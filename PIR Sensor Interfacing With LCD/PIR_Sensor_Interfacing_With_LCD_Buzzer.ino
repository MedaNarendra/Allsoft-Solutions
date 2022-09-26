#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);
int PIR = 6;
int LED = 5;
int buzzer = 4;
void setup()
{
  lcd.begin(16, 2);
  lcd.setCursor(1, 0);
  lcd.print("SECURITY ALARM");
  lcd.setCursor(5, 1);
  lcd.print("SYSTEM");
  pinMode(PIR, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  delay(5000);
}
void loop(){
  //lcd.clear();
  if (digitalRead(PIR)){
    digitalWrite(LED, HIGH);
    tone(buzzer,988,1000);
    lcd.setCursor(2,0);
    lcd.print("ALARM ACTIVE");
  }
  else{
    digitalWrite(LED,LOW);
    tone(buzzer,0,100);
    lcd.clear();
  }
}
