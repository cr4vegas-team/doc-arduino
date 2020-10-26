#include <Arduino.h>


int pin_contador = 6;
int lectura_contador = false;
double lectura;
bool tomada = false;
long m1;
long m2;
long mt;
int st;
int K = 100;



void setup() {
  Serial.begin(9600);
  pinMode(pin_contador, INPUT);
  m1 = millis();
}

void loop() {

    lectura_contador = digitalRead(pin_contador);
     if(lectura_contador == LOW) {
      if(tomada == false) {
         m2 = millis();
         mt = m2 - m1;
         st = mt / 1000;
         lectura = K / st;
         //lectura = (100 / lectura);
         //lectura = (1 / lectura);
         tomada = true;
         
         Serial.println("==================================");
         Serial.println("Tiempo 1: " + String(m1));
         Serial.println("Tiempo 2: " + String(m2));
         m1=m2;
         Serial.println("Millis transcurridos: " + String(mt));
         Serial.println("Caudal: " + String(lectura) + " l/s");
         
      }

     } else {
      tomada = false;
     }
     delay(10);
     

}