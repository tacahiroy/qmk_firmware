/**
 * Quantum Keyboard firmware configuration for Infinity Ergodox.
 * This is based on ergodox/default configuration.
 *
 * Copyright 2018 Takahiro Yoshihara <tacahiroy@gmail.com>
 *
 */

#include QMK_KEYBOARD_H
#include "tacahiroy.h"
#include "action_layer.h"
#include "version.h"

enum ergodox_layers {
    _CLMK,
    _QWTY,
    _MOVE,
    _MDIA,
    _MOUS,
    _SPCL
};

enum custom_keycodes {
    CLMK = SAFE_RANGE,
    QWTY,
    MOVE,
    MDIA,
    MOUS,
    SPCL,
    EPRM,
    VRSN,
    RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * Keymap 0: Colemak = Basic layer
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[_CLMK] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_GRV,    KC_1,      KC_2,    KC_3,    KC_4,      KC_5,     KC_DEL,
        KC_TAB,    KC_Q,      KC_W,    KC_F,    KC_P,      KC_G,     KC_HOME,
        KC_LCTL,   KC_A,      KC_R,    KC_S,    KC_T,      KC_D,
        KC_LSFT,   MOV_X(Z),  KC_X,    KC_C,    KC_V,      KC_B,     KC_LBRC,
        MO(_MOVE), MO(_MOUS), KC_LGUI, KC_LALT, MO(_MDIA),
                                                           KC_LEFT,  KC_RIGHT,
                                                                     TDSACA,
                                                KC_ESC,    KC_SPC,   TDKPP,

        // right hand
        KC_EQL,  KC_6,  KC_7,   KC_8,    KC_9,      KC_0,      KC_MINS,
        KC_END,  KC_J,  KC_L,   KC_U,    KC_Y,      KC_SCLN,   KC_BSLS,
                 KC_H,  KC_N,   KC_E,    KC_I,      KC_O,      KC_QUOT,
        KC_RBRC, KC_K,  KC_M,   KC_COMM, KC_DOT,    KC_SLSH,   KC_RSFT,
                        KC_SPC, KC_BSPC, MO(_MDIA), MO(_MOVE), KC_RCTL,

        KC_DOWN, KC_UP,
        KC_INS,
        KC_RGUI, KC_RALT, MEH_X(ENT)
),

/*
 * QWERTY
 */
[_QWTY] = LAYOUT_ergodox(
    // left hand
    _______, _______,  _______, _______, _______, _______, _______,
    _______, KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    _______,
    _______, KC_A,     KC_S,    KC_D,    KC_F,    KC_G,
    _______, MOV_X(Z), KC_X,    KC_C,    KC_V,    KC_B,    _______,
    _______, _______,  _______, _______, _______,
                                                  _______, _______,
                                                           _______,
                                         _______, _______, _______,

    // right hand
    _______, _______, _______, _______,  _______, _______, _______,
    _______, KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,    _______,
             KC_H,    KC_J,    KC_K,     KC_L,    KC_SCLN, _______,
    _______, KC_N,    KC_M,    KC_COMM,  KC_DOT,  KC_SLSH, _______,
                      _______, _______,  _______, _______, _______,
    _______, _______,
    _______,
    _______, _______, _______
),

/*
 * Move layer
 */
[_MOVE] = LAYOUT_ergodox(
       // left hand
       _______, KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F11,
       MC_EXPS, W_QUIT,   _______,  KC_END,   _______,  _______,  _______,
       _______, KC_HOME,  _______,  KC_DEL,   KC_PGDN,  _______,
       _______, _______,  _______,  COPY,     PASTE2,   KC_PGUP,  _______,
       _______, _______,  _______,  _______,  _______,
                                                        _______,  _______,
                                                                  _______,
                                              KC_F5,    _______,  _______,

       // right hand
       KC_F12,   KC_F6,    KC_F7,    KC_F8,    KC_F9,     KC_F10,   _______,
       _______,  _______,  TM_PREV,  TM_NEW,   TM_NEXT,   _______,  _______,
                 KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT,  TM_SSH,   _______,
       _______,  _______,  _______,  _______,  _______,   _______,  _______,
                           _______,  KC_DEL,   _______,   _______,  _______,
       _______,  _______,
       _______,
       KC_F4,    KC_F3,    KC_F2
),

