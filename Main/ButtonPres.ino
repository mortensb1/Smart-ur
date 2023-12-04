bool IsButtonPressed()
{
  if(digitalRead(buttonPin) == LOW && digitalRead(buttonPin) % 4 == 0)
  {
    return true;
  }
  return false;
}