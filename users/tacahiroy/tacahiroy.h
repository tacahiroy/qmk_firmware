#pragma once

#include "quantum.h"

#include "version.h"
#include "eeprom.h"

/* #include "quantum.h" */

// Layer shorthand
enum usespace_layers {
  _COLEMAK,
  _QWERTY,
  _LOWER,
  _RAISE,
  _MOUS,
  _MOVE,
  _ADJUST,
};

#ifdef TAP_DANCE_ENABLE
enum {
    TD_KOPIPE,
    TD_SELALL_CTRL_ALT,
    TD_SUPER_ESC,
};

#define TDKPP  TD(TD_KOPIPE)
#define TDSACA TD(TD_SELALL_CTRL_ALT)
#define TDSPESC TD(TD_SUPER_ESC)
#define KC_TDSPESC TDSPESC

void td_selall_ctrl_alt(qk_tap_dance_state_t *state, void *user_data);
void td_super_esc(qk_tap_dance_state_t *state, void *user_data);
#endif

void toggle_ime(bool is_on);

// key combinations
#define _______  KC_TRNS

// Windows specific key combinations
#define W_CADEL  LCTL(LALT(KC_DEL)) // Ctrl + Alt + Del
#define COPY     LCTL(KC_C)         // C-c Copy
#define COPY2    LALT(KC_C)         // M-c Copy
#define CUT      LCTL(KC_X)         // C-x Cut
#define PASTE    LCTL(KC_V)         // C-v Paste
#define PASTE2   S(KC_INS)          // Shift+Ins Paste
#define SELALL   LCTL(KC_A)         // C-v Paste
#define W_QUIT   LALT(KC_F4)        // M-F4 Close window on Windows
#define W_S_WIN  LCTL(LALT(KC_TAB)) // Activate the window switcher
#define W_IME    LALT(KC_GRV)       // Toggle IME on / off state on Windows
#define VMW_REL  RALT(KC_RCTL)      // Hotkey to release keyboard in a VMware window
#define TOP      LCTL(KC_HOME)
#define BOTTOM   LCTL(KC_END)
#define W_SSHOT  S(LGUI(KC_S))      // Activate the screenshot tool

// Vim
#define V_ALTB   LCTL(KC_6) 				// Changing to an alternate buffer in Vim

// Tmux
#define TM_PREV  LALT(KC_L)
#define TM_NEXT  LALT(KC_Y)
#define TM_SSH   LALT(KC_O)
#define TM_NEW   LALT(KC_N)
#define TM_PWIN  LALT(KC_G)
// last session
#define TM_LSTS  LALT(KC_SLSH)

 // Firefox and other web browsers
#define FX_NEXT  LCTL(KC_TAB)
#define FX_PREV  LCTL(LSFT(KC_TAB))

#define CTL_X(k) MT(MOD_LCTL, KC_ ## k)
#define SFT_X(k) MT(MOD_LSFT, KC_ ## k)
#define MEH_X(k) MT((MOD_LCTL | MOD_LSFT | MOD_LALT), KC_ ## k)

#define LW_X(k)  LT(_LOWER, KC_ ## k)
#define RS_X(k)  LT(_RAISE, KC_ ## k)
#define MOV_X(k) LT(_MOVE, KC_ ## k)
#define MDI_X(k) LT(_MDIA, KC_ ## k)
#define MOS_X(k) LT(_MOUS, KC_ ## k)

#define maVMW_REL 2
#define maEXPS 3

// Shortcut for macros
#define MC_VMW_REL M(maVMW_REL)
#define MC_EXPS M(maEXPS)
