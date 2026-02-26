/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

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

Copyright 2022-2026 Takahiro YOSHIHARA <tacahiroy@gmail.com>
This file is based on cannonkeys/tmov2/keymaps/default/keymap.c@bbc3bc55
*/
#include QMK_KEYBOARD_H

#include "tacahiroy.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_COLEMAK] = LAYOUT_default(
        QK_GESC,     KC_TAB,    KC_Q,     KC_W,  KC_F,   KC_P,  KC_G,  KC_J,  KC_L,   KC_U,  KC_Y,     KC_SCLN,  KC_MINS,  KC_EQL,   KC_BSPC,
        KC_PGUP,     CTLX(ESC), KC_A,     KC_R,  KC_S,   KC_T,  KC_D,  KC_H,  KC_N,   KC_E,  KC_I,     KC_O,     KC_QUOT,  KC_ENT,
        KC_PGDN,     SC_LSPO,   XXXXXXX,  KC_Z,  KC_X,   KC_C,  KC_V,  KC_B,  KC_K,   KC_M,  KC_COMM,  KC_DOT,   KC_SLSH,  SC_RSPC,  SYSTEM,
        SY_X(MPLY),  KC_LGUI,   KC_LALT,         LOWER,                RS_X(SPC),            KC_RALT,            KC_RCTL
    ),

	[_NORMAN] = LAYOUT_default(
        _______,  _______,  KC_Q,     KC_W,  KC_D,    KC_F,  KC_K,  KC_J,    KC_U,  KC_R,  KC_L,     KC_SCLN,  _______,  _______,  _______,
        _______,  _______,  KC_A,     KC_S,  KC_E,    KC_T,  KC_G,  KC_Y,    KC_N,  KC_I,  KC_O,     KC_H,     _______,  _______,
        _______,  _______,  XXXXXXX,  KC_Z,  KC_X,    KC_C,  KC_V,  KC_B,    KC_P,  KC_M,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,         _______,               _______,               _______,            _______
    ),

	[_QWERTY] = LAYOUT_default(
        _______,  _______,  KC_Q,     KC_W,  KC_E,    KC_R,  KC_T,  KC_Y,    KC_U,  KC_I,  KC_O,     KC_P,     _______,  _______,  _______,
        _______,  _______,  KC_A,     KC_S,  KC_D,    KC_F,  KC_G,  KC_H,    KC_J,  KC_K,  KC_L,     KC_SCLN,  _______,  _______,
        _______,  _______,  XXXXXXX,  KC_Z,  KC_X,    KC_C,  KC_V,  KC_B,    KC_K,  KC_M,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,         _______,               _______,               _______,            _______
    ),

	[_LOWER] = LAYOUT_default(
        W_IME,    KC_GRV,   KC_1,     KC_2,     KC_3,    KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_PIPE,  TM_WLST,  KC_TILD,
		_______,  KC_CAPS,  SYSTEM,   XX_TAB,   W_SNIP,  KC_F5,    KC_F3,    KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  TM_SSH,   JP_MHEN,  _______,
        _______,  _______,  XXXXXXX,  _______,  CUT,     COPY2,    PASTE2,   TOP,      BOTTOM,   KC_HOME,  KC_END,   _______,  TM_SLST,  _______,  XXXXXXX,
        _______,  _______,  _______,            _______,                     JP_HENK,                      _______,            _______
    ),

	[_RAISE] = LAYOUT_default(
        KC_MPLY,  AHK_ATB,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_AMPR,  KC_ASTR,  FX_NEXT,  V_ALTB,   TM_PREV,  TM_NEXT,  XX_WIN,
        KC_VOLU,  KC_ESC,   AHK_MOB,  KC_EQL,   KC_PLUS,  KC_LPRN,  KC_LBRC,  KC_RBRC,  KC_RPRN,  KC_DEL,   KC_BSLS,  _______,  _______,  _______,
        KC_VOLD,  _______,  XXXXXXX,  AHK_ZOM,  CUT,      COPY2,    PASTE2,   KC_LCBR,  KC_RCBR,  KC_PGUP,  KC_PGDN,  _______,  _______,  _______,  XXXXXXX,
        _______,            _______,  _______,            _______,            _______,                      _______,            _______
    ),

	[_SYSTEM] = LAYOUT_default(
        _______,  _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    _______,  MS_BTN1,  _______,  MS_BTN2,  _______,  _______,  _______,  QK_BOOT,
        _______,  _______,  KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   MS_LEFT,  MS_DOWN,  MS_UP,    MS_RGHT,  _______,  _______,  _______,
        _______,  _______,  XXXXXXX,  _______,  _______,  KC_F11,   KC_F12,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,            _______,  _______,            _______,            _______,                      _______,            _______
    ),

	[_ADJUST] = LAYOUT_default(
        QK_BOOT,  _______,  QWERTY,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_SYRQ,  KC_SCRL,  KC_BRK,
        EPRM,     _______,  CADEL,    _______,  _______,  _______,  DB_TOGG,  _______,  NORMAN,   _______,  _______,  _______,  _______,  _______,
        _______,  _______,  XXXXXXX,  _______,  _______,  COLEMAK,  VERSION,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  XXXXXXX,
        _______,            _______,  _______,            _______,            _______,                      _______,            _______
    ),
};
