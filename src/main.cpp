#include <Arduino.h>

const int triggerPin = D2;
const int leftLedsPin = D8;
const int rightLedsPin = D7;
const int frontLedsPin = D5;
const int speakerPin = D1;
int lastBeepMs = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(triggerPin, INPUT_PULLUP);
  pinMode(leftLedsPin, OUTPUT);
  pinMode(rightLedsPin, OUTPUT);
  pinMode(frontLedsPin, OUTPUT);
  pinMode(speakerPin, OUTPUT);
}

void loop() {
  int triggerState = digitalRead(triggerPin);

  if (triggerState == LOW) {
    digitalWrite(leftLedsPin, HIGH);
    digitalWrite(rightLedsPin, HIGH);
    digitalWrite(frontLedsPin, HIGH);

    // Beep for 50ms every 500ms
    unsigned long sinceLastBeep = millis() - lastBeepMs;
    if (sinceLastBeep >= 50) {
      digitalWrite(speakerPin, HIGH);
      lastBeepMs = millis();
    }
    else if (sinceLastBeep >= 25) {
      digitalWrite(speakerPin, LOW);
    }
  }
  else {
    digitalWrite(leftLedsPin, LOW);
    digitalWrite(rightLedsPin, LOW);
    digitalWrite(frontLedsPin, LOW);
    digitalWrite(speakerPin, LOW);
  }
}