/*
    Note: this is a modified copy of ../default/visualizer.c, originally licensed GPL.
    Current layer detection mechanism is taken from narze/visualizer.c
*/

#include "simple_visualizer.h"
#include "version.h"
#include <string.h>
#include "util.h"

enum ergodox_layers {
    _CLMK,
    _QWTY,
    _MOVE,
    _MDIA,
    _MOUS,
    _SPCL
};

// This function should be implemented by the keymap visualizer
// Don't change anything else than state->target_lcd_color and state->layer_text as that's the only thing
// that the simple_visualizer assumes that you are updating
// Also make sure that the buffer passed to state->layer_text remains valid until the previous animation is
// stopped. This can be done by either double buffering it or by using constant strings
static void get_visualizer_layer_and_color(visualizer_state_t* state) {
    uint8_t saturation = 255;
    if (state->status.leds & (1u << USB_LED_CAPS_LOCK)) {
        saturation = 255;
    }

    uint8_t layer = biton32(state->status.layer);
    switch(layer) {
        case _SPCL:
            state->target_lcd_color = LCD_COLOR(256, saturation, 234<<1u);
            state->layer_text = "SPCL";
            break;
        case _MOUS:
            state->target_lcd_color = LCD_COLOR(222, saturation, 222<<1u);
            state->layer_text = "MOUS";
            break;
        case _MDIA:
            state->target_lcd_color = LCD_COLOR(192, saturation, 192<<1u);
            state->layer_text = "MDIA";
            break;
        case _MOVE:
            state->target_lcd_color = LCD_COLOR(128, saturation, 107<<1u);
            state->layer_text = "MOVE";
            break;
        case _QWTY:
            state->target_lcd_color = LCD_COLOR(48, saturation, 64<<1u);
            state->layer_text = "QWTY";
            break;
        default:
#ifdef MASTER_IS_ON_RIGHT
            state->target_lcd_color = LCD_COLOR(40, saturation, 42<<1u);
            state->layer_text = "CLMK";
#else
            state->target_lcd_color = LCD_COLOR(32, saturation, 42<<1u);
            state->layer_text = QMK_VERSION;
#endif
            break;
    }
}
