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
  
  if(digitalRead(buttonPin) == HIGH)
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
      lcd.print(" sekunder");
      lcd.setCursor(0, 1);
      lcd.print("Tryk for start");
    }
    else if(guessTimePage == 1 && digitalRead(buttonPin) == HIGH)
    {
      timeStarted = millis() / 1000;
      Serial.print("Tid startet: ");
      Serial.println(timeStarted);
      delay(200);
      guessTimePage = 2;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Tryk naar tiden");
      lcd.setCursor(0, 1);
      lcd.print("er gaaet");
    }
    else if(guessTimePage == 2 && digitalRead(buttonPin) == HIGH)
    {
      delay(200);
      int timeGuessed = ((millis() / 1000) - timeStarted);
      guessTimePage = 3;
      Serial.print("Tid ved slut: ");
      Serial.println(millis() / 1000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Din tid: ");
      lcd.print(timeGuessed);
      lcd.print(" s");
      lcd.setCursor(0, 1);
      lcd.print("Afvigelse: ");
      lcd.print(abs(timeGuessed - timeToGuess));
    }

    if(guessTimePage == 3 && digitalRead(buttonPin) == HIGH)
    {
      Serial.println("Kører ikke");
      guessTimeRunning = false;
      delay(200);
    }
  }
}

