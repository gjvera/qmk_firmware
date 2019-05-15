#include QMK_KEYBOARD_H
#define ALT_TAB LALT(KC_TAB)
#define GUI_TAB LALT(KC_TAB)
#define CTL_ALT_DEL LCA(KC_DEL)
#define _______ KC_TRNS
enum {
    LPAREN_BRACE = 4,
    RPAREN_BRACE
};

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
/* 
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ESC    |   1  |   2  |   3  |   4  |   5  |  -   |           |  =   |   6  |   7  |   8  |   9  |   0  |  Bsp   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  | PgUp |           |  [   |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Caps   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  | Enter  |
 * |--------+------+------+------+------+------| PgDn |           |  ]   |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  Up  |M2/Shift|
 * `--------+------+------+---------------------------'           `---------------------------+------+------+--------'
 *   | Ctrl |  Gui |  Alt |                                                                   | Left |  Down| Right |
 *   `--------------------'                                                                   `--------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |      |      |       |      |        |  
 *                                        | Space|  M2  |       |  M3  |  Enter | 
 *                                        |      |      |       |      |        | 
 *                                        `-------------'       `---------------'
 */
    [0] = LAYOUT(
  KC_F1,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_MPLY,      KC_MUTE,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,    KC_F12,
  KC_ESC,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_MNXT,      KC_VOLU, KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,    KC_BSPC,
  KC_TAB, KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                          KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN, MO(1), 
  KC_LSFT, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_MPRV,      KC_VOLD, KC_N,   KC_M,   KC_COMM,KC_DOT, KC_UP,   KC_RSFT,
  KC_LCTL, KC_LGUI,KC_LALT,                                                                       KC_LEFT,KC_DOWN, KC_RGHT,
                                           KC_SPC, MO(2),       MO(3), KC_ENT,
                                           KC_NO , KC_NO,       KC_NO,  KC_NO
    ),
/* 
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   ~    |  F1  |  F2  |  F3  |  F4  |  F5  | F11  |           |  F12 |  F6  |  F7  |  F8  |  F9  | F10  |  Del   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |   '    |
 * |--------+------+------+------+------+------|      |           |  M3  |------+------+------+------+------+--------|
 * |        | Mute | Vol- | Vol+ |      |      |      |           |      |      |      |      |      |   /  |        |
 * `--------+------+------+---------------------------'           `---------------------------+------+------+--------'
 *   |      |      |      |                                                                   |      |      |       |
 *   `--------------------'                                                                   `--------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |      |      |       |      |        |  
 *                                        |      |------|       |------|        | 
 *                                        |      |      |       |      |        | 
 *                                        `-------------'       `---------------'
 */
    [1] = LAYOUT(
  KC_GRV,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F11,     KC_F12,  KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_DEL, 
  M(3),  _______,  _______,  _______,  _______,  _______,  _______,    KC_TRNS, M(1),  KC_EQL,  KC_7,  KC_8,  KC_9,  KC_BSPC, 
  M(6),  KC_QUOTE,  _______,  _______,  TD(LPAREN_BRACE),  TD(RPAREN_BRACE),     KC_BSLS,  KC_MINS,  KC_4,  KC_5,  KC_6,  KC_TRNS, 
  _______,  KC_GRV,  _______,  _______,  _______,  _______,  _______,    KC_TRNS,   KC_TRNS,  KC_SLSH,  KC_1,  KC_2,  KC_3,  KC_TRNS, 
  _______,  _______,  _______,                                                                                   _______,  _______,  _______,
                                                    _______,  _______,    _______,  _______,  
                                                    _______,  _______,    _______,  _______
    ),
/* 
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |   '    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |   /  |        |
 * `--------+------+------+---------------------------'           `---------------------------+------+------+--------'
 *   |      |      |      |                                                                   |      |      |       |
 *   `--------------------'                                                                   `--------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |      |      |       |      |        |  
 *                                        |      |------|       |------|        | 
 *                                        |      |      |       |      |        | 
 *                                        `-------------'       `---------------'
 */
    [2] = LAYOUT(
  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______, 
  CTL_ALT_DEL,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,  KC_PSCR, 
  M(3),  _______,  _______,  _______,  _______,  _______,                        _______,  _______,  _______,  _______,  _______,  KC_QUOT,
  _______,  _______,  _______,  M(8),  GUI_TAB,  ALT_TAB,  _______,    _______,  _______,  _______,  _______,  _______,  KC_SLSH,  _______, 
  _______,  _______,  _______,                                                                                    _______,  _______,  _______,
                                                    _______,  _______,    _______,  _______,   
                                                    _______,  _______,    _______,  _______
    ),
/* 
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      | Calc |NumLoc|   /  |   *  |    -   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |   7  |   8  |   9  |    +   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |   4  |   5  |   6  |    =   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |   1  |   2  |   3  |  Enter |
 * `--------+------+------+---------------------------'           `---------------------------+------+------+--------'
 *   |      |      |      |                                                                   |   0  |   .  | Enter|
 *   `--------------------'                                                                   `--------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |      |      |       |      |        |  
 *                                        |      |------|       |------|        | 
 *                                        |      |      |       |      |        | 
 *                                        `-------------'       `---------------'
 */
    [3] = LAYOUT(
  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  KC_CALC,  KC_NLCK, KC_PSLS,KC_PAST,KC_PMNS, 
  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  KC_P7,   KC_P8,  KC_P9,  KC_PPLS, 
  _______,  _______,  _______,  _______,  _______,  _______,                        _______,  _______,  KC_P4,   KC_P5,  KC_P6,  KC_PEQL, 
  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  KC_P1,   KC_P2,  KC_P3,  KC_PENT, 
  _______,  _______,  _______,                                                                                   KC_P0,  KC_PDOT,KC_PENT,
                                                    _______,  _______,    _______,  _______,  
                                                    _______,  _______,    _______,  _______
    ),
};

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {

}
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


