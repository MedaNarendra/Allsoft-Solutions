#include <IRremote.h>

int RECV_PIN=13;          // IR_Receiver data pin
IRrecv irrecv(RECV_PIN);  // Define IR Receiver and results objects
decode_results results;

int LED_1=14;     // indicates Hall LED
int LED_2=15;     // indicates Kitchen LED
int LED_3=16;     // indicates Bed_Room LED
int LED_4=17;     // indicates Bath_Room LED
int LED_5=18;     // indicates Parking_Garage LED
int LED_6=19;     // indicates Garden_Light LED's

int LED_7=2;     //IR_Remote_Mode indicating LED
int LED_8=3;     //Blynk_Mode indicating LED
int LED_9=4;     //Manual_Mode indicating LED

//int LED_9=8;              // Flame_Sensor indication LED
//int Flame_Sensor=9;       // Flame_Sensor Digital output

int toggleState_1 = 0; //Define integer to remember the toggle state for Hall LED
int toggleState_2 = 0; //Define integer to remember the toggle state for Kitchen LED
int toggleState_3 = 0; //Define integer to remember the toggle state for Bed_Room LED
int toggleState_4 = 0; //Define integer to remember the toggle state for Bathroom LED
int toggleState_5 = 0; //Define integer to remember the toggle state for Parking_Garage LED
int toggleState_6 = 0; //Define integer to remember the toggle state for Garden_LED's

int mswitch_1=7;  //Manual switch for Hall LED
int mswitch_2=8;  //Manual switch for Kitchen LED
int mswitch_3=9;  //Manual switch for Bed_Room LED
int mswitch_4=10; //Manual switch for Bath_Room LED
int mswitch_5=11;  //Manual switch for Parking_Garage LED
int mswitch_6=12; //Manual switch for Garden LED's

int mswitch_7=5; //Manual switch for IR_Remote Mode
int mswitch_8=6; //Manual switch for Blynk Mode

void setup(){
  Serial.begin(115200);
  irrecv.enableIRIn();    // Enable the IR Receiver
  for(int i=2; i<5; i++){
    pinMode(i,OUTPUT);
    digitalWrite(i,LOW);
  }
  for(int j=14; j<20; j++){
    pinMode(j,OUTPUT);
    digitalWrite(j,LOW);
  }
  for(int k=5; k<13; k++){
    pinMode(k,INPUT);
  }
  //pinMode(Flame_Sensor,INPUT);
}

void loop(){
  if(digitalRead(mswitch_7)==HIGH && digitalRead(mswitch_8)==LOW){
    digitalWrite(LED_7,HIGH); digitalWrite(LED_8,LOW); digitalWrite(LED_9,LOW);
    IR_Remote_Mode();
  }
  else if(digitalRead(mswitch_7)==LOW && digitalRead(mswitch_8)==HIGH){
    digitalWrite(LED_7,LOW); digitalWrite(LED_8,HIGH); digitalWrite(LED_9,LOW);
    Blynk_Mode();
  }
  else{
    digitalWrite(LED_7,LOW); digitalWrite(LED_8,LOW); digitalWrite(LED_9,HIGH);
    Manual_Mode();
  } 
}

void LedOnOff(int led){
  switch(led){
    case 1:
    if(toggleState_1 == 0){
      digitalWrite(LED_1,HIGH);   //Hall LED is in "On Condition"
      toggleState_1 = 1;
    }
    else{
      digitalWrite(LED_1,LOW);   //Hall LED is in "Off Condition"
      toggleState_1 = 0;     
    }
    break;
    
    case 2:
    if(toggleState_2 == 0){
      digitalWrite(LED_2,HIGH);   //Kitchen LED is in "On Condition"
      toggleState_2 = 1;
    }
    else{
      digitalWrite(LED_2,LOW);   //Kitchen LED is in "Off Condition"
      toggleState_2 = 0;     
    }
    break;

    case 3:
    if(toggleState_3 == 0){
      digitalWrite(LED_3,HIGH);   //Bed_Room LED is in "On Condition"
      toggleState_3 = 1;
    }
    else{
      digitalWrite(LED_3,LOW);   //Bed_Room LED is in "Off Condition"
      toggleState_3 = 0;     
    }
    break;

    case 4:
    if(toggleState_4 == 0){
      digitalWrite(LED_4,HIGH);   //Bathroom LED is in "On Condition"
      toggleState_4 = 1;
    }
    else{
      digitalWrite(LED_4,LOW);   //Bathroom LED is in "Off Condition"
      toggleState_4 = 0;     
    }
    break;

    case 5:
    if(toggleState_5 == 0){
      digitalWrite(LED_5,HIGH);   //Parking_Garage LED is in "On Condition"
      toggleState_5 = 1;
    }
    else{
      digitalWrite(LED_5,LOW);   //Parking_Garage LED is in "Off Condition"
      toggleState_5 = 0;     
    }
    break;

    case 6:
    if(toggleState_6 == 0){
      digitalWrite(LED_6,HIGH);   //Garden_Light LED's is in "On Condition"
      toggleState_6 = 1;
    }
    else{
      digitalWrite(LED_6,LOW);    //Garden_Light LED's is in "Off Condition"
      toggleState_6 = 0;     
    }
    break;
    default : break;
  }
}

