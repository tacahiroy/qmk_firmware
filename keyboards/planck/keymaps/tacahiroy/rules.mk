BOOTMAGIC_ENABLE     = no
COMMAND_ENABLE       = no
DEBUG_ENABLE         = no
CONSOLE_ENABLE       = no
TAP_DANCE_ENABLE     = yes
NKRO_ENABLE          = yes

AUDIO_ENABLE = no

SLEEP_LED_ENABLE     = no
LCD_BACKLIGHT_ENABLE = no
LCD_ENABLE           = no

MOUSEKEY_ENABLE      = yes

ifndef QUANTUM_DIR
	include ../../../../Makefile
endif
