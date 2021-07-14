/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
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

#include QMK_KEYBOARD_H
#include <stdio.h>
#include "lib/glcdfont.c"
#include "lib/layers.c"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum layer_number {
    _QWERTY = 0,
    _RAISE,
    _LOWER,
    _NUMPAD,
};

enum custom_keycodes {
    MY_CAPS = SAFE_RANGE,
    MY_KANA,
    MY_LT2
};

#define KC_TO0 TO(_QWERTY)         // Layer-Move keycode for _QWERTY(layer0)
#define KC_TO1 TO(_RAISE)          // Layer-Move keycode for _RAISE (layer1)
#define KC_TO2 TO(_LOWER)          // Layer-Move keycode for _LOWER (layer2)
#define KC_TO3 TO(_NUMPAD)         // Layer-Move keycode for _NUMPAD(layer3)
#define KC_LT1 LT(_RAISE, KC_NO)   // Layer-Tap keycode for _RAISE (layer1)
#define KC_LT2 LT(_LOWER, KC_CAPS) // Layer-Tap keycode for _LOWER (layer2)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT( \
    //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
        KC_ESC , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,     KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
        KC_TAB , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,     KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
        KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,     KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
    //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                          MY_LT2 , KC_LALT, KC_LCTL, KC_SPC ,     KC_ENT , KC_RCTL, KC_RALT, KC_LT1
    //                 `---------+--------+--------+--------'   `--------+--------+--------+--------'
    ),

    [_RAISE] = LAYOUT( \
    //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
        KC_GRV , KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,     KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_EQL , KC_DEL ,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
        KC_APP , XXXXXXX, KC_LCBR, KC_LPRN, KC_LBRC, XXXXXXX,     KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, XXXXXXX, KC_BSLS,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
        _______, XXXXXXX, KC_RCBR, KC_RPRN, KC_RBRC, XXXXXXX,     KC_HOME, KC_PGDN, KC_PGUP, KC_END , XXXXXXX, _______,
    //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                          MY_CAPS, _______, _______, KC_LGUI,     XXXXXXX, _______, _______, XXXXXXX
    //                  `--------+--------+--------+--------'   `--------+--------+--------+--------'
    ),

    [_LOWER] = LAYOUT( \
    //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
        _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,     KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , _______,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
        KC_TO0 , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_PAUS,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
        _______, KC_F11 , KC_F12 , XXXXXXX, KC_INS , XXXXXXX,     KC_PSCR, XXXXXXX, _______, _______, _______, _______,
    //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                          XXXXXXX, _______, _______, _______,     _______, _______, _______, KC_TO3
    //                  `--------+--------+--------+--------'   `--------+--------+--------+--------'
    ),

    [_NUMPAD] = LAYOUT( \
    //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
        _______, RESET  , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     KC_PSLS, KC_P7  , KC_P8  , KC_P9  , XXXXXXX, _______,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
        KC_TO0 , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     KC_PAST, KC_P4  , KC_P5  , KC_P6  , KC_EQL , XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     KC_PMNS, KC_P1  , KC_P2  , KC_P3  , KC_PDOT, _______,
    //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                          MY_KANA, _______, _______, _______,     _______, _______, KC_PPLS, KC_P0
    //                  `--------+--------+--------+--------'   `--------+--------+--------+--------'
    ),
};

#ifdef OLED_DRIVER_ENABLE

static uint8_t rotation_state, buf_blocks, skipped_pixel;
static uint8_t caps_state  = 0;
static uint8_t kana_state  = 0;

void switch_rotation(bool on) {
    if (on) {
        rotation_state = 1; // vertical
        buf_blocks     = OLED_DISPLAY_HEIGHT / OLED_FONT_WIDTH; // 5 (default)
        skipped_pixel  = OLED_DISPLAY_HEIGHT % OLED_FONT_WIDTH; // 2px (default)
    } else {
        rotation_state = 0; // horizontal
        buf_blocks     = OLED_DISPLAY_WIDTH / OLED_FONT_WIDTH; // 21 (default)
        skipped_pixel  = OLED_DISPLAY_WIDTH % OLED_FONT_WIDTH; // 2px (default)
    }
}

void write_font_block(const unsigned char* p, uint16_t read_index, uint16_t write_index) {
    unsigned char raw_byte;
    uint8_t line_number = write_index / buf_blocks; // Get a line number to write
    for (int i = 0; i < OLED_FONT_WIDTH; i++) {
        raw_byte = pgm_read_byte(p + (read_index * OLED_FONT_WIDTH + i));
        oled_write_raw_byte(raw_byte, write_index * OLED_FONT_WIDTH + i + (line_number * skipped_pixel)); // Skip 2*N px every line
    }
}

void write_font_blocks(const unsigned char* p, uint8_t row, uint8_t col, uint16_t param_r_idx, uint16_t param_w_idx) {
    uint16_t read_index, write_index;
    for (int i = 0; i < row; i++) {
        read_index  = param_r_idx + (i * 32); // Read blocks per line from OLED font (default 32 blocks)
        write_index = param_w_idx + (i * buf_blocks); // Write blocks per line to OLED buffer (default 5 or 21 blocks)
        for (int j = 0; j < col; j++) {
            write_font_block(p, read_index + j, write_index + j);
        }
    }
}

