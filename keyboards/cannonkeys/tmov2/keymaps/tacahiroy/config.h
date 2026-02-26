#ifndef CONFIG_USER_H

#define CONFIG_USER_H

#define NKRO_DEFAULT_ON true
#define PREVENT_STUCK_MODIFIERS // when switching layers, this will release all mods

#define LAYOUT_COLEMAK

#define TAPPING_TERM 150
#define MEDIA_KEY_DELAY 20

#undef MOUSEKEY_INTERVAL
#undef MOUSEKEY_DELAY
#undef MOUSEKEY_TIME_TO_MAX
#undef MOUSEKEY_MAX_SPEED
#undef MOUSEKEY_WHEEL_DELAY

#define MOUSEKEY_INTERVAL       10
#define MOUSEKEY_DELAY          0
#define MOUSEKEY_TIME_TO_MAX    30
#define MOUSEKEY_MAX_SPEED      4
#define MOUSEKEY_WHEEL_DELAY    0

#define MK_KINETIC_SPEED

#define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF
  
// https://docs.qmk.fm/features/caps_word
#define CAPS_WORD_INVERT_ON_SHIFT
#define CAPS_WORD_IDLE_TIMEOUT 3000  // 3 seconds.

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

// https://docs.qmk.fm/#/squeezing_avr?id=layers
#define LAYER_STATE_16BIT

#endif
