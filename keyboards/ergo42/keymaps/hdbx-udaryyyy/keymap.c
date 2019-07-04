// WindowsでJIS配列として認識しているときに、US配列として使うためのキーマップ
// @leopard_gecko さんがPlanck用に作成されたキーマップをかなり参考にしています。

#include QMK_KEYBOARD_H
#include "keymap_jp.h"       // qmk_firmware-master/quantum/keymap_extras/keymap_jp.h 日本語キーボード設定用
#include <sendstring_jis.h>  // macro sendstring for jis keyboard マクロ文字列送信時に日本語キーボード設定での文字化け回避

extern keymap_config_t keymap_config;

// レイヤー
#define BASE 0
#define NUMERIC 1
#define WITH_FUNC 2
#define _ADJUST 3

enum custom_keycodes {
  MCR1 = SAFE_RANGE,   // マクロ1
  MCR2,                // マクロ2
  MCR3,                // マクロ3
  DYNAMIC_MACRO_RANGE, // ダイナミックマクロ
  WN_SCLN,             // タップでJISの「:」  シフトでJISの「;」 (Windows)
};

// Use Dynamic macro
#include "dynamic_macro.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = LAYOUT( \
    KC_ESC,   KC_Q,          KC_W,        KC_E,    KC_R,    KC_T,     MCR1   ,      /*|*/ MCR2,         KC_Y,     KC_U,     KC_I,    KC_O,     KC_P,     KC_MINS, \
    KC_TAB,   KC_A,          KC_S,        KC_D,    KC_F,    KC_G,     KC_LPRN,      /*|*/ KC_RPRN,      KC_H,     KC_J,     KC_K,    KC_L,     KC_SCLN,  KC_QUOT, \
    KC_LSFT,  KC_Z,          KC_X,        KC_C,    KC_V,    KC_B,     TO(NUMERIC),  /*|*/ LALT(KC_GRV), KC_N,     KC_M,     KC_COMM, KC_DOT,   KC_UP,    KC_SLSH, \
    KC_LCTL,  MO(WITH_FUNC), MO(NUMERIC), KC_LALT, KC_DEL,  KC_SPACE, KC_UNDS,      /*|*/ KC_BSPC,      KC_SPACE, KC_SPACE, KC_ENT,  KC_LEFT,  KC_DOWN,  KC_RIGHT  \
  ),

  [NUMERIC] = LAYOUT( \
    KC_ESC,   KC_1,      KC_2,      KC_3,    KC_4,    KC_5,     KC_PSCR,      /*|*/ KC_6,      KC_7,    KC_8,    KC_9,     KC_0,     KC_PMNS, KC_PPLS, \
    KC_TAB,   KC_A,      KC_S,      KC_D,    KC_F,    KC_G,     KC_LBRC,      /*|*/ KC_RBRC,   KC_4,    KC_5,    KC_6,     XXXXXXX,  KC_PSLS, KC_PAST, \
    KC_LSFT,  KC_Z,      KC_X,      KC_C,    KC_V,    KC_B,     TO(BASE),     /*|*/ KC_DOT,    KC_1,    KC_2,    KC_3,     XXXXXXX,  KC_UP,   KC_BSLS, \
    _______,  _______,   _______,   _______, _______, _______,  _______,      /*|*/ _______,   KC_0,    KC_0,    KC_ENT,   KC_LEFT,  KC_DOWN, KC_RIGHT \
  ),

  [WITH_FUNC] = LAYOUT( \
    XXXXXXX,  XXXXXXX,       XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX,  KC_PSCR,      /*|*/ XXXXXXX,     KC_F7,    KC_F8,   KC_F9,      KC_F10,        KC_F11,  KC_F12,  \
    XXXXXXX,  XXXXXXX,       XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,      /*|*/ XXXXXXX,     KC_F4,    KC_F5,   KC_F6,      XXXXXXX,       XXXXXXX, TO(_ADJUST), \
    XXXXXXX,  XXXXXXX,       XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,      /*|*/ XXXXXXX,     KC_F1,    KC_F2,   KC_F3,      XXXXXXX,       XXXXXXX, XXXXXXX, \
    XXXXXXX,  _______,       XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,      /*|*/ XXXXXXX,     XXXXXXX,  XXXXXXX, XXXXXXX,    XXXXXXX,       XXXXXXX, KC_RGUI  \
  ),

  [_ADJUST] = LAYOUT( \
    RGB_TOG,  MCR1,    MCR2,    MCR3,    XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, DYN_MACRO_PLAY1, DYN_MACRO_PLAY2, DYN_REC_START1, DYN_REC_START2, DYN_REC_STOP, KC_BSPC, \
    RESET,    RGB_MOD, RGB_M_P, RGB_M_B, RGB_HUI, RGB_SAI, RGB_VAI,   XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,   XXXXXXX, XXXXXXX, TO(BASE), \
    KC_LSFT,  RGB_M_R, RGB_M_SN,RGB_M_G, RGB_HUD, RGB_SAD, RGB_VAD,   XXXXXXX, KC_MPLY, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPRV, KC_MNXT, \
    DEBUG,    XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
  ),

};

// RGB Underglow使用時のレイヤー毎のカラー切り替え
uint32_t layer_state_set_keymap (uint32_t state) {
  return state;
}

void matrix_init_user(void) {
#ifdef RGBLIGHT_ENABLE
  rgblight_enable();
  rgblight_setrgb_teal();
#endif
}

uint32_t layer_state_set_user(uint32_t state) {
  state = update_tri_layer_state(state, BASE, NUMERIC, WITH_FUNC);
#ifdef RGBLIGHT_ENABLE
    switch (biton32(state)) {
    case BASE:
      rgblight_setrgb_chartreuse(); // シャルトリューズ
      break;
    case NUMERIC:
      rgblight_setrgb_pink(); // ピンク
      break;
    case WITH_FUNC:
      rgblight_setrgb_red(); // レッド
      break;
    default: //  for any other layers, or the default layer
      rgblight_setrgb_teal(); // 他:ティール
      break;
    }
#endif
return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static bool     lshift = false;
  if (!process_record_dynamic_macro(keycode, record)) {
      return false;
  }
  switch (keycode) {
    case BASE:
      if (record->event.pressed) {
        set_single_persistent_default_layer(BASE);
      }
      return false;
      break;
    case WN_SCLN: // コロン「;:」
      if (record->event.pressed) {
        lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
        if (lshift) {
          unregister_code(KC_LSFT);
          register_code(JP_SCLN);
          unregister_code(JP_SCLN);
        } else {
          register_code(JP_COLN);
          unregister_code(JP_COLN);
        }
      }
      return false;
      break;
    case MCR1:
      if (record->event.pressed) {
        SEND_STRING("itsumoosewaninatteorimasu."); // 送信文字列
      }
      return false;
      break;
    case MCR2:
      if (record->event.pressed) {
        SEND_STRING("ijoutonarimasu." ); // 送信文字列
      }
      return false;
      break;
    case MCR3:
      if (record->event.pressed) {
        SEND_STRING("ijoutonarimasu.");// 送信文字列
      }
      return false;
      break;
  }
  return true;
}
