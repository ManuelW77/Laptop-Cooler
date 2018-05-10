#include <Arduino.h>

int sensorPin = A7;
int PWM = 7; // Fan
int sensorVal;
int PWMVal;

// Vars für Temp Umrechnung
float R1 = 10000;
float logR2, R2, T, Tc, raw, temp;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

float calculateTemp(float raw) {
  R2 = R1 * (1023.0 / (float)raw - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  Tc = T - 273.15;

  return Tc;
}

void setup() {
  pinMode(sensorPin, INPUT);
  pinMode(PWM, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  //read sensor value and set upper limit cap
  sensorVal = analogRead(sensorPin);

  temp = calculateTemp(sensorVal);
  Serial.println(String(temp) + " C");
  delay(1000);

  // Fan an
  if (sensorVal > 587) {
    digitalWrite(PWM, HIGH);
  }
  if (sensorVal < 500) {
    digitalWrite(PWM, LOW);
  }
}
