//Funktion som tjekker om der trykkes på knappen og giver lyd
bool IsButtonPressed()
{
  if(digitalRead(buttonPin) == LOW && encoder.read() % 4 == 0)
  {
    digitalWrite(buzzerPin, HIGH);
    delay(200);
    digitalWrite(buzzerPin, LOW);
    return true;
  }
  return false;
}