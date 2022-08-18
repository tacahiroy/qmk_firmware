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
 * Copyright 2019-2022 Takahiro Yoshihara <tacahiroy@gmail.com>
 * Created my own version of this file based on preonic/default.
 */

#include QMK_KEYBOARD_H

#include "muse.h"
#include "tacahiroy.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_COLEMAK] = LAYOUT_preonic_grid(
  KC_GRV,     KC_1, KC_2,    KC_3,    KC_4,  KC_5,   KC_6,   KC_7,  KC_8,    KC_9,    KC_0,    KC_MINS,
  KC_TAB,     KC_Q, KC_W,    KC_F,    KC_P,  KC_G,   KC_J,   KC_L,  KC_U,    KC_Y,    KC_SCLN, KC_QUOT,
  CTL_X(ESC), KC_A, KC_R,    KC_S,    KC_T,  KC_D,   KC_H,   KC_N,  KC_E,    KC_I,    KC_O,    KC_ENT,
  KC_LSFT,    KC_Z, KC_X,    KC_C,    KC_V,  KC_B,   KC_K,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  KC_MPLY,    MOUS, KC_LGUI, KC_LALT, LOWER, KC_SPC, KC_SPC, RAISE, KC_BSPC, KC_BSLS, KC_RCTL, KC_ESC
),

[_QWERTY] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
  _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______,
  _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_LOWER] = LAYOUT_preonic_grid(
  W_IME,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  M_EXPS,  XX_WIN,  XX_TAB,  KC_MS_U, W_SSHOT, KC_BTN1, KC_BTN2, TM_PREV, KC_BSPC, TM_NEXT, KC_PIPE, KC_F12,
  _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, TM_SSH,  _______,
  _______, _______, _______, _______, _______, TOP,     BOTTOM,  KC_HOME, KC_END,  _______, TM_LSTS, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_RAISE] = LAYOUT_preonic_grid(
  _______, ZOOMIN,  _______, _______, _______, _______, WS_LEFT, WS_RGHT, _______, _______, ZOOMOUT, XX_WIN,
  W_S_WIN, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, FX_NEXT, _______, RAL_RCT,
  _______, KC_MINS, KC_EQL,  KC_PLUS, KC_LPRN, KC_LBRC, KC_RBRC, KC_RPRN, KC_DEL,  KC_BSLS, MIC_TGL, _______,
  _______, KC_UNDS, CUT,     COPY2,   PASTE2,  KC_LCBR, KC_RCBR, KC_PGUP, KC_PGDN, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_MOUS] = LAYOUT_preonic_grid(
  RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPLY,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_ADJUST] = LAYOUT_preonic_grid(
  RESET,   _______, EPRM,    _______, _______, _______, _______, _______, _______,  _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
  _______, CADEL,   _______, _______, _______, DEBUG,   _______, _______, _______,  _______, _______, _______,
  _______, _______, _______, _______, VERSION, _______, _______, QWERTY,  COLEMAK,  _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    uint16_t held_keycode_timer = timer_read();
    if (clockwise) {
        register_code(KC_VOLU);
        while (timer_elapsed(held_keycode_timer) < MEDIA_KEY_DELAY) {
            // no-op
        }
        unregister_code(KC_VOLU);
    } else {
        register_code(KC_VOLD);
        while (timer_elapsed(held_keycode_timer) < MEDIA_KEY_DELAY) {
            // no-op
        }
        unregister_code(KC_VOLD);
    }

    return true;
}
#endif

void dip_update(uint8_t index, bool active) {
  switch (index) {
    case 0:
      if (active) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      break;
    case 1:
      if (active) {
        muse_mode = true;
      } else {
        muse_mode = false;
        #ifdef AUDIO_ENABLE
          stop_all_notes();
        #endif
      }
   }
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
