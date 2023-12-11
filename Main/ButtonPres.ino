//Funktion som tjekker om der trykkes på knappen og giver lyd
bool IsButtonPressed()
{
  if(digitalRead(buttonPin) == LOW && encoder.read() % 4 == 0)
  {
    if (buttonHasBeenPressed == false)
    {
      digitalWrite(buzzerPin, HIGH);
      delay(100);
      digitalWrite(buzzerPin, LOW);
      buttonHasBeenPressed = true;
      return true;
    }
  }
  if (digitalRead(buttonPin) == HIGH)
  {
    buttonHasBeenPressed = false;
  }
  return false;
}