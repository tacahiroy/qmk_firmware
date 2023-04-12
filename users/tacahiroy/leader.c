// this is based on users/kuchosauronad0/leader.c

#include "leader.h"

void leader_start_user(void) {
    // Do something when the leader key is pressed
}

void leader_end_user(void) {
    if (leader_sequence_two_keys(KC_D, KC_D)) {
        // dd => Deletes a line
        tap_code(KC_HOME);
        tap_code16(S(KC_END));
        tap_code(KC_DEL);
        tap_code(KC_BSPC);
    } else if (leader_sequence_two_keys(KC_Y, KC_Y)) {
        // yy => Copies a line
        tap_code(KC_HOME);
        tap_code16(S(KC_END));
        tap_code16(C(KC_C));
    } else if (leader_sequence_one_key(KC_P)) {
        // p => Pastes the clipboard content
        tap_code16(S(C(KC_V)));
        tap_code(KC_ENT);
    } else if (leader_sequence_two_keys(KC_Y, KC_S)) {
        // tmux copy: prefix + y, v, y
        tap_code16(C(KC_K));
        tap_code(KC_Y);
        tap_code16(S(KC_V));
        tap_code(KC_Y);
    }
}

