#define RED_LED 3

void setup() {
   // initialise les broches
   pinMode(RED_LED, OUTPUT);
}

void loop() {
   for(int i=0; i<=255; i++) {
      analogWrite(RED_LED, i);
      delay(10);
   }

   for(int i=255; i>=0; i--) {
      analogWrite(RED_LED, i);
      delay(10);
   }
}