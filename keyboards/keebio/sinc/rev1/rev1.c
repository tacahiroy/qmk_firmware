#include "sinc.h"
#include "split_util.h"

void matrix_init_kb(void) {
    setPinOutput(LED_CAPS_LOCK_PIN);
    matrix_init_user();
}

bool led_update_kb(led_t led_state) {
    // Only update if left half
    if (isLeftHand && led_update_user(led_state)) {
        writePin(LED_CAPS_LOCK_PIN, !led_state.caps_lock);
    }
    return true;
}

void eeconfig_init_kb(void) {
#ifdef BACKLIGHT_ENABLE
    backlight_enable();
    backlight_level(3);
#endif
    eeconfig_update_kb(0);
    eeconfig_init_user();
}

bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) { return false; }
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return false;
}
