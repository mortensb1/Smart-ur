void GuessTime()
{
  //Variabler funktionen skal bruge
  int guessTimePage = 0;
  int guessTimeRunning = false;
  int timeStarted = 0;

  //Forsiaden til gæt tid spillet
  lcd.print("Guess time game!");
  delay(20);
  lcd.clear();
  
  //Hvis der trykkes går man ind på spillet
  if(IsButtonPressed())
  {
    guessTimeRunning = true;
    delay(200);
  }

  //Spillet kører når denne bool er sand
  while(guessTimeRunning == true)
  {
    //Vis første side hvor man får at vide hvor lang tid man skal gætte
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
    //Vis siden hvor man skal gætte sekunderne og derefter trykke når man tror tiden er gået
    else if(guessTimePage == 1 && IsButtonPressed())
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
    //Vis sammenligning af den tid man skulle gætte og den tid der er gået
    else if(guessTimePage == 2 && IsButtonPressed())
    {
      delay(200);
      int timeGuessed = ((millis() / 1000) - timeStarted);
      guessTimePage = 3;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Din tid: ");
      lcd.print(timeGuessed);
      lcd.print(" s");
      lcd.setCursor(0, 1);
      lcd.print("Afvigelse: ");
      lcd.print(abs(timeGuessed - 10)); // coden uder virker ikke
      // lcd.print(abs(timeGuessed - timeToGuess));
    }

    //Hvis man trykker går man tilbage til main
    if(guessTimePage == 3 && IsButtonPressed())
    {
      guessTimeRunning = false;
      delay(200);
    }
  }
}

