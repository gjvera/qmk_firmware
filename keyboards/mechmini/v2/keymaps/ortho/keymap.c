#include QMK_KEYBOARD_H
enum {
    LPAREN_BRACE = 0,
    RPAREN_BRACE
};
#define _BL 0
#define _FN1 1
#define _FN2 2
#define _FN3 3
#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_BL] = LAYOUT_ortho(
		KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
		KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, MO(3),
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT,
		KC_LCTL, KC_LGUI, KC_LALT, KC_LALT, KC_SPC, MO(1), MO(2), KC_ENT, M(4), KC_UP, KC_DOWN, M(5)),

	[_FN1] = LAYOUT_ortho(
		M(7), KC_1, KC_UP, KC_3, KC_4, KC_5, M(2), RGB_SAI, RGB_SAD, KC_9, KC_0, KC_BSPC,
		M(3), KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, RGB_MOD, RGB_TOG, RGB_HUI, RGB_HUD, KC_EQL, KC_BSLS, KC_DEL,
		KC_TRNS, KC_TRNS, KC_TRNS, M(8), M(1), KC_TRNS, KC_TRNS, RGB_VAI, RGB_VAD, KC_HOME, KC_END, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY),

	[_FN2] = LAYOUT_ortho(
		KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
		KC_TRNS, BL_TOGG, BL_STEP, KC_MPRV, KC_MPLY, KC_MNXT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL,
		KC_TRNS, RGB_TOG, RGB_MOD, KC_VOLD, KC_MUTE, KC_VOLU, RGB_HUD, RGB_SAI, RGB_SAD, KC_HOME, KC_END, KC_TRNS,
		RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MNXT, KC_PGDN, KC_PGUP, KC_MPLY),
    
    [_FN3] = LAYOUT_ortho(
		M(3), KC_Q, KC_W, KC_E, KC_R, KC_T, M(1), KC_EQL, KC_7, KC_8, KC_9, KC_BSPC,
		M(6), KC_QUOTE, KC_S, KC_D, TD(LPAREN_BRACE), TD(RPAREN_BRACE), KC_BSLS, KC_MINS, KC_4, KC_5, KC_6, MO(3),
		KC_LSFT, KC_GRV, KC_X, KC_C, KC_V, KC_B, KC_N, KC_SLSH, KC_1, KC_2, KC_3, KC_ENT,
		KC_LCTL, KC_LGUI, KC_LALT, KC_LALT, MO(1), KC_SPC, KC_SPC, MO(2), KC_LEFT, KC_0, KC_UP, KC_RGHT),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {


	switch (id) {
		case 1:
			if (record->event.pressed) {
				return MACRO( D(LGUI), T(TAB), T(TAB), U(LGUI), END );
			}
			break;
		case 2:
			if (record->event.pressed) {
				return MACRO( D(LALT), T(TAB), END );
			}
			break;
        case 3:
            if(record->event.pressed){
                return MACRO( D(LCTL), D(LALT), T(DEL), U(LCTL), U(LALT), END ); 
            }
            break;
        case 4:
            if(record->event.pressed){
                return MACRO( D(LGUI), T(W), U(LGUI), T(LEFT), END ); 
            }
            break;
        case 5:
            if(record->event.pressed){
                return MACRO( D(LGUI), T(W), U(LGUI), T(RIGHT), END ); 
            }
            break;
        case 6:
            if(record->event.pressed){
                return MACRO( T(ESC), D(LSFT), T(SCLN), U(LSFT), T(V), T(S), T(SPC), D(LSFT), T(BSLS), U(LSFT), T(SPC), T(T), T(E), T(ENT),T(I), END ); 
            }
            break;
        case 7:
            if(record->event.pressed){
                return MACRO(D(LCTL), D(LSFT), D(DEL), U(LCTL), U(LSFT), U(DEL), END);
            }
            break;
        case 8:
            if(record->event.pressed){
                return MACRO(D(LCTL), T(TAB), U(LCTL), END);
            }
	}
	return MACRO_NONE;
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}

void led_set_user(uint8_t usb_led) {

	if (usb_led & (1 << USB_LED_NUM_LOCK)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_COMPOSE)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_KANA)) {

	} else {

	}

}

enum function_id {
    SHIFT_ESC,
};

const uint16_t PROGMEM fn_actions[] = {
  [0]  = ACTION_FUNCTION(SHIFT_ESC),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  static uint8_t shift_esc_shift_mask;
  switch (id) {
    case SHIFT_ESC:
      shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
      if (record->event.pressed) {
        if (shift_esc_shift_mask) {
          add_key(KC_GRV);
          send_keyboard_report();
        } else {
          add_key(KC_ESC);
          send_keyboard_report();
        }
      } else {
        if (shift_esc_shift_mask) {
          del_key(KC_GRV);
          send_keyboard_report();
        } else {
          del_key(KC_ESC);
          send_keyboard_report();
        }
      }
      break;
  }
}

void left_dance_paren_finished (qk_tap_dance_state_t * state, void * user_data){
    if(state->count == 1) {
        register_code(KC_LSFT);
        register_code(KC_9);
    }
    else if(state->count == 2){
        register_code(KC_LBRC);
    }
    else{
        register_code(KC_LSFT);
        register_code(KC_LBRC);
    }
}

void left_dance_paren_reset(qk_tap_dance_state_t * state, void * user_data){
    if(state->count == 1) {
       unregister_code(KC_LSFT);
       unregister_code(KC_9);
    }
    else if(state->count == 2){
        unregister_code(KC_LBRC);
    }
    else{
        unregister_code(KC_LSFT);
        unregister_code(KC_LBRC);
    }
}

void right_dance_paren_finished (qk_tap_dance_state_t * state, void * user_data){
    if(state->count == 1) {
        register_code(KC_LSFT);
        register_code(KC_0);
    }
    else if(state->count == 2){
        register_code(KC_RBRC);
    }
    else{
        register_code(KC_LSFT);
        register_code(KC_RBRC);
    }
}

void right_dance_paren_reset(qk_tap_dance_state_t * state, void * user_data){
    if(state->count == 1) {
       unregister_code(KC_LSFT);
       unregister_code(KC_0);
    }
    else if(state->count == 2){
        unregister_code(KC_RBRC);
    }
    else{
        unregister_code(KC_LSFT);
        unregister_code(KC_RBRC);
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [LPAREN_BRACE] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, left_dance_paren_finished, left_dance_paren_reset),
    [RPAREN_BRACE] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, right_dance_paren_finished, right_dance_paren_reset)
};
