#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);
int trig_pin = 7;
int echo_pin = 6;
int LED = 5;
long distance, duration;

void setup()
{
  lcd.begin(16, 2);
  lcd.setCursor(2, 0);
  lcd.print("Ultrasonic ..");
  delay(2000);
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  pinMode(LED,OUTPUT);
}

void loop()
{
  Distance_Cal();
  lcd.setCursor(0,1);
  lcd.print(distance);
  lcd.print("cm");
  delay(100);
  
  if(distance<=200 && distance>100){
    digitalWrite(LED,HIGH);
    delay(1000);
    digitalWrite(LED,LOW);
    delay(1000);
  }
  if(distance<=100 && distance>50){
      digitalWrite(LED,HIGH);
      delay(500);
      digitalWrite(LED,LOW);
      delay(500);
  }
  if(distance<=50){
    digitalWrite(LED,HIGH);
    delay(100);
    digitalWrite(LED,LOW);
    delay(100);
  }
  else{digitalWrite(LED,LOW);}
} 

void Distance_Cal(){
  digitalWrite(trig_pin,HIGH);
  delayMicroseconds(20);
  digitalWrite(trig_pin,LOW);
  delayMicroseconds(20);

  duration = pulseIn(echo_pin, HIGH);
  distance= duration*0.01723;
}
