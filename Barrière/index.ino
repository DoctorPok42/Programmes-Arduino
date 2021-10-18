#include <Servo.h>

Servo barriere;
int bp = 2; // Le bouton qui remplace le lecteur de badge
int LDR = A0;
const int ouvre=90;
const int ferme=0;

void setup() {
  pinMode(bp, INPUT);
  barriere.attach(3);
  barriere.write(ferme);
}

void loop() {
  int n = analogRead(LDR); // On lit la valeur de la LDR et on l'atribut à n
  
  if (digitalRead(bp) == HIGH && n < 250) { // Si le badge et la voiture sont présents 
    barriere.write(ouvre);
  }

  else if (n > 250) {
    delay(1000);
    barriere.write(ferme);
  }
}
