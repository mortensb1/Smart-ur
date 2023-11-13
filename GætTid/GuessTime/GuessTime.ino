

void setup(){
  pinMode(4, INPUT);
  Serial.begin(9600);
}

void loop(){
  GuessTime();
}

void GuessTime()
{
  int guessTimePage = 0;
  int guessTimeRunning = false;
  
  if(digitalRead(4) == HIGH)
  {
    guessTimeRunning = true;

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
