#!/bin/bash

set -Cueo pipefail

cwd=$(dirname "$(realpath "$0")")

repo_root=$(git -C "${cwd}" rev-parse --show-toplevel)

while read -r keymap; do
    # shellcheck disable=SC2001
    kb=$(echo "${keymap}" | sed 's#^.\+/keyboards/\(.\+\)/keymaps/.\+#\1#')
    km=${keymap##*/keymaps/}
    echo "%%%%% Compiling ${kb} ${km} %%%%%"
    poetry run qmk compile -kb "${kb}" -km "${km}" || true
done < <(find "${repo_root}" -type d -path '*/keymaps/tacahiroy*')
