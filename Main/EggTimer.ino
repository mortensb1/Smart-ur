void EggTimer()
{
  int eggPage = 0;
  int encoderPlace = 0;
  int eggTimerRunning = false;
  int eggBoilingTime = 0;

  lcd.print("Eggetimer");
  Serial.println(eggTimerRunning);
  delay(20);
  lcd.clear();

  if(digitalRead(buttonPin) == HIGH && eggPage == 0)
  {
    encoder.write(0);
    eggTimerRunning = true;
    eggPage = 1;
  }

  while(eggTimerRunning == true)
  {
    encoderPlace = (encoder.read()/4) % 3;
    if(eggPage == 1)
    {
      if(encoderPlace == 0)
      {
        lcd.print("Bloedkogt aeg");
        delay(20);
        lcd.clear();
        eggBoilingTime = 5;
      }
      else if(encoderPlace == 1)
      {
        lcd.print("Smilende aeg");
        delay(20);
        lcd.clear();
        eggBoilingTime = 7;
      }
      else if(encoderPlace == 2)
      {
        lcd.print("Haardkogt aeg");
        delay(20);
        lcd.clear();
        eggBoilingTime = 9;
      }

      if(digitalRead(buttonPin) == HIGH && eggPage == 1)
      {
        eggPage = 2;
      }
    }

    if(eggPage == 2)
    {
      lcd.print(eggBoilingTime);
      delay(20);
      lcd.clear();
    }
  }
}
