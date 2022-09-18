///*
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

//#define BLYNK_TEMPLATE_ID "TMPLU_xr-3oE"
//#define BLYNK_DEVICE_NAME "Home Automation"

char auth[] = "WPze0Zig4P1glgkmunKn_hQk0fyoNmm_";
char ssid[] = "NARENDRA";
char pass[] = "Pubg@987";

void setup()
{
  Serial.begin(115200);
  //Blynk.begin(auth, ssid, pass);
  Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
}

void loop()
{
  Blynk.run();
}



BLYNK_WRITE(V0)
{
  int pinValue_V0 = param.asInt();
  if(pinValue_V0==HIGH){
    Serial.println("A");
  }
  else{
    Serial.println("a");
  }
}
BLYNK_WRITE(V1)
{
  int pinValue_V1 = param.asInt();
  if(pinValue_V1==HIGH){
    Serial.println("B");
  }
  else{
    Serial.println("b");
  }
}
BLYNK_WRITE(V2)
{
  int pinValue_V2 = param.asInt();
  if(pinValue_V2==HIGH){
    Serial.println("C");
  }
  else{
    Serial.println("c");
  }
}
BLYNK_WRITE(V3)
{
  int pinValue_V3 = param.asInt();
  if(pinValue_V3==HIGH){
    Serial.println("D");
  }
  else{
    Serial.println("d");
  }
}
BLYNK_WRITE(V4)
{
  int pinValue_V4 = param.asInt();
  if(pinValue_V4==HIGH){
    Serial.println("E");
  }
  else{
    Serial.println("e");
  }
}
BLYNK_WRITE(V5)
{
  int pinValue_V5 = param.asInt();
  if(pinValue_V5==HIGH){
    Serial.println("F");
  }
  else{
    Serial.println("f");
  }
}
//*/
/*
#define BLYNK_TEMPLATE_ID "TMPLU_xr-3oE"
#define BLYNK_DEVICE_NAME "Home Automation"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"
#define BLYNK_PRINT Serial

#define APP_DEBUG

#include "BlynkEdgent.h"

void setup()
{
  Serial.begin(115200);
  delay(100);
  BlynkEdgent.begin();
}

void loop()
{
  BlynkEdgent.run();
}


BLYNK_WRITE(V0)
{
  int pinValue_V0 = param.asInt();
  if(pinValue_V0==HIGH){
    Serial.println("A");
  }
  else{
    Serial.println("a");
  }
}
BLYNK_WRITE(V1)
{
  int pinValue_V1 = param.asInt();
  if(pinValue_V1==HIGH){
    Serial.println("B");
  }
  else{
    Serial.println("b");
  }
}
BLYNK_WRITE(V2)
{
  int pinValue_V2 = param.asInt();
  if(pinValue_V2==HIGH){
    Serial.println("C");
  }
  else{
    Serial.println("c");
  }
}
BLYNK_WRITE(V3)
{
  int pinValue_V3 = param.asInt();
  if(pinValue_V3==HIGH){
    Serial.println("D");
  }
  else{
    Serial.println("d");
  }
}
BLYNK_WRITE(V4)
{
  int pinValue_V4 = param.asInt();
  if(pinValue_V4==HIGH){
    Serial.println("E");
  }
  else{
    Serial.println("e");
  }
}
BLYNK_WRITE(V5)
{
  int pinValue_V5 = param.asInt();
  if(pinValue_V5==HIGH){
    Serial.println("F");
  }
  else{
    Serial.println("f");
  }
}
*/
