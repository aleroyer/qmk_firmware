/* Copyright 2017 Wunder
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
#include "xd75.h"

// Layer shorthand
#define _QW 0
#define _FN 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* TYPEMATRIX QWERTY MAC OS
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      | DEL    | 6      | 7      | 8      | 9      | 0      | -      | =      | PG UP  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      | BACKSP | Y      | U      | I      | O      | P      | [      | ]      | PG DN  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | LSHIFT | A      | S      | D      | F      | G      | ENTER  | H      | J      | K      | L      | ;      | '      | `      | RSHIFT |
 * |        +--------+--------+--------+--------+--------+        +--------+--------+--------+--------+--------------------------+        |
 * |        | Z      | X      | C      | V      | B      |        | N      | M      | ,      | .      | /      | \      | UP     |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | CTRL   | ALT    | CMD    | FN     | SPACE  | SPACE  |        | SPACE  | SPACE  | ALGR   | HOME   | END    | LEFT   | DOWN   | RIGHT  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

    [_QW] = {
        /* QWERTY */
        {KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_DEL, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_PGUP},
        {KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_BSPACE, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_PGDOWN},
        {KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G, KC_ENTER, KC_H, KC_J, KC_K, KC_L, KC_SCOLON, KC_QUOTE, KC_GRV, KC_RSHIFT},
        {_______, KC_Z, KC_X, KC_C, KC_V, KC_B, _______, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_BSLASH, KC_UP, _______},
        {KC_LCTRL, KC_LALT, KC_LGUI, MO(_FN), KC_SPC, KC_SPC, _______, KC_SPC, KC_SPC, KC_ALGR, KC_HOME, KC_END, KC_LEFT, KC_DOWN, KC_RIGHT},
    },

    /* FUNCTION
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        | F1     | F2     | F3     | F4     | F5     | INSERT | F6     | F7     | F8     | F9     | F10    | F11    | F12    | PR SCR |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | PREV   | PLAY   | NEXT   | STOP   |        | VOL+   |        |        |        |        |        |        |        | SCR LK |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | CAPS   |        |        |        |        |        | VOL-   |        |        |        |        |        |        |        | PAUSE  |
 * |        +--------+--------+--------+--------+--------+        +--------+--------+--------+--------+--------+--------+--------+        |
 * |        |        | CUT    | COPY   | PASTE  |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        | FN     |        |        | MUTE   |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

    [_FN] = {
        /* FUNCTION */
        {_______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_INSERT, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_PSCREEN},
        {_______, KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, _______, KC_VOLU, _______, _______, _______, _______, _______, _______, _______, KC_SLCK},
        {KC_CAPS, _______, _______, _______, _______, _______, KC_VOLD, _______, _______, _______, _______, _______, _______, _______, KC_PAUSE},
        {_______, _______, KC_CUT, KC_COPY, KC_PASTE, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
        {_______, _______, _______, MO(_FN), _______, _______, KC_MUTE, _______, _______, _______, _______, _______, _______, _______, _______},
    }};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch (id)
  {
  case 0:
    if (record->event.pressed)
    {
      register_code(KC_RSFT);
#ifdef BACKLIGHT_ENABLE
      backlight_step();
#endif
    }
    else
    {
      unregister_code(KC_RSFT);
    }
    break;
  }
  return MACRO_NONE;
};

// led_set_user example - you could also turn these on/off in response
// to events in process_record_user or matrix_scan_user
void led_set_user(uint8_t usb_led)
{
  if (usb_led & (1 << USB_LED_CAPS_LOCK))
  {
    capslock_led_on();
  }
  else
  {
    capslock_led_off();
  }
}
