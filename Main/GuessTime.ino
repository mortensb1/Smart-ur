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
  
  if(digitalRead(4) == HIGH)
  {
    guessTimeRunning = true;
    lcd.print("Gæt tid spillet!")
    Serial.println("Kører");
    delay(200);
  }

  while(guessTimeRunning == true)
  {
    if(guessTimePage == 0 && digitalRead(4) == HIGH)
    {
      Serial.println("Kører ikke");
      guessTimeRunning = false;
      delay(200);
    }
  }
}
