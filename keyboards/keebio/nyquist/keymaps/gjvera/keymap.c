#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// E49ggach layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#define ALT_TAB LALT(KC_TAB)
#define GUI_TAB LGUI(KC_TAB)
#define CTL_ALT_DEL LCA(KC_DEL)

enum {
    LPAREN_BRACE = 4,
    RPAREN_BRACE
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT(
            KC_F1,  KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,    KC_F11,    KC_F12, 
            KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, 
            KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, MO(1), 
            KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_NO , 
            KC_LCTL,  KC_LGUI, KC_LALT, KC_LGUI, KC_SPC,   MO(2),  MO(3),  KC_ENT,   M(4), M(9), M(10),   M(5) 
          ),
    LAYOUT(
	   KC_F1,   KC_F2,   KC_F3,   LCA(KC_Z),   KC_F5,   KC_F6,   KC_F7,   KC_F8,   LCA(KC_C),   KC_F10,  KC_F11,  KC_F12, 
	   M(3), KC_Q, KC_W, KC_E, LALT(KC_R), KC_T, M(1), KC_EQL, KC_7, KC_8, KC_9, KC_BSPC, 
            LGUI(KC_X), KC_QUOTE, KC_S, KC_D, TD(LPAREN_BRACE), TD(RPAREN_BRACE), KC_BSLS, KC_MINS, KC_4, KC_5, KC_6, KC_TRNS, 
            KC_LSFT, KC_GRV, KC_X, KC_C, KC_V, KC_B, KC_N, KC_SLSH, KC_1, KC_2, KC_3, KC_ENT, 
            KC_LCTL, KC_LGUI, KC_LALT, KC_LALT, KC_NO, KC_SPC, KC_SPC, KC_NO, KC_LEFT, KC_0, KC_UP, KC_RGHT 
          ),

    LAYOUT(
            KC_TILD, KC_1, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, 
            CTL_ALT_DEL, KC_1, KC_UP,   KC_3, KC_4,  KC_5, M(2), RGB_SAI, RGB_SAD, KC_9, KC_0, KC_PSCR, 
            M(3),  KC_LEFT,   KC_DOWN,   KC_RIGHT,   KC_TRNS,   RGB_MOD,   RGB_TOG, RGB_HUI, RGB_HUD, KC_EQL, KC_BSLS, KC_DEL, 
            KC_TRNS, KC_TRNS,   KC_TRNS,   M(8),   GUI_TAB,  ALT_TAB, KC_TRNS, RGB_VAI, RGB_VAD, KC_HOME, KC_END, KC_TRNS, 
            KC_TRNS, KC_TRNS, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY 
          ),

    LAYOUT(
            KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, 
            KC_F1, KC_MS_BTN2, LALT(KC_K), KC_MS_BTN1, KC_WH_D, KC_F6, KC_F7, KC_VOLD, KC_MUTE, KC_VOLU, KC_F11, KC_F12, 
            KC_TRNS, LALT(KC_H), LALT(KC_J), LALT(KC_L), KC_WH_U, KC_TRNS, KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT, KC_TRNS, KC_DEL, 
            KC_TRNS, RGB_TOG, RGB_MOD, KC_VOLD, KC_MUTE, KC_VOLU, RGB_HUD, RGB_SAI, RGB_SAD, KC_HOME, KC_END, KC_TRNS, 
            RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MNXT, KC_PGDN, KC_PGUP, KC_MPLY 
          ),
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
                return MACRO( D(LCTL), T(W), U(LCTL), T(LEFT), END ); 
            }
            break;
        case 5:
            if(record->event.pressed){
                return MACRO( D(LCTL), T(W), U(LCTL), T(RIGHT), END ); 
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
            break;
        case 9:
            if(record->event.pressed){
                return MACRO( D(LCTL), T(W), U(LCTL), T(DOWN), END ); 
            }
            break;
        case 10:
            if(record->event.pressed){
                return MACRO( D(LCTL), T(W), U(LCTL), T(UP), END ); 
            }
            break;
    }
    return MACRO_NONE;
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}
