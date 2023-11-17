// #include "rgb_lcd.h"

// rgb_lcd lcd;

// void setup(){
//   pinMode(4, INPUT);
//   Serial.begin(9600);
//   lcd.begin(16, 2);
// }

// void loop(){
//   GuessTime();
// }

void GuessTime()
{
  int guessTimePage = 0;
  int guessTimeRunning = false;
  int timeStarted = 0;

  lcd.print("Guess time game!");
  delay(20);
  lcd.clear();
  
  if(digitalRead(4) == HIGH)
  {
    guessTimeRunning = true;
    delay(200);
  }

  while(guessTimeRunning == true)
  {
    if(guessTimePage == 0)
    {
      delay(200);
      int timeToGuess = random(2, 40);
      guessTimePage = 1;
      lcd.clear();
      lcd.setCursor(3, 0);
      lcd.print(timeToGuess);
      lcd.print(" seconds");
      lcd.setCursor(0, 1);
      lcd.print("Press to start");
    }
    else if(guessTimePage == 1 && digitalRead(4) == HIGH)
    {
      timeStarted = millis() / 1000;
      Serial.print("Tid startet: ");
      Serial.println(timeStarted);
      delay(200);
      guessTimePage = 2;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Press to guess when");
      lcd.setCursor(0, 1);
      lcd.print("the time is up");
    }
    else if(guessTimePage == 2 && digitalRead(4) == HIGH)
    {
      delay(200);
      int timeGuessed = ((millis() / 1000) - timeStarted);
      guessTimePage = 3;
      Serial.print("Tid ved slut: ");
      Serial.println(millis() / 1000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(timeGuessed);
    }

    if(guessTimePage == 3 && digitalRead(4) == HIGH)
    {
      Serial.println("Kører ikke");
      guessTimeRunning = false;
      delay(200);
    }
  }
}

