#include <Arduino.h>

int sensorPin = A7;
int PWM = 7; // Fan
int sensorVal;
int PWMVal;
bool fanRunning = false;

void setup() {
  pinMode(sensorPin, INPUT);
  pinMode(PWM, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  Serial.println(sensorVal);
  delay(1000);

  //read sensor value and set upper limit cap
  sensorVal = analogRead(sensorPin);
  // Fan an
  if (sensorVal > 700) {
    digitalWrite(PWM, HIGH);
  }
  if (sensorVal < 500) {
    digitalWrite(PWM, LOW);
  }
}
