#include "tacahiroy.h"


void toggle_ime(bool is_on) {
    if (is_on) {
        tap_code(KC_HENK);
    } else {
        tap_code(KC_MHEN);
    }
}

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

    case M_HENK:
      if (record->event.pressed) {
        toggle_ime(true);
        lower_pressed = false;
      }
      return false;

    case M_MHEN:
      if (record->event.pressed) {
        toggle_ime(false);
      }
      return false;

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

    case M_EXPS:
      // Escape from VirtualBox / ESXi window :|
      if (record->event.pressed) {
          set_mods(MOD_BIT(KC_RCTL) | MOD_BIT(KC_RALT)); clear_mods();
          set_mods(MOD_BIT(KC_LCTL) | MOD_BIT(KC_LALT)); tap_code(KC_TAB); clear_mods();
      }
      return false;

    default:
      if (record->event.pressed) {
        lower_pressed = false;
        raise_pressed = false;
      }
      break;
  }
  return true;
}
