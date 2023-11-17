#include <Encoder.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

Encoder encoder(2, 3);

void Ur();
void StopUr();
void GuessTime();
void EggTimer();

void (*funktionsListe[4])() = {Ur, StopUr, GuessTime, EggTimer};

int encoderCount = 0;
int buttonPin = 4;

void setup()
{
  pinMode(4, INPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop()
{
  encoderCount = encoder.read()/4;
  if (encoderCount > 3)
  {
    encoder.write(0);
    encoderCount = encoder.read()/4;
  }
  Serial.println(encoderCount);
  funktionsListe[encoderCount]();
}


void Ur()
{
  lcd.print("Ur");
  delay(10);
  lcd.clear();
}

void StopUr()
{
  lcd.print("StopUr");
  delay(10);
  lcd.clear();
}
