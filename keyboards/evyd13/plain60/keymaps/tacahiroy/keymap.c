/*
 * Copyright 2022 Takahiro Yoshihara
 * This is based on evyd13/plain60/keymaps/default/keymap.c
 */
#include QMK_KEYBOARD_H
#include "tacahiroy.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK] = LAYOUT(
    KC_GRV,     KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_DEL,  KC_BSPC,
    KC_TAB,     KC_Q,    KC_W,   KC_F,   KC_P,   KC_G,   KC_J,   KC_L,   KC_U,   KC_Y,    KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS,
    CTL_X(ESC), KC_A,    KC_R,   KC_S,   KC_T,   KC_D,   KC_H,   KC_N,   KC_E,   KC_I,    KC_O,    KC_QUOT, XXXXXXX, KC_ENT,
    KC_LSFT,    XXXXXXX, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_K,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_RGUI,
    XXXXXXX,    KC_LALT, LOWER,                      RS_X(SPC),                           XXXXXXX, RAISE,   KC_RCTL, XXXXXXX

  ),

  [_QWERTY] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______, _______, _______,
    _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______, XXXXXXX, _______,
    _______, XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    _______, _______, _______, _______, _______,
    XXXXXXX, _______, _______,                       _______,                                 XXXXXXX, _______, _______, XXXXXXX
  ),

  [_LOWER] = LAYOUT(
    W_IME,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_MSTP, KC_MPLY,
    M_EXPS,  XX_WIN,  XX_TAB,  KC_MS_U, W_SSHOT, KC_BTN1, KC_BTN2, TM_PREV, KC_BSPC, TM_NEXT, KC_PIPE, _______, KC_VOLD, KC_VOLU,
    _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, MOUS,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, TM_SSH,  _______, XXXXXXX, _______,
    _______, XXXXXXX, _______, CUT,     COPY2,   PASTE,   TOP,     BOTTOM,  KC_HOME, KC_END,  _______, TM_LSTS, _______, _______,
    XXXXXXX, _______, _______,                       M_HENK,                                  XXXXXXX, _______, _______, XXXXXXX
  ),

  [_RAISE] = LAYOUT(
    RESET,   _______, _______, _______, _______, _______, WS_LEFT, WS_RGHT, _______, _______, _______, _______, _______, _______, XX_WIN,
    W_S_WIN, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, FX_NEXT, _______, _______, _______, RAL_RCT,
    _______, KC_MINS, KC_EQL,  KC_PLUS, KC_LPRN, KC_LBRC, KC_RBRC, KC_RPRN, KC_DEL,  KC_BSLS, _______, _______, XXXXXXX, _______,
    _______, XXXXXXX, KC_UNDS, CUT,     COPY2,   PASTE2,  KC_LCBR, KC_RCBR, KC_PGUP, KC_PGDN, _______, _______, _______, _______,
    XXXXXXX, _______, _______,                       _______,                                 XXXXXXX, _______, _______, XXXXXXX
  ),

  [_MOUS] = LAYOUT(
    RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_MSTP, KC_MPLY,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, _______,
    _______, XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    XXXXXXX, _______, _______,                       _______,                                 XXXXXXX, _______, _______, XXXXXXX
  ),

  [_ADJUST] = LAYOUT(
    RESET,   _______, EPRM,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, CADEL,   _______, _______, _______, DEBUG,   _______, _______, _______, _______, _______, _______, XXXXXXX, _______,
    _______, XXXXXXX, _______, _______, _______, VERSION, _______, _______, QWERTY,  COLEMAK, _______, _______, _______, _______,
    XXXXXXX, _______, _______,                       _______,                                 XXXXXXX, _______, _______, XXXXXXX
  )
};
