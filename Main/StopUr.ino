void StopUr()
{
  lcd.print("Stop Ur");
  delay(10);
  lcd.clear();
  int stopUrPage = 0;
  int encoderPlace = 0;
  int stopUrRunning = false;

  int minLeft = 0;
  int secLeft = 0;
  int startTime = 0;
  int minSlut = 0;
  int secSlut = 0;

  if (digitalRead(buttonPin) == HIGH)
  {
    encoder.write(0);
    stopUrRunning = true;
    stopUrPage = 1;
    lcd.print("...");
    delay(1000);
  }

  while (stopUrRunning == true)
  {
    encoderPlace = (encoder.read()/4) % 3;
    if (stopUrPage == 1)
    {
      lcd.print("tryk for start");
      delay(100);
      lcd.clear();
      if (digitalRead(buttonPin) == HIGH)
      {
        stopUrPage = 2;
        startTime = millis();
        delay(100);
      }
    }
    if (stopUrPage == 2)
    {
      int minLeft = (millis() - startTime) / 1000 / 60;
      int secLeft = ((millis() - startTime) / 1000) % 60;

      lcd.print("Tid gaaet");
      lcd.setCursor(0,1);
      lcd.print("Tid: ");
      lcd.print(minLeft);
      lcd.print(":");
      lcd.print(secLeft);
      delay(20);
      lcd.clear();
      if (digitalRead(buttonPin) == HIGH)
      {
        stopUrPage = 3;
        minSlut = minLeft;
        secSlut = secLeft;
        delay(500);
      }
    }
    if (stopUrPage == 3)
    {
      lcd.print("Slut:");
      lcd.setCursor(0,1);
      lcd.print("Tid gaaet: ");
      lcd.print(minSlut);
      lcd.print(":");
      lcd.print(secSlut);
      delay(20);
      lcd.clear();
      if (digitalRead(buttonPin) == HIGH)
      {
        stopUrRunning = false;
        stopUrPage = 0;
      }

    }
  }
}