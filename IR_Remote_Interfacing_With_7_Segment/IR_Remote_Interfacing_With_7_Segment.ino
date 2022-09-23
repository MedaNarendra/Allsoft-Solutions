#include <IRremote.h>
int RECV_PIN = 9;
int i,j,k;
IRrecv irrecv(RECV_PIN);
decode_results results;
int num_array[10][7] = {  {1,1,1,1,1,1,0},    // 0
                          {0,1,1,0,0,0,0},    // 1
                          {1,1,0,1,1,0,1},    // 2
                          {1,1,1,1,0,0,1},    // 3
                          {0,1,1,0,0,1,1},    // 4
                          {1,0,1,1,0,1,1},    // 5
                          {1,0,1,1,1,1,1},    // 6
                          {1,1,1,0,0,0,0},    // 7
                          {1,1,1,1,1,1,1},    // 8
                          {1,1,1,0,0,1,1}};   // 9
                          
void setup(){
 for(i=2;i<10;i++)
  {
    pinMode(i,OUTPUT);
    digitalWrite(i,LOW);
  }
 Serial.begin(9600);
 irrecv.enableIRIn(); // Start the receiver
}

void Segment(){
  for(j=2;j<9;j++){
    digitalWrite(j,num_array[k][j-2]);
  }
}

void loop(){
 if (irrecv.decode(&results)){
  Serial.println(results.value);

  switch(results.value){
    case 16593103: k=0; Segment(); break;
    case 16582903: k=1; Segment(); break;
    case 16615543: k=2; Segment(); break;
    case 16599223: k=3; Segment(); break;
    case 16591063: k=4; Segment(); break;
    case 16623703: k=5; Segment(); break;
    case 16607383: k=6; Segment(); break;
    case 16586983: k=7; Segment(); break;
    case 16619623: k=8; Segment(); break;
    case 16603303: k=9; Segment(); break; 
  }
  irrecv.resume(); // Receive the next value
 }
}
