// this is based on users/kuchosauronad0/leader.c

#include "leader.h"

bool leader_succeed;

LEADER_EXTERNS();

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    }
#endif

    LEADER_DICTIONARY() {
        leader_succeed = leading = false;
        leader_end();

        SEQ_ONE_KEY(KC_L) {
            layer_on(_LOWER);
            leader_succeed = true;
        }

        SEQ_ONE_KEY(KC_SLSH) { // ~/
            SEND_STRING("~/");
            leader_succeed = true;
        }
    }
}

void leader_start(void) {
}

void leader_end(void) {
}
