#include <Encoder.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

Encoder encoder(2, 3);

void Ur();
void StopUr();
void GuessTime();
void KogEg();

void (*funktionsListe[4])() = {Ur, StopUr, GuessTime, KogEg};

int encoderCount = 0;

void setup()
{
  lcd.begin(16, 2);
}

void loop()
{
  encoderCount = encoder.read()/4;
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

void KogEg()
{
  lcd.print("KogEg");
  delay(10);
  lcd.clear();
}
