#include <Arduino.h>

const int triggerPin = D2;
const int leftPin = D8;
const int rightPin = D7;
const int frontPin = D5;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(triggerPin, INPUT_PULLUP);
  pinMode(leftPin, OUTPUT);
  pinMode(rightPin, OUTPUT);
  pinMode(frontPin, OUTPUT);
}

void loop() {
  int triggerState = digitalRead(triggerPin);

  Serial.println(F("Trigger state"));
  Serial.println(triggerState);

  if (triggerState == LOW) {
    digitalWrite(leftPin, HIGH);
    digitalWrite(rightPin, HIGH);
    digitalWrite(frontPin, HIGH);
  }
  else {
    digitalWrite(leftPin, LOW);
    digitalWrite(rightPin, LOW);
    digitalWrite(frontPin, LOW);
  }
}