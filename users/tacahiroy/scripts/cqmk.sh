#!/bin/bash

set -Cueo pipefail

list-boards() {
    printf "%-18s\t%-20s\n" 'aa|ata|atlas_alps'    'cannonkeys/atlas_alps'
    printf "%-18s\t%-20s\n" 'a|at|atlas'           'cannonkeys/atlas'
    printf "%-18s\t%-20s\n" 'b60|bn60|bakeneko60'  'kkatano/bakeneko60'
    printf "%-18s\t%-20s\n" 'b|bw'                 'boardwalk'
    printf "%-18s\t%-20s\n" 'jp02|jp-02|ar|arisu'  'arisu'
    printf "%-18s\t%-20s\n" 'merr|merro60'         'chlx/merro60'
    printf "%-18s\t%-20s\n" 'pal|palmetto|h60'     'hineybush/h60'
    printf "%-18s\t%-20s\n" 'pa|palice'            'projectkb/alice/rev2'
    printf "%-18s\t%-20s\n" 'pi65k|kbd67r2'        'kbdfans/kbd67/rev2'
    printf "%-18s\t%-20s\n" 'pi65|pizza65'         'pizzakeyboards/pizza65'
    printf "%-18s\t%-20s\n" 'pl|planck'            'planck/rev4'
    printf "%-18s\t%-20s\n" 'pr|preonic'           'preonic/rev3'
    printf "%-18s\t%-20s\n" 't|tmov2'              'cannonkeys/tmov2'
    printf "%-18s\t%-20s\n" 'y|yeti'               'axolstudio/yeti/soldered'
    printf "%-18s\t%-20s\n" 'jd|jjwd|derivative|zed60'   'mechlovin/zed60'
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
    ar|arisu|jp02|jp-02)
        kb=arisu
        ;;
    b60|bn60|bakeneko60)
        kb=kkatano/bakeneko60
        ;;
    b|bw|boardwalk)
        kb=boardwalk
        ;;
    merr|merro60)
        kb=chlx/merro60
        ;;
    pal|palmetto|h60)
        kb=hineybush/h60
        ;;
    pa|palice|projectkb/alice)
        kb=projectkb/alice/rev2
        ;;
    pi65|pizza65)
        kb=pizzakeyboards/pizza65
        ;;
    pi65k|kbd67r2)
        kb=kbdfans/kbd67/rev2
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
    jd|jjwd|derivative|zed60)
        kb=mechlovin/zed60
        ;;
    *)
        kb=$1
        ;;
esac

echo "Compling a QMK firmware: board:${kb} map:${km}"

uv run qmk compile -kb "${kb}" -km "${km}"