void render_layer_state(void) {
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            write_font_blocks(layer_char, 2, 5, 0x01, 0);
            break;
        case _RAISE:
            write_font_blocks(layer_char, 2, 5, 0x06, 0);
            break;
        case _LOWER:
            write_font_blocks(layer_char, 2, 5, 0x0b, 0);
            break;
        case _NUMPAD:
            write_font_blocks(layer_char, 2, 5, 0x10, 0);
            break;
        default:
            write_font_blocks(layer_char, 2, 5, 0x15, 0);
    }
}

void render_caps_state(void) {
    caps_state ? write_font_blocks(layer_char, 2, 5, 0x41, 20)  // upper
               : write_font_blocks(layer_char, 2, 5, 0x46, 20); // lower
}

void render_kana_state(void) {
    kana_state ? write_font_blocks(layer_char, 2, 3, 0x5d, 41)  // kana
               : write_font_blocks(layer_char, 2, 3, 0x5a, 41); // eisu
}

void render_logo(void) {
    switch_rotation(0); // horizontal (logo display)
    write_font_blocks(font, 3, 21, 0x80, 0); // official claw44 logo
    switch_rotation(1); // vertical (main display)
}

// The function to render and maintain the CapsLock state on OLED
bool led_update_user(led_t led_state) {
    // TODO: caps_state initialization may be ought to be moved here
    if (caps_state != led_state.caps_lock) {
        caps_state = led_state.caps_lock;
        render_caps_state();
    }
    // TODO: implement led_state.kana later
    // TODO: kana_state initialization may be ought to be moved here
    /* if (kana_state != led_state.kana) { */
    /*     kana_state = led_state.kana; */
    /*     render_kana_state(); */
    /* } */
    return false;
}
// _kb() is a hook for _user()
bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    return res;
}

void press_capslock(uint8_t temp_mod){
    clear_mods();
    if (temp_mod & MOD_MASK_SHIFT) {
        tap_code16(S(KC_CAPS)); // Shift + CapsLock
    } else if (temp_mod & MOD_MASK_CA) {
        tap_code(KC_CAPS); // CapsLock (that ignores Ctrl/Alt)
        kana_state ^= 1; // Toggle IME(kana/eisu) state
    } else {
        tap_code(KC_CAPS); // CapsLock
        kana_state ^= 1; // Toggle IME(kana/eisu) state
    }
    set_mods(temp_mod);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_layer_state();
        render_kana_state();
    } else {
        render_logo();
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) return OLED_ROTATION_180;
    switch_rotation(1); // vertical (main display)
    return OLED_ROTATION_270;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint8_t checker_numpad = 0;
    static uint8_t checker_caps = 0;
    uint8_t temp_mod = get_mods();
    /* temp_mod = get_mods(); */
    switch (keycode) {
        // Customized keycodes for CapsLock
        case KC_CAPS:
            if (record->event.pressed) {
                return false; // No change is reflected until you release CapsLock
            } else {
                press_capslock(temp_mod);
            }
            break;
        case MY_CAPS:
            if (record->event.pressed) { tap_code16(S(KC_CAPS)); } // Users are forced to press NOT CapsLock BUT Shift + CapsLock
            break;

        // Toggle an IME view on OLED without toggling an internal IME state
        // This keycode is prepared for users to adjust the IME view to the internal IME state
        case MY_KANA:
            if (record->event.pressed) { kana_state ^= 1; }
            break;

        // Customized Layer-Tap keycode
        case MY_LT2:
            if (record->event.pressed) {
                layer_state_set(0b0100);
                return false; // Keep staying at the layer 2 while holding key
            } else {
                // Check whether Numpad key (KC_TO3) is pressed
                if (checker_numpad) {
                    layer_state_set(0b1000); // Move to the layer3 (_NUMPAD)
                    checker_numpad = 0;
                    return true;
                } else {
                    layer_state_set(0b0000); // Return to the default layer (_QWERTY)
                }

                // If the specific keys are pressed, do NOT call press_capslock()
                if (!checker_caps) { press_capslock(temp_mod); }
                checker_caps = 0; // Even if 1, force it to be 0
            }
            break;
        case KC_TO3:
            if (record->event.pressed) { checker_numpad = 1; }
            break;

        // If these keys are pressed, do NOT call press_capslock()
        case KC_F1 ... KC_F12: // Function keys
        case KC_1 ... KC_0: // Number keys
        case KC_INS: // Insert
        case KC_PAUS: // Pause
        case KC_PSCR: // Print Screen
            if (record->event.pressed) { checker_caps = 1; }
            break;
    }
    return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_LT1:
        case KC_LT2:
            return 10;
        default:
            return TAPPING_TERM; // 150ms
    }
}

#endif // OLED_DRIVER_ENABLE
