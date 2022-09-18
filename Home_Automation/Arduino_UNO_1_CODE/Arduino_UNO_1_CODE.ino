#include <DHT.h>
#include <LiquidCrystal_I2C.h>
#include<Keypad.h>
#include<Servo.h>
#include<Wire.h>
#include<SparkFunMLX90614.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo myservo;
IRTherm therm;

#define LED_RED 11 //Main door Red_LED
#define LED_GREEN 12 //Main door Green_LED

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET    -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define DHTPIN 10
#define DHTTYPE DHT22
DHT dht(DHTPIN,DHTTYPE);

#define codeLength 5
char Code[codeLength]; //define code length
char pswd[codeLength]="A1B2"; //Change your password here 
byte keycount=0;
const byte ROWS=4;
const byte COLS=4;

char hexakeys[ROWS][COLS]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}};


byte rowPins[ROWS]={2,3,4,5};
byte colPins[COLS]={6,7,8,9};

Keypad customKeypad=Keypad(makeKeymap(hexakeys),rowPins,colPins,ROWS,COLS);

void setup() {
  Serial.begin(9600);
  Wire.begin();
  
  pinMode(LED_RED,OUTPUT);
  pinMode(LED_GREEN,OUTPUT);
  red();
  
  dht.begin();
  therm.begin();
  therm.setUnit(TEMP_F);
  myservo.attach(A0);       //attach servo motor to A0
  myservo.write(130);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //Start the OLED display
  display.clearDisplay();
  display.display();
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("HOME AUTOMATION"); 
}

void loop() { 
  char customkey=customKeypad.getKey();
  if(customkey){
    Code[keycount]=customkey;
    Serial.print(Code[keycount]);
    lcd.setCursor(keycount,1);
    lcd.print(Code[keycount]);
    keycount++;
  }
  door_system();
  DHT22_OLED();
}

void door_system(){
    if(keycount==codeLength-1){
    Serial.println(" ");
    lcd.print(" ");

    if(!strcmp(Code,pswd)){
      Serial.println("PASSWORD CORRECT");
      lcd.clear();
      lcd.setCursor(0,1);
      lcd.print("  WELCOME HOME  ");
      delay(1000);
      lcd.clear();
      if (therm.read()){                  // On success, read() will return 1, on fail 0.
        Serial.print("Object: " + String(therm.object(), 2));
        Serial.println("F");
        Serial.print("Ambient: " + String(therm.ambient(), 2));
        Serial.println("F");
        Serial.println();
        Serial.println(String(therm.object(), 2));
    
        if (therm.object()>=90 && therm.object()<=95){
          myservo.write(0);           //unlock
          green();
          delay(8000);
          myservo.write(130);        //auto lock the door after 8secs.
          red();
        }
      }
   }
    else{
      Serial.println("PASSWORD INCORRECT");
      myservo.write(130);
      red();
      lcd.clear();
      lcd.setCursor(0,1);
      lcd.print("  NOT ALLOWED  ");
      delay(1000);
      lcd.clear();
    }
  deleteCount();
 }
}

void DHT22_OLED(){
  float h= dht.readHumidity();
  float t= dht.readTemperature(); 
  display.clearDisplay();
  display.setTextSize(1);                    
  display.setTextColor(WHITE);             
  display.setCursor(0,4);                
  display.println("TEMP"); 
  
  display.setTextSize(2);
  display.setCursor(50,0);
  display.println(dht.readTemperature(),1);
 
  display.setCursor(110,0);
  display.println("C");
  
  display.setTextSize(1);                    
  display.setTextColor(WHITE);             
  display.setCursor(0,20);                
  display.println("HUMI"); 
  
  display.setTextSize(2);
  display.setCursor(50,17);
  display.println(dht.readHumidity(),1);
  
  display.setCursor(110,17);
  display.println("%");
  
  display.display();
}

void deleteCount(){
  while(keycount != 0){
    Code[keycount--]=0;
  }
  return;
}

void red(){
  digitalWrite(LED_RED,HIGH);
  digitalWrite(LED_GREEN,LOW); 
}

void green(){
  digitalWrite(LED_RED,LOW);
  digitalWrite(LED_GREEN,HIGH);  
}
