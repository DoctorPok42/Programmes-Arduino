#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // La longueur de l'écran, en pixels
#define SCREEN_HEIGHT 64 // La hauteur de l'écran, en pixels

// Declaration d'un objet de type Adafruit_SSD1306
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int bp1 = 2;
int bp2 = 3;
long val10;

void setup() {
    pinMode(bp1, INPUT);
    pinMode(bp2, INPUT);

    Serial.begin(115200);

    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println(F("SSD1306 allocation failed"));
        for(;;);
    }
    delay(2000);
    display.clearDisplay();
}

void loop () {
    if (digitalRead(bp1) == HIGH) {
        val10 = val10 + 1;
    }

    if (digitalRead(bp2) == HIGH) {
        val10 = val10 - 1;
    }

    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.println(val10);

    display.setCursor(30, 0);
    display.println(val10, BIN);
    display.display();
    delay(100);
}
