#include "tacahiroy.h"

void toggle_ime(bool is_on) {
    if (is_on) {
        register_code(KC_HENK);
        unregister_code(KC_HENK);
    } else {
        register_code(KC_MHEN);
        unregister_code(KC_MHEN);
    }
}

#ifdef TAP_DANCE_ENABLE

typedef struct {
    uint16_t ime_key;
} toggle_ime_config_t;

void td_selall_ctrl_alt(qk_tap_dance_state_t *state, void *user_data) {
    switch(state->count) {
        case 1:
            // Ctrl + A
            register_code(KC_LCTL);
            register_code(KC_A);
            unregister_code(KC_LCTL);
            unregister_code(KC_A);
            break;
        case 2:
            // RCtrl + RAlt
            register_code(KC_RCTL);
            register_code(KC_RALT);
            unregister_code(KC_RCTL);
            unregister_code(KC_RALT);
            break;
        default:
            break;
    }
}

void td_super_esc(qk_tap_dance_state_t *state, void *user_data) {
    /* toggle_ime_config_t *config = (toggle_ime_config_t *) user_data; */

    switch(state->count) {
        case 1:
            register_code(KC_ESC);
            unregister_code(KC_ESC);
            break;
        case 2:
            register_code(KC_ESC);
            unregister_code(KC_ESC);
            register_code(KC_ESC);
            unregister_code(KC_ESC);

            register_code(KC_MHEN);
            unregister_code(KC_MHEN);
            break;
        default:
            break;
    }
}

// Tap Dance Declarations
qk_tap_dance_action_t tap_dance_actions[] = {
    // 1: copy, 2: paste (Shift + Ins)
    [TD_KOPIPE] = ACTION_TAP_DANCE_DOUBLE(COPY, PASTE2),
    [TD_SELALL_CTRL_ALT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_selall_ctrl_alt, NULL),
    [TD_SUPER_ESC] = {
        .fn = { NULL, td_super_esc, NULL },
        .user_data = (void *)&((toggle_ime_config_t) { KC_HENK })
    },
};
#endif // #ifdef TAP_DANCE_ENABLE

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    // MACRODOWN only works in this function
    switch(id) {
        case maVMW_REL:
            // Alt + Ctrl: is a hotkey to get the cursor back from VMware console window
            if (record->event.pressed) {
                return MACRO ( D(RALT), D(RCTL), U(RALT), U(RCTL), END );
            }
            break;
        case maEXPS:
            // Escape from VirtualBox window :|
            if (record->event.pressed) {
                return MACRO ( D(RCTL), D(RALT), U(RCTL), U(RALT), D(LCTL), D(LALT), T(TAB), END );
            }
            break;
    }
    return MACRO_NONE;
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
