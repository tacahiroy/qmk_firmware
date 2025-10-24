/* 
Copyright 2021 Alexander Lee <chlx.bsmt@gmail.com> 

This program is free software: you can redistribute it and/or modify 
it under the terms of the GNU General Public License as published by 
the Free Software Foundation, either version 2 of the License, or 
(at your option) any later version. 

This program is distributed in the hope that it will be useful, 
but WITHOUT ANY WARRANTY; without even the implied warranty of 
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
GNU General Public License for more details. 

You should have received a copy of the GNU General Public License 
along with this program.  If not, see <http://www.gnu.org/licenses/>. 

Copyright 2024-2025 YOSHIHARA Takahiro <tacahiroy@gmail.com>
This is based on merro60/keymaps/iso/keymap.c
*/ 

#include QMK_KEYBOARD_H
#include "tacahiroy.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK] = LAYOUT_iso_tsangan(
    QK_GESC,  KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,     KC_0,    KC_MINS, KC_EQL,  KC_BSPC,  KC_BSPC,
    KC_TAB,   KC_Q,    KC_W,   KC_F,   KC_P,   KC_G,   KC_J,   KC_L,   KC_U,   KC_Y,     KC_SCLN, KC_LBRC, KC_RBRC,
    KC_LCTL,  KC_A,    KC_R,   KC_S,   KC_T,   KC_D,   KC_H,   KC_N,   KC_E,   KC_I,     KC_O,    KC_QUOT, KC_GRV,  KC_ENT,
    SC_LSPO,  KC_NUBS, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_K,   KC_M,   KC_COMM,  KC_DOT,  KC_SLSH, SC_RSPC, KC_PGDN,
    KC_LGUI,  KC_LALT, LOWER,                                          RS_X(SPC),                 KC_RCTL, KC_RALT, KC_RGUI
  ),

  [_NORMAN] = LAYOUT_iso_tsangan(
    _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, KC_Q,     KC_W,    KC_D,    KC_F,    KC_K,    KC_J,    KC_U,    KC_R,    KC_L,    KC_SCLN, _______, _______,
    _______, KC_A,     KC_S,    KC_E,    KC_T,    KC_G,    KC_Y,    KC_N,    KC_I,    KC_O,    KC_H,    _______, _______, _______,
    _______, _______,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_P,    KC_M,    _______, _______, _______, _______, _______,
    _______, _______, _______,                                               _______,                   _______, _______, _______
  ),

  [_HHKB] = LAYOUT_iso_tsangan(
    QK_GESC,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, KC_BSLS, KC_BSPC,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_GRV,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,
    _______,  _______,  _______,                                          _______,                                _______,  _______, _______
  ),

  [_QWERTY] = LAYOUT_iso_tsangan(
    _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______, _______,
    _______, KC_A,     KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______, _______, _______,
    _______, _______,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    _______, _______, _______, _______, _______,
    _______, _______, _______,                                               _______,                   _______, _______, _______
  ),

  [_LOWER] = LAYOUT_iso_tsangan(
    KC_GRV,  _______, _______, _______, _______, _______, _______, C_LEFT,  C_RIGHT, _______, _______, _______, _______,  _______, _______,
    W_WLST,  _______, XX_TAB,  KC_MEH,  KC_CAPS, _______, SK_KANA, TM_PREV, TM_WLST, TM_NEXT, KC_PIPE, _______, CW_TOGG,
    _______, KC_MPLY, MOUS,    W_SNIP,  KC_F5,   KC_F3,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, TM_SSH,  KC_MINS, _______,  _______,
    _______, _______, _______, CUT,     COPY2,   PASTE2,  TOP,     BOTTOM,  KC_HOME, KC_END,  _______, _______, _______,  KC_PGUP,
    _______, _______, _______,                                     JP_HENK,                            _______, _______,  _______ 
  ),

  [_RAISE] = LAYOUT_iso_tsangan(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_F13, XX_WIN,
    AHK_ATB, AHK_MOB, _______, _______, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, FX_NEXT, _______, _______, _______,
    _______, KC_UNDS, KC_EQL,  KC_PLUS, KC_LPRN, KC_LBRC, KC_RBRC, KC_RPRN, KC_DEL,  KC_BSLS, _______, _______, _______, _______,
    _______, _______, AHK_ZOM, CUT,     COPY2,   PASTE2,  KC_LCBR, KC_RCBR, KC_PGUP, KC_PGDN, _______, _______, _______, QK_BOOT,
    _______, _______, _______,                                     _______,                            _______, _______, _______
  ),

  [_MOUS] = LAYOUT_iso_tsangan(
    QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MNXT,  KC_MPLY,
    _______, _______, _______, _______, _______, _______, _______, MS_BTN1, _______, MS_BTN2, _______, KC_VOLD, KC_VOLU,
    _______, _______, _______, _______, _______, _______, MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______,                   _______,                            _______, _______, _______
  ),

  [_ADJUST] = LAYOUT_iso_tsangan(
    QK_BOOT, _______, EPRM,    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_SYRQ, KC_SCRL, KC_BRK,
    _______, QWERTY,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, CADEL,   _______, AC_TOGG, _______, DB_TOGG, HHKB,    NORMAN,  _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, COLEMAK, VERSION, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______,                            _______,                   _______, _______, _______ 
  )
};
