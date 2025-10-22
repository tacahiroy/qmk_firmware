/* Copyright 2020-2025 Takahiro YOSHIHARA <tacahiroy@gmail.com>
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
 */
#include "tacahiroy.h"

// Initialize variable holding the binary
// representation of active modifiers.
uint8_t mod_state;

static bool lower_pressed = false;
static bool raise_pressed = false;

void toggle_ime(bool is_on) {
    if (is_on) {
        register_code(JP_HENK);
        unregister_code(JP_HENK);
    } else {
        register_code(JP_MHEN);
        unregister_code(JP_MHEN);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case COLEMAK:
      if (record->event.pressed) {
        print("mode just switched to Colemak and this is a huge string\n");
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;

    case NORMAN:
      if (record->event.pressed) {
        print("mode just switched to Norman and this is a huge string\n");
        set_single_persistent_default_layer(_NORMAN);
      }
      return false;

    case MACOS:
      if (record->event.pressed) {
        print("mode just switched to macOS and this is a huge string\n");
        set_single_persistent_default_layer(_MACOS);
      }
      return false;

    case UKISO:
      if (record->event.pressed) {
        print("mode just switched to UKISO and this is a huge string\n");
        set_single_persistent_default_layer(_UKISO);
      }
      return false;

    case BS2U:
      if (record->event.pressed) {
        print("mode just switched to BS2U and this is a huge string\n");
        set_single_persistent_default_layer(_BS2U);
      }
      return false;

    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;

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

    case SYSTEM:
      if (record->event.pressed) {
        layer_on(_SYSTEM);
      } else {
        layer_off(_SYSTEM);
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
          SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP);
      }
      return false;

    case M_EXPS:
      // Escape from VirtualBox / ESXi window :|
      if (record->event.pressed) {
          set_mods(MOD_BIT(KC_RCTL) | MOD_BIT(KC_RALT)); clear_mods();
          set_mods(MOD_BIT(KC_LCTL) | MOD_BIT(KC_LALT)); tap_code(KC_TAB); clear_mods();
      }
      return false;

    // https://docs.qmk.fm/#/feature_advanced_keycodes?id=shift-backspace-for-delete
    case KC_BSPC:
      // Store the current modifier state in the variable for later reference
      mod_state = get_mods();
      return shift_backspace_for_delete(record);

    default:
      if (record->event.pressed) {
        lower_pressed = false;
        raise_pressed = false;
      }
      break;
  }
  return true;
}

bool shift_backspace_for_delete(keyrecord_t *record) {
    // Initialize a boolean variable that keeps track
    // of the delete key status: registered or not?
    static bool delkey_registered;
    if (record->event.pressed) {
        // Detect the activation of either shift keys
        if (mod_state & MOD_MASK_SHIFT) {
            // First temporarily canceling both shifts so that
            // shift isn't applied to the KC_DEL keycode
            del_mods(MOD_MASK_SHIFT);
            register_code(KC_DEL);
            // Update the boolean variable to reflect the status of KC_DEL
            delkey_registered = true;
            // Reapplying modifier state so that the held shift key(s)
            // still work even after having tapped the Backspace/Delete key.
            set_mods(mod_state);
            return false;
        }
    } else { // on release of KC_BSPC
        // In case KC_DEL is still being sent even after the release of KC_BSPC
        if (delkey_registered) {
            unregister_code(KC_DEL);
            delkey_registered = false;
            return false;
        }
    }

    // Let QMK process the KC_BSPC keycode as usual outside of shift
    return true;
}
