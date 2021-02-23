/* Copyright 2020 Neil Brian Ramirez
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *s
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [0] = LAYOUT_60_ansi_split_bs_rshift_tsangan_encoder(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS, KC_EQL,  KC_DEL,      TG(2), 
         LT(1,KC_TAB),    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC, KC_RBRC, KC_BSPC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,          KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  RSFT_T(KC_DOWN),  LT(2,KC_UP),           KC_VOLU, KC_VOLD,
        KC_LGUI, MO(1),   KC_LALT,                   KC_SPC,                              RALT_T(KC_LEFT),  KC_RGUI,          RCTL_T(KC_RIGHT)
    ),
    [1] = LAYOUT_60_ansi_split_bs_rshift_tsangan_encoder(
        
        KC_GRAVE,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_F6,        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS,  RESET,
        KC_TRNS,    KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,      KC_TRNS, KC_INS,  KC_TRNS, KC_PSCR, KC_SLCK, KC_PAUS, KC_BSLS,
        LGUI(KC_L),  KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS, RCTL(KC_DEL), RGUI(KC_DEL), KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_PGUP,          KC_TRNS,
        KC_CAPS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,      KC_TRNS, KC_TRNS, KC_END,  KC_PGDN,          KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS,
        MEH(KC_S), KC_TRNS, MEH(KC_A),                   KC_MPLY,                                                       KC_TRNS, KC_TRNS, KC_TRNS
	),

    [2] = LAYOUT_60_ansi_split_bs_rshift_tsangan_encoder(
        KC_TRNS, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_M_R, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLU, KC_VOLD, SGUI(KC_S),   KC_TRNS,   
        KC_TRNS, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_M_B, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSLS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,         RCS(KC_ESC),
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,         LALT(KC_F4), KC_TRNS, KC_MNXT, KC_MPRV,
        KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,                                              KC_TRNS, KC_TRNS, KC_TRNS
	)

};

const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
{2, 4, HSV_RED},       // Light 4 LEDs, starting with LED 6
{8, 4, HSV_RED}       // Light 4 LEDs, starting with LED 12);
);


const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
{5, 2, HSV_CYAN); 



 const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
 {11, 2, HSV_PURPLE});
 
 
 // Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
my_capslock_layer,
my_layer1_layer, // Overrides caps lock layer
my_layer2_layer // Overrides other layers);
);

void keyboard_post_init_user(void) {
// Enable the LED layers
rgblight_layers = my_rgb_layers;}

layer_state_t layer_state_set_user(layer_state_t state) {
// Both layers will light up if both kb layers are active
rgblight_set_layer_state(1, layer_state_cmp(state, 1));
rgblight_set_layer_state(2, layer_state_cmp(state, 2));
return state;
};

bool led_update_user(led_t led_state) {
rgblight_set_layer_state(0, led_state.caps_lock);
return true;
};