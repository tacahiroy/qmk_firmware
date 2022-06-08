#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "config_common.h"
#define FORCE_NKRO
#define PREVENT_STUCK_MODIFIERS // when switching layers, this will release all mods

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

#define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF

#endif
