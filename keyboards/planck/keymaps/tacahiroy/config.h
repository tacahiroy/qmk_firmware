#pragma once

#include "../../config.h"

#define FORCE_NKRO
#define PREVENT_STUCK_MODIFIERS // when switching layers, this will release all mods
#define DEBOUNCE 5 // the delay when reading the value of the pin (5 is default)

#define TAPPING_TERM 150

#undef MOUSEKEY_INTERVAL
#undef MOUSEKEY_DELAY
#undef MOUSEKEY_TIME_TO_MAX
#undef MOUSEKEY_MAX_SPEED
#undef MOUSEKEY_WHEEL_DELAY

#define MOUSEKEY_INTERVAL       20
#define MOUSEKEY_DELAY          0
#define MOUSEKEY_TIME_TO_MAX    20
#define MOUSEKEY_MAX_SPEED      3
#define MOUSEKEY_WHEEL_DELAY    0

#define MUSIC_MASK (keycode != KC_NO)
