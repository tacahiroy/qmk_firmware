#!/bin/bash

set -Cueo pipefail

list-boards() {
    printf "%-18s\t%-20s\n" 'a|at|atlas'         'cannonkeys/atlas'
    printf "%-18s\t%-20s\n" 'aa|ata|atlas_alps'  'cannonkeys/atlas_alps'
    printf "%-18s\t%-20s\n" 'ar'                 'arisu'
    printf "%-18s\t%-20s\n" 'b|bw'               'boardwalk'
    printf "%-18s\t%-20s\n" 'pa|palice'          'projectkb/alice/rev2'
    printf "%-18s\t%-20s\n" 'pl|planck'          'planck/rev4'
    printf "%-18s\t%-20s\n" 'pr|preonic'         'preonic/rev3'
    printf "%-18s\t%-20s\n" 'l|lj'               'peej/lumberjack'
    printf "%-18s\t%-20s\n" 'p60|plain60'        'evyd13/plain60'
    printf "%-18s\t%-20s\n" 'pi65|pizza65'       'pizzakeyboards/pizza65'
    printf "%-18s\t%-20s\n" 't|tmov2'            'cannonkeys/tmov2'
    printf "%-18s\t%-20s\n" 'y|yeti'             'axolstudio/yeti/soldered'
}

if [ $# -lt 1 ]; then
    echo "Usage: $0 KEYBOARD KEYMAP"
    list-boards
    exit 1
fi

km="tacahiroy${2:-}"

case "$1" in
    a|at|atlas)
        kb=cannonkeys/atlas
        ;;
    aa|ata|atlas_alps)
        kb=cannonkeys/atlas_alps
        ;;
    ar|arisu)
        kb=arisu
        ;;
    b|bw|boardwalk)
        kb=boardwalk
        ;;
    l|lj|lumberjack)
        kb=peej/lumberjack
        ;;
    p60|plain60)
        kb=evyd13/plain60
        ;;
    pa|palice|projectkb/alice)
        kb=projectkb/alice/rev2
        ;;
    sl|slice65*)
        kb=pizzakeyboards/slice65
        ;;
    pl|planck)
        kb=planck/rev4
        ;;
    pr|preonic)
        kb=preonic/rev3
        ;;
    t|tmo*)
        kb=cannonkeys/tmov2
        ;;
    y|yeti)
        kb=axolstudio/yeti/soldered
        ;;
    *)
        kb=$1
        ;;
esac

echo "Compling a QMK firmware: board:${kb} map:${km}"

poetry run qmk compile -kb "${kb}" -km "${km}"
