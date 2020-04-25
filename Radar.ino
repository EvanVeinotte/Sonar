#include <Servo.h>

//create servo object
Servo myservo;

//declare the ultrasonic pins
const int trigpin = 9;
const int echopin = 10;
const int del = 15;
const float soundspd = 0.034;

long duration;
int distance;

int pos = 0;

void setup() {
  //declare the pin used for the servo
  myservo.attach(11);

  //setting the pinmodes
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  //move a degree and then scan
  for (pos = 10; pos <= 170; pos += 1) {
    myservo.write(pos);
    //execute scan function
    scan(pos);
    delay(del);
  }
  //repeat the last for loop except backwards
  for (pos = 170; pos >= 10; pos -= 1) {
    myservo.write(pos);

    //execute scan function
    scan(pos);
    delay(del);
  }
}

void scan(int pos) {
  //I do some tricky tuning because the module that I have
  //doesn't seem to work well without a specific delay.
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);

  duration = pulseIn(echopin, HIGH);

  //The distance will be equal to the duration multiplied by the
  //speed of sound constant divided by two
  //(Because the waves have to travel to the surface and then travel back)
  distance = duration * soundspd / 2;
  
  Serial.println(String(distance) + " " + String(pos));
}
