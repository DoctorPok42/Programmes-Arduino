#include "Keyboard.h"

int b1 = 7;
int b2 = 8;
int b3 = 9;
int b4 = 10;

void setup() {
    pinMode(b1, INPUT_PULLUP);
    pinMode(b2, INPUT_PULLUP);
    pinMode(b3, INPUT_PULLUP);
    pinMode(b4, INPUT_PULLUP);
    Keyboard.begin();
}

void loop() {

    if(digitalRead(b1) == LOW) {
        Keyboard.press(KEY_LEFT_GUI);
        Keyboard.press('d');
        Keyboard.releaseAll();
        delay(250);
    }

     if(digitalRead(b2) == LOW) {
        Keyboard.press(KEY_LEFT_GUI);
        Keyboard.press('l');
        Keyboard.releaseAll();
        delay(250);
    }

      if(digitalRead(b3) == LOW) {
        Keyboard.press(KEY_LEFT_GUI);
        Keyboard.press('p');
        Keyboard.releaseAll();
        delay(250);
    }

       if(digitalRead(b4) == LOW) {
        Keyboard.press(KEY_LEFT_GUI);
        Keyboard.releaseAll('k');
        delay(500);
    }
}