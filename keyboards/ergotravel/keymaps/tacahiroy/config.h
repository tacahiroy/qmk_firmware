/*
Copyright 2017 Pierre Constantineau <jpconstantineau@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* Use I2C or Serial, not both */

// #define USE_SERIAL
#define USE_I2C

/* Select hand configuration */

#define MASTER_LEFT

#define FORCE_NKRO
#define PREVENT_STUCK_MODIFIERS // when switching layers, this will release all mods
#define DEBOUNCE 5              // the delay when reading the value of the pin (5 is default)

#define TAPPING_TERM 150

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
