/*
Elastic Band Cutter
Copyright Martin Schörner

Last Change: 2020-04-30
License: CC BY
*/

// Length of each band. Customize to fit your needs
#define BAND_LENGTH 250

// Steps per mm of extruded band.
// Tweak this value to fit your extruder gear
#define stepsPerMM 6.4

#define stepsPerRevolution 200


// Pin defines for the linear actuator
#define cutterOutPin 12
#define cutterInPin 13

// Pin defines for the steppers
#define dirPin 4
#define stepPin 7
#define enablePin 8


void setup() {
  // Declare pins as output:
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(enablePin, OUTPUT);

  pinMode(cutterOutPin, OUTPUT);
  pinMode(cutterInPin, OUTPUT);

  digitalWrite(cutterOutPin, LOW);
  digitalWrite(cutterInPin, LOW);

  digitalWrite(enablePin, LOW);
}
void loop() {

  digitalWrite(cutterOutPin, HIGH);
  digitalWrite(cutterInPin, LOW);

  delay(6000);
    digitalWrite(cutterOutPin, LOW);
  digitalWrite(cutterInPin, LOW);

  // Set the spinning direction clockwise:
  digitalWrite(dirPin, LOW);
  // Spin the stepper motor 1 revolution slowly:
  for (int i = 0; i < stepsPerMM *  BAND_LENGTH; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(2000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(2000);

  }

  digitalWrite(cutterOutPin, LOW);
  digitalWrite(cutterInPin, HIGH);
  delay(6500);


  digitalWrite(cutterOutPin, LOW);
  digitalWrite(cutterInPin, LOW);

  delay(1000);

}