void IR_Remote_Mode(){ //Function for IR_Remote operating
  if(irrecv.decode(&results)){
    Serial.println(results.value);
    switch(results.value){
      //case 33480735: LedOnOff(0); break;
      case 33444015: LedOnOff(1); break;                //IR_Remote control for Hall LED
      case 33478695: LedOnOff(2); break;                //IR_Remote control for Kitchen LED
      case 33486855: LedOnOff(3); break;                //IR_Remote control for Bed_Room LED
      case 33435855: LedOnOff(4); break;                //IR_Remote control for Bath_Room LED
      case 33468495: LedOnOff(5); break;                //IR_Remote control for Parking_Garage LED
      case 33452175: LedOnOff(6); break;                //IR_Remote control for Garden LED's
      //case 33423615: LedOnOff(7); break;
      //case 33484815: LedOnOff(8); break;
      //case 33462375: LedOnOff(9); break;
      default : break;
    }
    irrecv.resume(); // Receive the next value
  }
}

void Blynk_Mode(){ //Function for blynk operating
  if(Serial.available()){
    char data=Serial.read();
    switch(data){
      case 'A': LedOnOff(1); break;        //Blynk_App control for Hall LED
      case 'a': LedOnOff(1); break;
      case 'B': LedOnOff(2); break;        //Blynk_App control for Kitchen LED
      case 'b': LedOnOff(2); break;        
      case 'C': LedOnOff(3); break;        //Blynk_App control for Bed_Room LED
      case 'c': LedOnOff(3); break;
      case 'D': LedOnOff(4); break;        //Blynk_App control for Bath_Room LED
      case 'd': LedOnOff(4); break;
      case 'E': LedOnOff(5); break;        //Blynk_App control for Parking_Garage LED
      case 'e': LedOnOff(5); break;
      case 'F': LedOnOff(6); break;        //Blynk_App control for Garden LED's
      case 'f': LedOnOff(6); break;
      default : break;
    }
    Serial.println(data);
  }
  delay(100);
}

void Manual_Mode(){ //Function for manual operating
  Manual_LED_1();
  Manual_LED_2();
  Manual_LED_3();
  Manual_LED_4();
  Manual_LED_5();
  Manual_LED_6();
}

void Manual_LED_1(){
  if(digitalRead(mswitch_1)==HIGH){              //Manual control for Hall LED
    digitalWrite(LED_1,HIGH);
  }
  else{
    digitalWrite(LED_1,LOW);
  }
}
void Manual_LED_2(){
  if(digitalRead(mswitch_2)==HIGH){              //Manual control for Hall LED
    digitalWrite(LED_2,HIGH);
  }
  else{
    digitalWrite(LED_2,LOW);
  }
}
void Manual_LED_3(){
  if(digitalRead(mswitch_3)==HIGH){              //Manual control for Hall LED
    digitalWrite(LED_3,HIGH);
  }
  else{
    digitalWrite(LED_3,LOW);
  }
}
void Manual_LED_4(){
  if(digitalRead(mswitch_4)==HIGH){              //Manual control for Hall LED
    digitalWrite(LED_4,HIGH);
  }
  else{
    digitalWrite(LED_4,LOW);
  }
}
void Manual_LED_5(){
  if(digitalRead(mswitch_5)==HIGH){              //Manual control for Hall LED
    digitalWrite(LED_5,HIGH);
  }
  else{
    digitalWrite(LED_5,LOW);
  }
}
void Manual_LED_6(){
  if(digitalRead(mswitch_6)==HIGH){              //Manual control for Hall LED
    digitalWrite(LED_6,HIGH);
  }
  else{
    digitalWrite(LED_6,LOW);
  }
}
