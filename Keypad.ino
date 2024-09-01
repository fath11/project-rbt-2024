/* @file MultiKey.ino
|| @version 1.0
|| @author Mark Stanley
|| @contact mstanley@technologist.com
||
|| @description
|| | The latest version, 3.0, of the keypad library supports up to 10
|| | active keys all being pressed at the same time. This sketch is an
|| | example of how you can get multiple key presses from a keypad or
|| | keyboard.
|| #
*/

#include <Keypad.h>

const byte ROWS = 4;
const byte COLS =4;
char keys[ROWS][COLS] = {
{'1','5','9','d'}, //12-8, 12-7
{'2','6','a','e'}, //11-7
{'3','7','b','f'},
{'4','8','c','g'}
};

byte rowPins[ROWS] = {12, 11, 10, 9};
byte colPins[COLS] = {8, 7, 6, 5};

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

unsigned long loopCount;
unsigned long startTime;
String msg;

void setup() {
  Serial.begin(9600);
}

void loop() {
    // Fills kpd.key[ ] array with up-to 10 active keys.
    // Returns true if there are ANY active keys.
  if (kpd.getKeys()) {
    for (int i=0; i<LIST_MAX; i++) {
      if ( kpd.key[i].stateChanged ) {
        switch (kpd.key[i].kstate) {  // Report active key state : IDLE, PRESSED, HOLD, or RELEASED
          case PRESSED:
            msg = " PRESSED.";
          break;
          
          case HOLD:
            msg = " HOLD.";
          break;
          
          case RELEASED:
            msg = " RELEASED.";
          break;

          case IDLE:
            msg = " IDLE.";
        }
        Serial.print("Key ");
        Serial.print(kpd.key[i].kchar);
        Serial.println(msg);
      }
    }
  }
}