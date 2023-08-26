/* Copyright 2022 DZTECH <moyi4681@live.cn>
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
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum layers {
    _BASE = 0,
    _GAME,
    _FN1
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
	KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   KC_MPLY,   KC_MPRV, KC_MNXT,
	KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,   KC_BSPC,   KC_HOME, KC_PGUP,
	KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,  KC_BSLS,   KC_END,  KC_PGDN,
	KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,           KC_ENT,
	KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,           TG(_GAME), KC_UP,
	KC_LCTL, KC_LGUI, KC_LALT,                           KC_SPC,                                       KC_RALT, MO(_FN1), KC_LEFT,   KC_DOWN, KC_RGHT
  ),

  [_GAME] = LAYOUT(
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
	KC_RCTL, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,  _______,
	_______, KC_NO,   _______,                           _______,                                      _______, _______, _______,  _______, _______
  ),

  [_FN1] = LAYOUT(
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT,  _______, NK_TOGG,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
	KC_RCTL, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,  KC_WH_U,
	_______, KC_LGUI, _______,                           _______,                                      _______, _______, KC_PGUP,  KC_WH_D, KC_PGDN
  )
};

// Key overrides

// shift + backspace => delete
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_CTRL, KC_BSPC, KC_DEL);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &delete_key_override,
    NULL // Null terminate the array of overrides!
};
