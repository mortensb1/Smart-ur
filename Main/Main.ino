#include <Encoder.h>
#include "rgb_lcd.h"
#include "RTClib.h"  // bruges til at præsentere date og time information
#include <DS1307.h>
#include <Wire.h>

RTC_DS1307 rtc;

rgb_lcd lcd;

Encoder encoder(3, 4);

void Ur();
void StopUr();
void GuessTime();
void EggTimer();

void (*funktionsListe[4])() = {Ur, StopUr, GuessTime, EggTimer};

int encoderCount = 0;
int buttonPin = 2;
int buzzerPin = 8;

void setup()
{
  pinMode(buttonPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

  lcd.begin(16, 2);
  rtc.begin();
}

void loop()
{
  EncoderRead();

  funktionsListe[encoderCount]();
}

