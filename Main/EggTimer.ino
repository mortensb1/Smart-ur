void EggTimer()
{
  int eggPage = 0;
  int encoderPlace = 0;
  int eggTimerRunning = false;
  int eggBoilingTime = 0;
  long startTime = 0;

  lcd.print("Eggetimer");
  delay(20);
  lcd.clear();

  if(digitalRead(buttonPin) == HIGH)
  {
    encoder.write(0);
    eggTimerRunning = true;
    eggPage = 1;
    lcd.print("...");
    delay(1000);
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

      if(digitalRead(buttonPin) == HIGH)
      {
        eggPage = 2;
        startTime = millis();
        delay(100);
      }
    }

    if(eggPage == 2)
    {
      int minLeft = (millis() - startTime) / 1000 / 60;
      int secLeft = ((millis() - startTime) / 1000) % 60;

      lcd.print("Bloedkogt: ");
      lcd.print(eggBoilingTime);
      lcd.print(" min");
      lcd.setCursor(0, 1);
      lcd.print("Tid: ");
      lcd.print(minLeft);
      lcd.print(":");
      lcd.print(secLeft);
      delay(20);
      lcd.clear();
      if (digitalRead(buttonPin) == HIGH)
      {
        eggTimerRunning = false;
      }
    }
  }
}
