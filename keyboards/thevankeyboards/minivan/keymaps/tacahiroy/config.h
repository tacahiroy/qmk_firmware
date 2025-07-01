#pragma once

#define NKRO_DEFAULT_ON true
#define PREVENT_STUCK_MODIFIERS // when switching layers, this will release all mods
#define DEBOUNCE 5              // the delay when reading the value of the pin (5 is default)
#define LAYOUT_COLEMAK

#define TAPPING_TERM 150
#define MEDIA_KEY_DELAY 20

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

#define CAPS_WORD_INVERT_ON_SHIFT
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

#define MK_KINETIC_SPEED

#define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF

// https://docs.qmk.fm/#/squeezing_avr?id=layers
#define LAYER_STATE_16BIT
