bool IsButtonPressed()
{
  if(digitalRead(buttonPin) == LOW && encoder.read() % 4 == 0)
  {
    delay(100);
    return true;
  }
  return false;
}