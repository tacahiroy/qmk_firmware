/*
 * Copyright 2025 Takahiro YOSHIHARA <tacahiroy@gmail.com>
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
 */
#include QMK_KEYBOARD_H
#include "tacahiroy.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT_65_ansi_blocker(
        QK_GESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,   KC_DEL,
        KC_TAB,     KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,   KC_U,    KC_Y,    KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS,   KC_PGUP,
        KC_LCTL,    KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,   KC_E,    KC_I,    KC_O,    KC_QUOT,          KC_ENT,    KC_PGDN,
        SC_LSPO,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, SC_RSPC,          KC_UP,     MOUS,
        KC_LGUI,    KC_LALT, LOWER,                     RS_X(SPC),                         KC_RALT, KC_RCTL,          KC_LEFT, KC_DOWN,   KC_RGHT
    ),

    [_NORMAN] = LAYOUT_65_ansi_blocker(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______,
        _______, KC_Q,    KC_W,    KC_D,    KC_F,    KC_K,    KC_J,    KC_U,    KC_R,    KC_L,    KC_SCLN, _______, _______, _______,   _______,
        _______, KC_A,    KC_S,    KC_E,    KC_T,    KC_G,    KC_Y,    KC_N,    KC_I,    KC_O,    KC_H,    _______, _______,            _______,
        _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_P,    KC_M,    _______, _______, _______, _______,          _______,   _______,
        _______, _______, _______,                   _______,                            _______, _______,          _______, _______,   _______
    ),

    [_QWERTY] = LAYOUT_65_ansi_blocker(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______,
        _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______, _______, _______,   _______,
        _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______, _______,            _______,
        _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    _______, _______, _______, _______,          _______,   _______,
        _______, _______, _______,                   _______,                            _______, _______,          _______, _______,   _______
    ),

    [_LOWER] = LAYOUT_65_ansi_blocker(
        KC_GRV,  _______, _______, _______, _______, _______, _______, C_LEFT,  C_RIGHT, _______, _______, _______, _______, _______,   KC_MPLY,
        W_WLST,  XX_WIN,  XX_TAB,  KC_MEH,  KC_CAPS, _______, SK_KANA, TM_PREV, TM_WLST, TM_NEXT, KC_PIPE, _______, CW_TOGG, _______,   KC_VOLU,
        _______, KC_MPLY, MOUS,    W_SNIP,  KC_F5,   KC_F3,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, TM_SSH,  _______, _______,            KC_VOLD,
        _______, _______, CUT,     COPY2,   PASTE2,  TOP,     BOTTOM,  KC_HOME, KC_END,  _______, _______, _______,          TOP,       _______,
        _______, _______, _______,                   JP_HENK,                            _______, _______,          _______, BOTTOM,    _______
    ),

    [_RAISE] = LAYOUT_65_ansi_blocker(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XX_WIN,    KC_F13,
        _______, A(KC_1), A(KC_2), A(KC_3), A(KC_4), A(KC_9), KC_CIRC, KC_AMPR, KC_ASTR, FX_NEXT, _______, _______, _______, _______,   _______,
        _______, _______, KC_EQL,  KC_PLUS, KC_LPRN, KC_LBRC, KC_RBRC, KC_RPRN, KC_DEL,  KC_BSLS, _______, _______, _______,            _______,
        _______, _______, CUT,     COPY2,   PASTE2,  KC_LCBR, KC_RCBR, KC_PGUP, KC_PGDN, _______, _______, _______,          _______,   QK_BOOT,
        _______, _______, _______,                   _______,                            _______, _______,          _______, _______,   _______
    ),

    [_MOUS] = LAYOUT_65_ansi_blocker(
        QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MNXT, _______,   _______,
        _______, _______, _______, _______, _______, _______, _______, KC_BTN1, _______, KC_BTN2, _______, KC_VOLD, KC_VOLU, KC_MPLY,   _______,
        _______, CADEL,   _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______, _______,            _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,   _______,
        _______, _______, _______,                   _______,                            _______, _______,          _______, _______,   _______
        ),

    [_ADJUST] = LAYOUT_65_ansi_blocker(
        QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_SYRQ, KC_SCRL, KC_BRK,    _______,
        _______, QWERTY,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______,
        _______, CADEL,   _______, _______, _______, DB_TOGG, _______, NORMAN,  _______, _______, _______, _______, _______,            _______,
        _______, _______, _______, COLEMAK, VERSION, _______, _______, _______, _______, _______, _______, _______,          _______,   _______,
        _______, _______, _______,                   _______,                            _______, _______,          _______, _______,   _______
    ),
};
