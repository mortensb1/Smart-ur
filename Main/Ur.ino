void Ur() {
  int timer, minutter, sekunder;  //variable

  DateTime now = rtc.now();

  timer = now.hour();
  minutter = now.minute();
  sekunder = now.second();

  // Serial.println(now.minute());
  // Serial.println(now.minute());
  // Serial.printin(now.hour());
  // Serial.printin(now.second());


  lcd.setCursor(0, 0);
  lcd.print("Klokken: ");
  lcd.setCursor(0, 1);
  lcd.print((timer < 10) ? "0" : "");  //tilføj en 0 hvis det er enkelt cifre.
  lcd.print(timer);
  lcd.print(":");
  lcd.print((minutter < 10) ? "0" : "");  // tilføj en 0 hvis det er enkelt cifre
  lcd.print(minutter);
  lcd.print(":"); 
  lcd.print((sekunder < 10) ? "0" : "");  // tilføj en 0 hvis det er enkelt cifre
  lcd.print(sekunder);


  delay(1000);  // Her sker det en delay, som gøre sådan at den her loop kan læses, i den her tilfælde er det 1000 millisekund  hvilket betyder at displayet updates hver sekund
  lcd.clear();
}