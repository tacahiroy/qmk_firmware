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
 * Copyright 2017-2019 Takahiro Yoshihara <tacahiroy@gmail.com>
 * This file was based on default/keymap.c.
 */

#include "planck.h"
#include "tacahiroy.h"
#include "version.h"

#define PLANCK_YES // This is the Planck

extern keymap_config_t keymap_config;


enum planck_layers {
  _COLEMAK,
  _QWERTY,
  _LOWER,
  _RAISE,
  _MOVE,
  _MOUS,
  _ADJUST
};

enum planck_keycodes {
  COLEMAK = SAFE_RANGE,
  QWERTY,
  LOWER,
  RAISE,
  MOVE,
  MOUS,
  ADJUST,
  VERSION,
  EPRM
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_COLEMAK] = { /* Colemak */
  {KC_TAB,     KC_Q,     KC_W,    KC_F,    KC_P,  KC_G,   KC_J,   KC_L,  KC_U,    KC_Y,    KC_SCLN, KC_MINS},
  {CTL_X(ESC), KC_A,     KC_R,    KC_S,    KC_T,  KC_D,   KC_H,   KC_N,  KC_E,    KC_I,    KC_O,    KC_ENT},
  {KC_LSFT,    MOV_X(Z), KC_X,    KC_C,    KC_V,  KC_B,   KC_K,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT},
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
  {_______, _______, _______, _______, MOUS,    _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, TM_SSH,  _______},
  {_______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_END,  W_IME,   TM_LSTS, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

[_RAISE] = { /* Raise */
  {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, FX_NEXT, _______, W_QUIT},
  {_______, KC_ASTR, KC_EQL,  KC_PLUS, KC_LPRN, KC_LBRC, KC_RBRC, KC_RPRN, KC_DEL,  KC_BSLS, MOVE,    VMW_REL},
  {_______, KC_ESC,  CUT,     COPY2,   PASTE2,  KC_LCBR, KC_RCBR, KC_PGUP, KC_PGDN, MC_EXPS, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

[_MOVE] = { /* Move */
  {MC_EXPS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   V_ALTB,  TM_PREV, TM_PWIN, TM_NEXT, _______, TOP},
  {_______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, _______, _______, _______, TM_SSH,  BOTTOM},
  {_______, KC_F11,  KC_F12,  _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

[_MOUS] = { /* Mouse */
  {RESET,    _______, _______, _______,  _______, _______, _______, _______, _______, KC_MUTE, KC_MSTP, KC_MPLY},
  {_______,  RGB_TOG, RGB_MOD, RGB_RMOD, RGB_M_B, RGB_M_K, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_VOLD, KC_VOLU},
  {_______,  RGB_HUI, RGB_SAI, RGB_VAI,  RGB_M_R, RGB_M_X, _______, KC_BTN1, _______, KC_BTN2, KC_MPRV, KC_MNXT},
  {_______,  _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______}
},

[_ADJUST] = { /* Adjust (Lower + Raise) */
  {RESET,   _______, EPRM,    _______, _______, _______, _______, _______, _______,  _______, _______, KC_MPLY},
  {_______, W_CADEL, _______, _______, _______, DEBUG,   _______, _______, _______,  _______, _______, KC_VOLU},
  {_______, _______, _______, _______, VERSION, _______, _______, QWERTY,  COLEMAK,  _______, _______, KC_VOLD},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______}
}
};

static bool lower_pressed = false;
static bool raise_pressed = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case COLEMAK:
      if (record->event.pressed) {
        print("mode just switched to Colemak and this is a huge string\n");
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;

    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;

    case LOWER:
      if (record->event.pressed) {
          lower_pressed = true;
          layer_on(_LOWER);
          update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
          layer_off(_LOWER);
          update_tri_layer(_LOWER, _RAISE, _ADJUST);
          if (lower_pressed) {
              toggle_ime(false);
          }
          lower_pressed = false;
      }
      return false;
      break;

    case RAISE:
      if (record->event.pressed) {
          raise_pressed = true;
          layer_on(_RAISE);
          update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
          layer_off(_RAISE);
          update_tri_layer(_LOWER, _RAISE, _ADJUST);
          if (raise_pressed) {
              toggle_ime(true);
          }
          raise_pressed = false;
      }
      return false;
      break;

    case MOVE:
      if (record->event.pressed) {
        layer_on(_MOVE);
      } else {
        layer_off(_MOVE);
      }
      return false;
      break;

    case MOUS:
      if (record->event.pressed) {
        layer_on(_MOUS);
      } else {
        layer_off(_MOUS);
      }
      return false;
      break;

    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;

    case EPRM:
      if (record->event.pressed) {
          eeconfig_init();
      }
      return false;
      break;

    case VERSION:
      if (record->event.pressed) {
          SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;

    default:
      if (record->event.pressed) {
          lower_pressed = false;
          raise_pressed = false;
      }
      break;

  }
  return true;
}
