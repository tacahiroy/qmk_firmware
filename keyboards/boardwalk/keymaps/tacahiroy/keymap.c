/*
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
 */

#include QMK_KEYBOARD_H
#include "tacahiroy.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_COLEMAK] = LAYOUT_ortho_hhkb(
  KC_GRV,   KC_1,  KC_2,     KC_3,     KC_4,   KC_5,  KC_MINS,  KC_EQL,   KC_6,  KC_7,   KC_8,     KC_9,        KC_0,     KC_MINS, \
  KC_TAB,   KC_Q,  KC_W,     KC_F,     KC_P,   KC_G,  KC_HOME,  KC_END,   KC_J,  KC_L,   KC_U,     KC_Y,        KC_SCLN,  KC_QUOT, \
  KC_LCTL,  KC_A,  KC_R,     KC_S,     KC_T,   KC_D,  KC_DEL,   KC_BSPC,  KC_H,  KC_N,   KC_E,     KC_I,        KC_O,     KC_ENT,  \
  KC_LSFT,  KC_Z,  KC_X,     KC_C,     KC_V,   KC_B,  KC_PGUP,  KC_PGDN,  KC_K,  KC_M,   KC_COMM,  KC_DOT,      KC_SLSH,  KC_RSFT, \
            MOUS,  KC_LGUI,  KC_LALT,  LOWER,     KC_ESC,            KC_SPC,     RAISE,  KC_BSPC,  MEH_X(BSLS), KC_RCTL            \
 ),

 [_QWERTY] = LAYOUT_ortho_hhkb(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______, _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______, \
  _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______, _______, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______, \
  _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______, _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______, \
           _______, _______, _______, _______,    _______,            _______,     _______, _______, _______, _______           \
 ),

 [_LOWER] = LAYOUT_ortho_hhkb(
  MC_EXPS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,  KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_EQL,  \
  _______, _______, _______, W_IME,   _______, TOP,     _______, _______, V_ALTB,  TM_PREV, KC_BSPC, TM_NEXT, _______, KC_PIPE, \
  _______, _______, _______, W_SSHOT, MOUS,    _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, TM_SSH,  _______, \
  _______, W_QUIT,  _______, _______, _______, BOTTOM,  _______, _______, _______, KC_HOME, KC_END,  _______, TM_LSTS, _______, \
           _______, _______, _______, _______,    _______,           _______,      _______, _______, _______, _______           \
 ),

 [_RAISE] = LAYOUT_ortho_hhkb(
  W_S_WIN,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, W_QUIT,  \
  _______,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, FX_NEXT, _______, VMW_REL, \
  _______,  KC_MINS, KC_EQL,  KC_PLUS, KC_LPRN, KC_LBRC, _______, _______, KC_RBRC, KC_RPRN, KC_DEL,  KC_BSLS, _______, _______, \
  _______,  KC_UNDS, CUT,     COPY2,   PASTE2,  KC_LCBR, _______, _______, KC_RCBR, KC_PGUP, KC_PGDN, _______, _______, _______, \
            _______, _______, _______, _______,    _______,          _______,       _______, _______, _______, _______           \
 ),

 [_MOUS] = LAYOUT_ortho_hhkb(
  RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_MSTP, KC_MPLY, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_WH_U, _______, KC_WH_D, KC_VOLD, KC_VOLU, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_MPRV, KC_MNXT, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BTN1, _______, KC_BTN2, _______, _______, \
           _______, _______, _______, _______,    _______,          _______,       _______, _______, _______, _______           \
 ),

 [_ADJUST] = LAYOUT_ortho_hhkb(
  RESET,   _______, EPRM,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD,  _______, \
  _______, W_CADEL, _______, _______, _______, _______, _______, _______, _______, RGB_VAD, RGB_SAD, RGB_HUD, RGB_RMOD, _______, \
  _______, _______, _______, _______, VERSION, _______, _______, _______, _______, QWERTY,  COLEMAK, _______, RGB_TOG,  _______, \
           _______, _______, _______, _______,    _______,          _______,       _______, _______, _______, _______            \
 ),
};
