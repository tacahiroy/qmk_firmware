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

Copyright 2022-2024 Takahiro YOSHIHARA <tacahiroy@gmail.com>
This file is based on cannonkeys/tmov2/keymaps/default/keymap.c@bbc3bc55
*/
#include QMK_KEYBOARD_H

#include "tacahiroy.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_COLEMAK] = LAYOUT_default(
        QK_GESC,     KC_TAB,      KC_Q,     KC_W,  KC_F,   KC_P,  KC_G,  KC_J,  KC_L,       KC_U,  KC_Y,     KC_SCLN,  KC_MINS,  KC_EQL,   KC_BSPC,
        KC_PGUP,     CTL_X(ESC),  KC_A,     KC_R,  KC_S,   KC_T,  KC_D,  KC_H,  KC_N,       KC_E,  KC_I,     KC_O,     KC_QUOT,  KC_ENT,
        KC_PGDN,     KC_LSFT,     XXXXXXX,  KC_Z,  KC_X,   KC_C,  KC_V,  KC_B,  KC_K,       KC_M,  KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  XXXXXXX,
        MO_X(MPLY),  MOUS,        KC_LALT,         LOWER,                RS_X(SPC),                KC_LGUI,            KC_RCTL
    ),

	[_QWERTY] = LAYOUT_default(
        _______,  _______,  KC_Q,     KC_W,     KC_E,  KC_R,     KC_T,  KC_Y,  KC_U,     KC_I,  KC_O,     KC_P,     _______,  _______,  _______,
        _______,  _______,  KC_A,     KC_S,     KC_D,  KC_F,     KC_G,  KC_H,  KC_J,     KC_K,  KC_L,     KC_SCLN,  _______,  _______,
        _______,  _______,  XXXXXXX,  KC_Z,     KC_X,  KC_C,     KC_V,  KC_B,  KC_K,     KC_M,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,            _______,                _______,                _______,            _______
    ),

	[_LOWER] = LAYOUT_default(
        W_IME,    KC_GRV,   KC_1,     KC_2,     KC_3,    KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_PIPE,  TM_WLST,  KC_DEL,
		_______,  _______,  _______,  XX_TAB,   W_SNIP,  KC_F5,    KC_F3,    KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  TM_SSH,   TM_LASS,  _______,
        _______,  _______,  XXXXXXX,  _______,  CUT,     COPY2,    PASTE2,   TOP,      BOTTOM,   KC_HOME,  KC_END,   TM_SLST,  _______,  _______,  XXXXXXX,
        _______,  _______,  _______,            _______,                     JP_HENK,                      _______,            _______
    ),

	[_RAISE] = LAYOUT_default(
        KC_MPLY,  KC_TILD,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_AMPR,  KC_ASTR,  FX_NEXT,  V_ALTB,   TM_PREV,  TM_NEXT,  XX_WIN,
        KC_VOLU,  CW_TOGG,  KC_UNDS,  KC_EQL,   KC_PLUS,  KC_LPRN,  KC_LBRC,  KC_RBRC,  KC_RPRN,  KC_DEL,   KC_BSLS,  _______,  _______,  _______,
        KC_VOLD,  _______,  XXXXXXX,  _______,  CUT,      COPY2,    PASTE2,   KC_LCBR,  KC_RCBR,  KC_PGUP,  KC_PGDN,  _______,  _______,  _______,  XXXXXXX,
        _______,            _______,  _______,            _______,            _______,                      _______,            _______
    ),

	[_MOUS] = LAYOUT_default(
        QK_BOOT,  _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_MS_L,  KC_MS_D,  KC_MS_U,  KC_MS_R,  KC_BTN1,  KC_BTN2,  _______,
        _______,  _______,  XXXXXXX,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  XXXXXXX,
        _______,            _______,  _______,            _______,            _______,                      _______,            _______
    ),

	[_ADJUST] = LAYOUT_default(
        QK_BOOT,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        EPRM,     _______,  CADEL,    _______,  _______,  _______,  DB_TOGG,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  XXXXXXX,  _______,  _______,  _______,  VERSION,  _______,  _______,  QWERTY,   COLEMAK,  _______,  _______,  _______,  XXXXXXX,
        _______,            _______,  _______,            _______,            _______,                      _______,            _______
    ),
};


