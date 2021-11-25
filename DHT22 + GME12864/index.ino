#include <DHT.h>
#define brocheDeBranchementDHT 6 // Branche du DHT22
#define typeDeDHT DHT22

DHT dht(brocheDeBranchementDHT, typeDeDHT);

// ---------------

#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>


#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// ---------------

void setup () {
    Serial.begin(115200);

    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
      Serial.println(F("SSD1306 allocation failed"));
      for(;;);
    }
    delay(250);
    display.clearDisplay();

    // Initialisation du DHT22;
    dht.begin();
}

void loop () {
  
  // Lecture des données
  float tauxHumidite = dht.readHumidity();              // Lecture du taux d'humidité (en %)
  float temperatureEnCelsius = dht.readTemperature();   // Lecture de la température, exprimée en degrés Celsius

  // Vérification si données bien reçues
  if (isnan(tauxHumidite) || isnan(temperatureEnCelsius)) {
    Serial.println("Aucune valeur retournée par le DHT22. Est-il bien branché ?");
    delay(2000);
    return;         // Si aucune valeur n'a été reçue par l'Arduino, on attend 2 secondes, puis on redémarre la fonction loop()
  }

  // Calcul de la température ressentie
  float temperatureRessentieEnCelsius = dht.computeHeatIndex(temperatureEnCelsius, tauxHumidite, false); // Le "false" est là pour dire qu'on travaille en °C, et non en °F

  
/*  Serial.print("Humidité = "); Serial.print(tauxHumidite); Serial.println(" %");
  Serial.print("Température = "); Serial.print(temperatureEnCelsius); Serial.println(" °C");
  Serial.print("Température ressentie = "); Serial.print(temperatureRessentieEnCelsius); Serial.println(" °C");
  Serial.println();*/

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
    display.setCursor(0, 0);
  // Display static text
  display.println("Humidite :");


  display.setTextSize(1);
  display.setCursor(0, 10);
  display.print(tauxHumidite);
  display.println(" %");
  display.display(); 

// -----------------

  display.setTextSize(1);
  display.setTextColor(WHITE);
    display.setCursor(0, 23);
  // Display static text
  display.println("Temperature :");


  display.setTextSize(1);
  display.setCursor(0, 33);
  display.print(temperatureEnCelsius);
  display.println(" C");
  display.display(); 

// -----------------

  display.setTextSize(1);
  display.setTextColor(WHITE);
    display.setCursor(0, 47);
  // Display static text
  display.println("Temperature ressentie :");


  display.setTextSize(1);
  display.setCursor(0, 57);
  display.print(temperatureRessentieEnCelsius);
  display.println(" C");
  display.display();

  
  // Délais de 3 secondes (pour rappel : il ne faut pas essayer de faire plus d'1 lecture toutes les 2 secondes, avec le DHT22, selon le fabricant)
  delay(3000);
}