#!/bin/bash

set -Cueo pipefail

if [ $# -lt 1 ]; then
    echo "Usage: $0 KEYBOARD KEYMAP"
    exit 1
fi

km="tacahiroy${2:-}"

case "$1" in
    b|bw|boardwalk)
        kb=boardwalk
        ;;
    pr|preonic)
        kb=preonic/rev3
        ;;
    pl|planck)
        kb=planck/rev4
        ;;
    au|arisu)
        kb=arisu
        ;;
    a|at|atlas)
        kb=cannonkeys/atlas
        ;;
    aa|ata|atlas_alps)
        kb=cannonkeys/atlas_alps
        ;;
    *)
        kb=$1
        ;;
esac

echo "Compling a QMK firmware: board:${kb} map:${km}"

poetry run qmk compile -kb "${kb}" -km "${km}"
