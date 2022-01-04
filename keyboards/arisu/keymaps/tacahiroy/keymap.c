/* Copyright 2019 Fate
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
 * Copyright 2021 Takahiro Yoshihara <tacahiroy@gmail[dot]com>
 */
#include QMK_KEYBOARD_H
#include "tacahiroy.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK] = LAYOUT(
    KC_GRV,     KC_1,  KC_2,     KC_3,    KC_4,    KC_5,  KC_EQL,    KC_6,       KC_7,   KC_8,     KC_9,    KC_0,     KC_MINS,      KC_DEL,   KC_BSLS,  KC_PGUP,
    KC_TAB,     KC_Q,  KC_W,     KC_F,    KC_P,    KC_G,             KC_J,       KC_L,   KC_U,     KC_Y,    KC_SCLN,  KC_LBRC,      KC_RBRC,  KC_BSPC,  KC_PGDN,
    CTL_X(ESC), KC_A,  KC_R,     KC_S,    KC_T,    KC_D,             KC_H,       KC_N,   KC_E,     KC_I,    KC_O,     KC_QUOT,      KC_ENT,             KC_ESC,
    KC_LSFT,    KC_Z,  KC_X,     KC_C,    KC_V,    KC_B,             KC_N,       KC_M,   KC_COMM,  KC_DOT,  KC_SLSH,  KC_RSFT,      KC_UP,
    MOUS,              KC_LALT,           LOWER,   KC_LGUI,          RS_X(SPC),  RAISE,                               CTL_X(LEFT),  KC_DOWN,  KC_RGHT
  ),

  [_QWERTY] = LAYOUT(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  KC_Q,     KC_W,     KC_F,     KC_P,     KC_G,               KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN,  _______,  _______,  _______,  _______,
    _______,  KC_A,     KC_R,     KC_S,     KC_T,     KC_D,               KC_H,     KC_N,     KC_E,     KC_I,     KC_O,     _______,  _______,            _______,
    _______,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,               KC_N,     KC_M,     _______,  _______,  _______,  _______,  _______,
    _______,            _______,            _______,  _______,            _______,  _______,                                _______,  _______,  _______
  ),

  [_LOWER] = LAYOUT(
    W_IME,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,  KC_F12,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   _______,  _______,  _______,
    MC_EXPS,  _______,  _______,  _______,  _______,  _______,           V_ALTB,   TM_PREV,  KC_BSPC,  TM_NEXT,  KC_PIPE,  _______,  _______,  KC_PIPE,  _______,
    KC_CAPS,  _______,  _______,  W_SSHOT,  MOUS,     _______,           KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  TM_SSH,   _______,  _______,            _______,
    _______,  W_QUIT,   _______,  _______,  _______,  TOP,               BOTTOM,   KC_HOME,  KC_END,   _______,  TM_LSTS,  _______,  _______,
    _______,            _______,            _______,  _______,           _______,  _______,                                _______,  _______,  _______
  ),

  [_RAISE] = LAYOUT(
    VMW_REL,  _______,  _______,  _______,  _______,  _______,  _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  W_QUIT,  _______,
    W_S_WIN,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,           KC_CIRC,  KC_AMPR,  KC_ASTR,  FX_NEXT,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  KC_EQL,   KC_PLUS,  KC_LPRN,  KC_LBRC,           KC_RBRC,  KC_RPRN,  KC_DEL,   KC_BSLS,  _______,  _______,  _______,            _______,
    _______,  KC_UNDS,  CUT,      COPY2,    PASTE2,   KC_LCBR,           KC_RCBR,  KC_PGUP,  KC_PGDN,  _______,  _______,  _______,  _______,
    _______,            _______,            _______,  _______,           _______,  _______,                                _______,  _______,  _______
  ),

  [_MOUS] = LAYOUT(
    RESET,    _______,  _______,  _______,  _______,  _______,  _______, _______,  _______,  _______,  _______,  _______,  _______,  KC_MUTE,  KC_MSTP,  KC_MPLY,
    EPRM,     _______,  _______,  _______,  _______,  _______,           _______,  _______,  _______,  _______,  _______,  _______,  KC_MPRV,  KC_MNXT,  KC_VOLU,
    _______,  _______,  W_CADEL,  _______,  _______,  _______,           _______,  _______,  _______,  _______,  _______,  _______,  _______,            KC_VOLD,
    _______,  _______,  _______,  _______,  _______,  _______,           _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,            _______,            _______,  _______,           _______,  _______,                                _______,  _______,  _______
  )
};
