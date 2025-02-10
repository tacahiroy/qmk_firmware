const uint16_t PROGMEM test_combo1[] = {LSFT_T(KC_A), LT(1, KC_B), COMBO_END};
const uint16_t PROGMEM test_combo2[] = {LSFT_T(KC_A), LT(1, KC_B), KC_C, COMBO_END};
combo_t key_combos[] = {
    COMBO(test_combo1, KC_ESC)
    COMBO(test_combo2, KC_TAB)
};