/*
 * Media, not only media though :|
 */
[_MDIA] = LAYOUT_ergodox(
       // left hand
       _______,  _______,  _______,  _______,  _______,  _______,  _______,
       MC_EXPS,  _______,  _______,  _______,  VMW_REL,  _______,  _______,
       _______,  _______,  _______,  _______,  _______,  _______,
       _______,  _______,  W_QUIT,   _______,  _______,  _______,  _______,
       _______,  _______,  _______,  _______,  _______,
                                                         _______,  _______,
                                                                   _______,
                                               _______,  _______,  MO(_SPCL),

       // right hand
       _______,  _______,  _______,  _______,  _______,  _______,  KC_MPLY,
       _______,  _______,  KC_LBRC,  _______,  KC_RBRC,  _______,  KC_VOLU,
                 _______,  KC_LPRN,  _______,  KC_RPRN,  _______,  KC_VOLD,
       _______,  _______,  KC_LCBR,  _______,  KC_RCBR,  _______,  _______,
                           KC_MHEN,  _______,  _______,  _______,  VMW_REL,
       _______,  _______,
       _______,
       MO(_SPCL), _______, KC_HENK
),

/*
 * Mouse keys
 */
[_MOUS] = LAYOUT_ergodox(
       // left hand
       _______,  _______,  _______,  _______,  _______,  _______,  _______,
       _______,  _______,  _______,  _______,  _______,  _______,  _______,
       _______,  _______,  _______,  _______,  KC_BTN1,  _______,
       _______,  _______,  _______,  _______,  _______,  _______,  _______,
       _______,  _______,  _______,  _______,  _______,
                                                         _______,  _______,
                                                                   _______,
                                               _______,  _______,  _______,

       // right hand
       _______,  _______,  _______,  _______,  _______,  _______,  _______,
       _______,  _______,  KC_WH_U,  _______,  KC_WH_D,  _______,  _______,
                 KC_MS_L,  KC_MS_D,  KC_MS_U,  KC_MS_R,  _______,  _______,
       _______,  _______,  KC_BTN1,  _______,  KC_BTN2,  _______,  _______,
                           _______,  _______,  _______,  _______,  _______,
       _______,  _______,
       _______,
       _______,  _______, _______
),

/*
 * Special layer
 */
[_SPCL] = LAYOUT_ergodox(
       // left hand
       VRSN,     _______,  _______,  _______,  _______,  _______,  EPRM,
       _______,  _______,  _______,  _______,  _______,  _______,  _______,
       _______,  _______,  _______,  CLMK,     QWTY,     _______,
       _______,  _______,  _______,  _______,  _______,  _______,  _______,
       _______,  _______,  _______,  _______,  _______,
                                                         _______,  RESET,
                                                                   _______,
                                               _______,  _______,  _______,

       // right hand
       EPRM,     _______,  _______,  _______,  _______,  _______,  VRSN,
       _______,  _______,  _______,  _______,  _______,  _______,  _______,
                 _______,  QWTY,     CLMK,     _______,  _______,  _______,
       _______,  _______,  _______,  _______,  _______,  _______,  _______,
                 _______,  _______,  _______,  _______,  _______,
       RESET,    _______,
       _______,
       _______,  _______,  _______
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(_MOVE),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // dynamically generate these.
        case CLMK:
            if (record->event.pressed) {
                print("mode just switched to Colemak\n");
                set_single_persistent_default_layer(_CLMK);
            }
            break;
        case QWTY:
            if (record->event.pressed) {
                print("mode just switched to Qwerty\n");
                set_single_persistent_default_layer(_QWTY);
            }
            break;
        case EPRM:
            if (record->event.pressed) {
                eeconfig_init();
            }
            return false;
            break;
        case VRSN:
            if (record->event.pressed) {
                SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            }
            return false;
            break;
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
};
