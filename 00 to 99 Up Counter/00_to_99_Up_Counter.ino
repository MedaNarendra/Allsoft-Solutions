int i, j, k, p, q;
int arr[10][7] = {  {1,1,1,1,1,1,0}, // 0
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
  for(i=0; i<14; i++){
    pinMode(i,OUTPUT);
    digitalWrite(i,LOW);
  }
}

void segment2(){
  for(j=0; j<10; j++){ //For selecting row of segment_2
    for(k=0; k<7; k++){ //For selecting column of segment_2
      digitalWrite(k+7,arr[j][k]);
    }
  delay(1000);
  }
}

void loop(){
  for(p=0; p<10; p++){ //For selecting row of segment_1
    for(q=0; q<7; q++){  //For selecting column of segment_1
      digitalWrite(q,arr[p][q]);
    }
  //delay(1000);
  segment2();
  }
}
