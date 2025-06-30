/* Original by Salicylic-acid3
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
#include "keymap_japanese.h"
#include "os_detection.h"
#ifdef CONSOLE_ENABLE
    #include <print.h>
#endif

// レイヤー定義 とりあえず0〜4を列挙
enum layers {
    _LAYER0,    // 通常入力用のレイヤー = 0
    _LAYER1,    // 数字・記号入力用のレイヤー = 1
    _LAYER2,    //
    _LAYER3,    //
    _LAYER4,    // Mac/iOS用のレイヤー = 4
};

//Override definitions
//These JIS keycodes have been overridden to emulate pseudo-US layout
const key_override_t jp2_key_override    = ko_make_basic(MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT), JP_2,    JP_AT);
const key_override_t jp6_key_override    = ko_make_basic(MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT), JP_6,    JP_CIRC);
const key_override_t jp7_key_override    = ko_make_basic(MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT), JP_7,    JP_AMPR);
const key_override_t jp8_key_override    = ko_make_basic(MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT), JP_8,    JP_ASTR);
const key_override_t jp9_key_override    = ko_make_basic(MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT), JP_9,    JP_LPRN);
const key_override_t jp0_key_override    = ko_make_basic(MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT), JP_0,    JP_RPRN);
const key_override_t jpunds_key_override = ko_make_basic(MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT), JP_MINS, JP_UNDS);
const key_override_t jpplus_key_override = ko_make_basic(MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT), JP_CIRC, JP_PLUS);
const key_override_t jpeql_key_override  = ko_make_basic(0,                                   JP_CIRC, JP_EQL);
const key_override_t jpcoln_key_override = ko_make_basic(MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT), JP_SCLN, JP_COLN);
const key_override_t jpdquo_key_override = ko_make_basic(MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT), JP_COLN, JP_DQUO);
const key_override_t jpquot_key_override = ko_make_basic(0,                                   JP_COLN, JP_QUOT);
const key_override_t jptild_key_override = ko_make_basic(MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT), JP_ZKHK, JP_TILD);
const key_override_t jpgrv_key_override  = ko_make_basic(0,                                   JP_ZKHK, JP_GRV);
const key_override_t jp1_key_override    = ko_make_basic(MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT), JP_1,    JP_TILD);
const key_override_t jpcomm_key_override = ko_make_basic(MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT), JP_COMM, S(JP_1));
const key_override_t jpslsh_key_override = ko_make_basic(MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT), JP_DOT,  S(JP_SLSH));
const key_override_t jprabk_key_override = ko_make_basic(MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT), JP_BSLS, JP_RABK);
const key_override_t jplabk_key_override  = ko_make_basic(0,                                  JP_BSLS, JP_LABK);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
	&jp2_key_override,
	&jp6_key_override,
	&jp7_key_override,
	&jp8_key_override,
	&jp9_key_override,
	&jp0_key_override,
	&jpunds_key_override,
	&jpplus_key_override,
	&jpeql_key_override,
	&jpcoln_key_override,
	&jpdquo_key_override,
	&jpquot_key_override,
	&jptild_key_override,
	&jpgrv_key_override,
	&jp1_key_override,
	&jpcomm_key_override,
	&jpslsh_key_override,
    &jprabk_key_override,
	&jplabk_key_override
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, KC_LCBR,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_DEL,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G, KC_SCLN,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_MINS,    KC_N,    KC_M, KC_COMM,  KC_DOT,   KC_UP,   MO(1),
        KC_LCTL, KC_LGUI, KC_LALT,KC_LNG1,    KC_SPC,    KC_SPC,     KC_SPC,    KC_SPC, KC_LNG2, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [1] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,   _______,   _______, _______,   _______,    _______, _______, _______, _______
    ),
    [2] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,   _______,   _______, _______,   _______,    _______, _______, _______, _______
    ),
    [3] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,   _______,   _______, _______,   _______,    _______, _______, _______, _______
    ),
    [4] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,   _______,   _______, _______,   _______,    _______, _______, _______, _______
    ),
    [5] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,   _______,   _______, _______,   _______,    _______, _______, _______, _______
    ),
    [6] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,   _______,   _______, _______,   _______,    _______, _______, _______, _______
    )
};

// Host OS detection
// If Host OS is either macOS or iOS, activate _LAYER4
// Do nothing for the others. Just move to the default layer.
void keyboard_post_init_user(void) {
    wait_ms(400);
    switch (detected_host_os()) {
    case OS_MACOS:
        layer_on(_LAYER4);
        break;
    case OS_IOS:
        layer_on(_LAYER4);
        break;
    default:
        layer_move(_LAYER0);
        break;
    }
}
