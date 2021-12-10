AUDIO_ENABLE     = no  # Audio output on port C6
BACKLIGHT_ENABLE = no  # Disable keyboard backlight functionality
BLUETOOTH_ENABLE = no  # Enable Bluetooth with the Adafruit EZ-Key HID
BOOTMAGIC_ENABLE = no  # Virtual DIP switch configuration(+1000)
COMMAND_ENABLE   = no  # Commands for debug and configuration
CONSOLE_ENABLE   = no  # Console for debug(+400)
DEBUG_ENABLE     = no
EXTRAKEY_ENABLE  = yes # Audio control and System control(+450)
MIDI_ENABLE      = no  # MIDI controls
NKRO_ENABLE      = yes # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ # nkro-doesnt-work
RGBLIGHT_ENABLE  = no  # Enable WS2812 RGB underlight.  Do not enable this with audio at the same time.
TAP_DANCE_ENABLE = no
UNICODE_ENABLE   = no  # Unicode
LEADER_ENABLE    = no

MOUSEKEY_ENABLE      = yes # Mouse keys(+4700)

ifndef QUANTUM_DIR
	^ include ../../../../Makefile
endif

USER_NAME = tacahiroy
