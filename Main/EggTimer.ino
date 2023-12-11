void EggTimer()
{
  //Variabler som bruges til funktionen
  int eggPage = 0;
  int encoderPlace = 0;
  int eggTimerRunning = false;
  int eggBoilingTime = 0;
  long startTime = 0;

  //"Forside" for eggetimeren
  lcd.print("Eggetimer");
  delay(20);
  lcd.clear();

  //Starter funktionen hvis der trykkes
  if(IsButtonPressed())
  {
    encoder.write(0);
    eggTimerRunning = true;
    eggPage = 1;
    lcd.print("...");
    delay(100);
  }

  //Eggetimeren kører mens denne bool er sand
  while(eggTimerRunning == true)
  {
    //Aflæs encoderens position, som kan være 0, 1 eller 2
    encoderPlace = (encoder.read()/4) % 3;
    if(eggPage == 1)
    {
      //Blødkogt æg vises
      if(encoderPlace == 0)
      {
        lcd.print("Bloedkogt aeg");
        delay(20);
        lcd.clear();
        eggBoilingTime = 5;
      }
      //Smilende æg vises
      else if(encoderPlace == 1)
      {
        lcd.print("Smilende aeg");
        delay(20);
        lcd.clear();
        eggBoilingTime = 7;
      }
      //Hårdkogt æg vises
      else if(encoderPlace == 2)
      {
        lcd.print("Haardkogt aeg");
        delay(20);
        lcd.clear();
        eggBoilingTime = 9;
      }

      //Når der trykkes vælges det æg som man har scrollet hen på
      if(IsButtonPressed())
      {
        eggPage = 2;
        startTime = millis();
        delay(100);
      }
    }

    //Siden der skal vises når man har valgt et slags æg
    if(eggPage == 2)
    {
      int minLeft = (millis() - startTime) / 1000 / 60;
      int secLeft = ((millis() - startTime) / 1000) % 60;

      //Viser tiden der skal gå, og hvor langt tid der er gået
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

      //Hvis man trykker går man tilbage til main
      if (IsButtonPressed())
      {
        eggTimerRunning = false;
      }

      //Hvis tiden er gået skal den bippe
      if(minLeft >= eggBoilingTime)
      {
        lcd.clear();
        lcd.print("Hold knappen inde");
        lcd.setCursor(0,1);
        lcd.print("for at stoppe");
        digitalWrite(buzzerPin, HIGH);
        delay(500);
        digitalWrite(buzzerPin, LOW);
        delay(480);
      }
    }
  }
}
