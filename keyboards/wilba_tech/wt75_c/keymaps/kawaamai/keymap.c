#include QMK_KEYBOARD_H


enum layers {
	_BASE = 0,
	_FN1,
	_FN2,
	_FN3,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	// Default layer
	[_BASE] = LAYOUT_ansi_rwkl(
		KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  MO(3),
		KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_PGUP,
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGDN,
		KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,                    MO(1),
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                   KC_UP,
		KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(2),            KC_LEFT, KC_DOWN, KC_RGHT),

	// Fn1 Layer
	[_FN1] = LAYOUT_ansi_rwkl(
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,           KC_HOME,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_END,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_INS,                    _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,
		_______, _______, _______,                            _______,                            _______, _______,          _______, _______, _______),

	// Fn2 Layer
	[_FN2] = LAYOUT_ansi_rwkl(
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,
		_______, _______, _______,                            _______,                            _______, _______,          KC_MPRV, KC_MPLY, KC_MNXT),

	// Fn3 Layer
	[_FN3] = LAYOUT_ansi_rwkl(
		_______, _______, _______, _______, _______, _______, _______, _______, _______, GU_ON,   GU_OFF,  NK_ON,   NK_OFF,  _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_PSCR,
		_______, QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_PAUS,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,
		_______, _______, _______,                            _______,                            _______, _______,          _______, _______, _______),
};

// Kye overrides

// ctrl + backspace => delete
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_CTRL, KC_BSPC, KC_DEL);

// lalt + hjkl => left/down/up/right
const key_override_t left_key_override = ko_make_basic(MOD_MASK_ALT, KC_H, KC_LEFT);
const key_override_t down_key_override = ko_make_basic(MOD_MASK_ALT, KC_J, KC_DOWN);
const key_override_t up_key_override = ko_make_basic(MOD_MASK_ALT, KC_K, KC_UP);
const key_override_t right_key_override = ko_make_basic(MOD_MASK_ALT, KC_L, KC_RIGHT);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &delete_key_override,
    &left_key_override,
    &down_key_override,
    &up_key_override,
    &right_key_override,
    NULL // Null terminate the array of overrides!
};