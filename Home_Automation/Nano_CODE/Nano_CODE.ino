const int trigPin = 9; // pin on the arduinowhere the trigger pin is connected
const int echoPin = 10;// pin on the arduino where the echo pin is connected
const int led1 = 2; // water level indicator 1
const int led2 = 3; // water level indicator 2
const int led3 = 4; // water level indicator 3
const int led4 = 5;// pin connected to the base of NPN transistor through a resistor for switching the pump ON and off
const int buzzer=6;
long duration; // variable where the the reflection time of the ultrasound is stored
int distance; // variable where the distance of the measured object is stored
void setup()
{
pinMode (led1, OUTPUT);// sets as output
pinMode (led2, OUTPUT);//sets as output
pinMode (led3, OUTPUT);//sets as aoutput
pinMode(led4, OUTPUT);//sets as output
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(buzzer, OUTPUT);
Serial.begin(9600); // Starts the serial communication
}

void loop()
{
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);


if ( distance<=3)// when water has gotten to this level or is less than this level
{
digitalWrite (led1, HIGH);// led1 comes ON and remains ON
digitalWrite (led2, HIGH);
digitalWrite (led3, HIGH);
digitalWrite (led4, HIGH);
tone(buzzer,3000);
delay(3000);
noTone(buzzer);
delay(3000);
}
if (distance>=4&&distance<=6)// when the level of water has gotten to this level
{
digitalWrite(led1, HIGH);// switch ON the Tap
digitalWrite(led2, HIGH);
digitalWrite(led3, HIGH);
digitalWrite(led4, LOW);
}
if ( distance>=7&&distance<=9)// when water has gotten to this level or is less than this level
{
digitalWrite (led1, HIGH);
digitalWrite (led2, HIGH);//switch ON the led2
digitalWrite (led3, LOW);
digitalWrite (led4, LOW);
}
if( distance>=10&&distance<=12)// when water has gotten to this level or is less than this level
{
digitalWrite (led1, HIGH);//switch ON the led3
digitalWrite (led2, LOW);
digitalWrite (led3, LOW);
digitalWrite (led4, LOW);
}
if (distance>12)// when the level of water has gotten to this level
{
digitalWrite(led1,LOW);
digitalWrite(led2,LOW);
digitalWrite(led3,LOW);
digitalWrite(led4,LOW);//led4 goes OF and stays OF
}
}
