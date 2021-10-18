int a, b =- 1, n = 0;

void setup() {
  randomSeed(analogRead(A0));
  a = random(0, 100); // nombre aléatoire entre 0 et 100
  Serial.begin(9600);
}

void loop() {
  while(a != b) {
    
    b = lirenombre("Saisir un nombre : ");
    n = n + 1;
    if (b > a) Serial.println(" Trop grand");
    if (b < a) Serial.println(" Trop petit");
  }

  Serial.print("Gagne en ");
  Serial.print(n);
  Serial.println(" coups");
  while(1);
}

// La fonction ci-dessous permet de lire un nombre via le moniteur série
int lirenombre(String message) {
  String saisie = "";
  Serial.print(message);
  while (Serial.available() == 0);
  while (Serial.available() > 0) {

    char caractere = Serial.read();
    delay(1);
    if(isDigit(caractere)) saisie = saisie + caractere; 
  }

  int nombre = saisie.toInt();
  Serial.print(nombre);
  return nombre;
}
