/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Copyright 2017-2021 Takahiro Yoshihara <tacahiroy@gmail.com>
 * This file was based on default/keymap.c.
 */

#include QMK_KEYBOARD_H
#include "planck.h"
#include "tacahiroy.h"

#define PLANCK_YES // This is the Planck

extern keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_COLEMAK] = { /* Colemak */
  {KC_TAB,     KC_Q,     KC_W,    KC_F,    KC_P,  KC_G,   KC_J,   KC_L,  KC_U,    KC_Y,    KC_SCLN, KC_MINS},
  {CTL_X(ESC), KC_A,     KC_R,    KC_S,    KC_T,  KC_D,   KC_H,   KC_N,  KC_E,    KC_I,    KC_O,    KC_ENT},
  {KC_LSFT,    MV_X(Z), KC_X,    KC_C,    KC_V,  KC_B,   KC_K,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT},
  {MOVE,       MOUS,     KC_LGUI, KC_LALT, LOWER, KC_SPC, KC_SPC, RAISE, KC_BSPC, KC_QUOT, KC_RCTL, KC_MEH}
},

[_QWERTY] = { /* Qwerty */
  {_______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______},
  {_______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______},
  {_______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

[_LOWER] = { /* Lower */
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PIPE},
  {_______, W_IME,   _______, _______, MOUS,    _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, TM_SSH,  _______},
  {_______, XX_WIN,  _______, _______, _______, TOP,     BOTTOM,  KC_HOME, KC_END,  _______, TM_LASS, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

[_RAISE] = { /* Raise */
  {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, FX_NEXT, _______, XX_WIN},
  {_______, KC_ASTR, KC_EQL,  KC_PLUS, KC_LPRN, KC_LBRC, KC_RBRC, KC_RPRN, KC_DEL,  KC_BSLS, MOVE,    _______},
  {_______, KC_ESC,  CUT,     COPY2,   PASTE2,  KC_LCBR, KC_RCBR, KC_PGUP, KC_PGDN, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

[_MOVE] = { /* Move */
  {M_EXPS,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   V_ALTB,  TM_PREV, TM_PWIN, TM_NEXT, _______, _______},
  {_______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, _______, _______, _______, TM_SSH,  _______},
  {_______, _______, _______, _______, KC_F11,  KC_F12,  _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

[_MOUS] = { /* Mouse */
  {RESET,    _______, _______, _______,  _______, _______, _______, _______, _______, KC_MUTE, KC_MSTP, KC_MPLY},
  {_______,  RGB_TOG, RGB_MOD, RGB_RMOD, RGB_M_B, RGB_M_K, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_VOLD, KC_VOLU},
  {_______,  RGB_HUI, RGB_SAI, RGB_VAI,  RGB_M_R, RGB_M_X, _______, KC_BTN1, _______, KC_BTN2, KC_MPRV, KC_MNXT},
  {_______,  _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______}
},

[_ADJUST] = { /* Adjust (Lower + Raise) */
  {RESET,   _______, EPRM,    _______, _______, _______, _______, _______, _______,  _______, _______, _______},
  {_______, CADEL,   _______, _______, _______, DEBUG,   _______, _______, _______,  _______, _______, _______},
  {_______, _______, _______, _______, VERSION, _______, _______, QWERTY,  COLEMAK,  _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______}
}
};
