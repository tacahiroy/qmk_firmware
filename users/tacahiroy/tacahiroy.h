/* Copyright 2020-2023 Takahiro Yoshihara <tacahiroy@gmail.com>
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
#pragma once

#include "quantum.h"
#include "version.h"
#include "keymap_japanese.h"

// Layer shorthand
enum tacahiroy_layers {
  _COLEMAK,
  _HHKB,
  _QWERTY,
  _LOWER,
  _RAISE,
  _MOUS,
  _MOVE,
  _ADJUST,
};

enum tacahiroy_keycodes {
  COLEMAK = SAFE_RANGE,
  HHKB,
  QWERTY,
  LOWER,
  RAISE,
  MOUS,
  MOVE,
  ADJUST,
  VERSION,
  EPRM,
  M_EXPS,
};

void toggle_ime(bool is_on);
bool shift_backspace_for_delete(keyrecord_t *record);

#define LOWER LT(_LOWER, JP_MHEN)
#define RAISE LT(_RAISE, JP_HENK)

// Windows specific key combinations
#define TOP      C(KC_HOME)
#define BOTTOM   C(KC_END)

#define CADEL    LCA(KC_DEL)   // Ctrl + Alt + Del
#define COPY     C(KC_C)       // C-c Copy
#define COPY2    S(C(KC_C))    // C-S-c Copy on some terminal emulators
#define CUT      C(KC_X)       // C-x Cut
#define PASTE    C(KC_V)       // C-v Paste
#define PASTE2   S(C(KC_V))    // C-S-v Paste on some terminal emulators
#define W_IME    A(KC_GRV)     // Toggle IME on / off state on Windows
#define W_SNIP   S(G(KC_S))    // Activate the screenshot tool
#define W_WLST   C(A(KC_TAB))  // Activate the window list on Windows
#define XX_TAB   C(KC_W)       // C-w Close current tab
#define XX_WIN   A(KC_F4)      // M-F4 Close window on Windows

// Vim
#define V_ALTB   C(KC_6)       // Changing to an alternate buffer in Vim

// tmux
#define TM_PREV  A(KC_L)
#define TM_NEXT  A(KC_Y)
#define TM_SSH   A(KC_O)
#define TM_NEW   A(KC_N)
#define TM_PWIN  A(KC_G)
// last session
#define TM_LASS  A(KC_MINS)
#define TM_SLST  A(KC_S)
#define TM_WLST  A(KC_W)

// Parsec (Windows)
#define PS_MNU  C(S(KC_M))
#define PS_WIM  C(S(KC_W))
#define PS_DETM C(A(KC_Z))

 // Firefox and other web browsers
#define FX_NEXT  C(KC_TAB)
#define FX_PREV  C(LSFT(KC_TAB))
#define FX_BACK  A(KC_LEFT)
#define FX_FWD   A(KC_RGHT)

#define CTL_X(k) LCTL_T(KC_ ## k)
#define SFT_X(k) LSFT_T(KC_ ## k)
#define MEH_X(k) MEH_T(KC_ ## k)

#define LW_X(k)  LT(_LOWER, KC_ ## k)
#define RS_X(k)  LT(_RAISE, KC_ ## k)
#define MV_X(k)  LT(_MOVE, KC_ ## k)
#define MO_X(k)  LT(_MOUS, KC_ ## k)
