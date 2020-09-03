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
#endif

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
