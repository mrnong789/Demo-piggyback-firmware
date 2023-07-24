#include <Arduino.h>

const int inEnPin = 7;
const int inIn1Pin = 8;
const int inIn2Pin = 9;

const int outEnPin = 10;
const int outIn1Pin = 11;
const int outIn2Pin = 12;
unsigned long duration = 0;

void setup() {
  Serial.begin(9600);
  pinMode(inEnPin, INPUT);
  pinMode(inIn1Pin, INPUT);
  pinMode(inIn2Pin, INPUT);
  pinMode(outEnPin, OUTPUT);
  pinMode(outIn1Pin, OUTPUT);
  pinMode(outIn2Pin, OUTPUT);
}

void loop() {
  duration = pulseIn(inEnPin, HIGH);
  int enVal = map(duration, 0, 2012, 0, 255);
  int in1Val = digitalRead(inIn1Pin);
  int in2Val = digitalRead(inIn2Pin);

  // Serial.print("in1=");
  // Serial.print(in1Val);

  // Serial.print(" ,in2=");
  // Serial.print(in2Val);

  // Serial.print(" ,en=");
  // Serial.println(enVal);
  Serial.println(enVal);
  digitalWrite(outIn1Pin, in1Val);
  digitalWrite(outIn2Pin, in2Val);
  analogWrite(outEnPin, enVal);

  delay(250);

}