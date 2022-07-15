#!/bin/bash

set -Cueo pipefail

list-boards() {
    printf "%-18s\t%-20s\n" 'a|at|atlas'         'cannonkeys/atlas'
    printf "%-18s\t%-20s\n" 'aa|ata|atlas_alps'  'cannonkeys/atlas_alps'
    printf "%-18s\t%-20s\n" 'ar'                 'arisu'
    printf "%-18s\t%-20s\n" 'b|bw'               'boardwalk'
    printf "%-18s\t%-20s\n" 'pa|palice'          'projectkb/alice/rev2'
    printf "%-18s\t%-20s\n" 'pl'                 'planck/rev4'
    printf "%-18s\t%-20s\n" 'pr'                 'preonic/rev3'
    printf "%-18s\t%-20s\n" 'l|lj'               'peej/lumberjack'
}

if [ $# -lt 1 ]; then
    echo "Usage: $0 KEYBOARD KEYMAP"
    list-boards
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
    ar|arisu)
        kb=arisu
        ;;
    pa|palice|projectkb/alice)
        kb=projectkb/alice/rev2
        ;;
    a|at|atlas)
        kb=cannonkeys/atlas
        ;;
    aa|ata|atlas_alps)
        kb=cannonkeys/atlas_alps
        ;;
    l|lj|lumberjack)
        kb=peej/lumberjack
        ;;
    plain|plain60)
        kb=evyd13/plain60
        ;;
    *)
        kb=$1
        ;;
esac

echo "Compling a QMK firmware: board:${kb} map:${km}"

poetry run qmk compile -kb "${kb}" -km "${km}"
