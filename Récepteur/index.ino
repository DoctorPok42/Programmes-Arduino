#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

int c=0;
int l=1;
String message="";
bool p=true;
long tp;
int tm;

void setup()
{
    Serial.begin(9600);
    lcd.begin(16, 2);
    lcd.setCursor(0, 0);
    lcd.print("Attente message");
    lcd.setCursor(0,0);    
}

void loop()
{      
    if(Serial.available())
    {
      if(p) 
      {
        tp=millis(); //mémorisation de l'instant du premier caractère reçu
        p=false;
        tm=0;
      }
      message+=(char)Serial.read(); 
      tm++;     
    }
    if(!p && (millis()>tp+100)) //Si 100 ms écoulées depuis premier reçu
    {  
      while(1)
      {
        lcd.clear();
        c=0;
        l=0;
        lcd.setCursor(c,l);
        for (int i=0; i<tm; i++)
        {
          lcd.print(message[i]);
          delay(100);
          c++;
          if(c==16)
          {
            c=0;
            l=!l;
            lcd.setCursor(c,l);
          }
        }
        delay(5000);        
      }
    }      
}