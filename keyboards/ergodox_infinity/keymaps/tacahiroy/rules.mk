AUDIO_ENABLE     = no  # Audio output on port C6
BACKLIGHT_ENABLE = no  # Disable keyboard backlight functionality
BLUETOOTH_ENABLE = no  # Enable Bluetooth with the Adafruit EZ-Key HID
BOOTMAGIC_ENABLE = yes # Virtual DIP switch configuration(+1000)
COMMAND_ENABLE   = no  # Commands for debug and configuration
CONSOLE_ENABLE   = no  # Console for debug(+400)
DEBUG_ENABLE     = no
EXTRAKEY_ENABLE  = yes # Audio control and System control(+450)
MIDI_ENABLE      = no  # MIDI controls
NKRO_ENABLE      = yes # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ # nkro-doesnt-work
RGBLIGHT_ENABLE  = no  # Enable WS2812 RGB underlight.  Do not enable this with audio at the same time.
TAP_DANCE_ENABLE = yes
UNICODE_ENABLE   = no  # Unicode

SLEEP_LED_ENABLE     = no
LCD_BACKLIGHT_ENABLE = yes
LCD_ENABLE           = yes

MOUSEKEY_ENABLE      = yes # Mouse keys(+4700)
MOUSEKEY_INTERVAL    = 10
MOUSEKEY_DELAY       = 0
MOUSEKEY_TIME_TO_MAX = 5
MOUSEKEY_MAX_SPEED   = 3
MOUSEKEY_WHEEL_DELAY = 0

ifndef QUANTUM_DIR
	^ include ../../../../Makefile
endif
