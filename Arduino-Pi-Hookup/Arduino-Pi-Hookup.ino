#include <Stepper.h>

const int stepsPerRevolution = 2038;

const int clockwise = stepsPerRevolution;
const int counterClockwise = -stepsPerRevolution;

// Creates an instance of stepper class
// Pins entered in sequence IN1-IN3-IN2-IN4 for proper step sequence
Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);

void switchPresets(String presetName) {
  switch(presetName) {
    case "Peace Sign":
      peaceSign();
  }
}

// TESTING
// THIS IS NOT THE PEACE SIGN, THIS IS THE STEPPER MOTOR PROTOTYPE CODE
void peaceSign() {
  // Rotate CW slowly at 5 RPM
	myStepper.setSpeed(5);
	myStepper.step(clockwise);
	delay(1000);
	
	// Rotate CCW quickly at 10 RPM
	myStepper.setSpeed(20);
	myStepper.step(counterClockwise);
	delay(1000);
}


void setup() {
  Serial.begin(9600);
}

void loop() {
  //read from port 9600
  if (Serial.available() > 0) {
    String name = Serial.readStringUntil('\n');
    String presetName = Serial.readStringUntil('\n');
  }
}