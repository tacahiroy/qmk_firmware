// Default layout for WT60-D
#include QMK_KEYBOARD_H
#include "tacahiroy.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// Default layer
[_COLEMAK] = LAYOUT_all(
    KC_GRV,      KC_1,     KC_2,     KC_3,    KC_4,     KC_5,     KC_6,   KC_7,      KC_8,  KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_BSPC,
    KC_TAB,      KC_Q,     KC_W,     KC_F,    KC_P,     KC_G,     KC_J,   KC_L,      KC_U,  KC_Y,     KC_SCLN,  KC_LBRC,  KC_RBRC,  KC_BSLS,
    CTL_X(ESC),  KC_A,     KC_R,     KC_S,    KC_T,     KC_D,     KC_H,   KC_N,      KC_E,  KC_I,     KC_O,     KC_QUOT,  KC_ENT,
    KC_LSFT,     KC_LSFT,  KC_Z,     KC_X,    KC_C,     KC_V,     KC_B,   KC_K,      KC_M,  KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_RSFT,
    KC_LGUI,     KC_LALT,  LOWER,                           RS_X(SPC),                                RAISE,    KC_RALT,  KC_RCTL,  MOUS),

[_QWERTY] = LAYOUT_all(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     _______,  _______,  _______,
    _______,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  _______,  _______,
    _______,  _______,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,                         _______,                                       _______,  _______,  _______,  _______),

[_LOWER] = LAYOUT_all(
    W_IME,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______, _______,
    MC_EXPS,  _______,  _______,  _______,  _______,  _______,  _______,  TM_PREV,  KC_BSPC,  TM_NEXT,  KC_PIPE,  _______,  _______,  KC_PIPE,
    _______,  _______,  _______,  W_SSHOT,  MOUS,     _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  TM_SSH,   _______,  _______,
    _______,  _______,  _______,  _______,  _______,  TOP,      _______,  BOTTOM,   KC_HOME,  KC_END,   _______,  TM_LSTS,  _______,  _______,
    _______,  _______,  _______,                            _______,                                    _______,  _______,  _______,  _______),

[_RAISE] = LAYOUT_all(
    _______,  _______,  _______,  _______,  _______,  _______,  W_LFT_D,  W_RGT_D,  _______,  _______,  _______,  _______,  _______,  W_QUIT,  W_QUIT,
    W_S_WIN,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_AMPR,  KC_ASTR,  FX_NEXT,  _______,  _______,  _______,  VMW_REL,
    _______,  KC_MINS,  KC_EQL,   KC_PLUS,  KC_LPRN,  KC_LBRC,  KC_RBRC,  KC_RPRN,  KC_DEL,   KC_BSLS,  _______,  _______,  _______,
    _______,  KC_UNDS,  CUT,      COPY2,    PASTE2,   KC_LCBR,  _______,  KC_RCBR,  KC_PGUP,  KC_PGDN,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,                             _______,                                   _______,  _______,  _______,  _______),

[_MOUS] = LAYOUT_all(
    RESET,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_MSTP,  KC_MPLY,  KC_MPLY,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_WH_U,  _______,  KC_WH_D,  _______,  KC_MUTE,  KC_VOLD,  KC_VOLU,
    _______,  _______,  _______,  _______,  _______,  _______,  KC_MS_L,  KC_MS_D,  KC_MS_U,  KC_MS_R,  KC_MPRV,  KC_MNXT,  _______,
    _______,  _______,  _______,  _______,  _______,  VERSION,  _______,  _______,  KC_BTN1,  KC_BTN2,  QWERTY,   COLEMAK,  _______,  _______,
    _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______),

[_ADJUST] = LAYOUT_all(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,                           _______,                                     _______,  _______,  _______,  _______),
};
