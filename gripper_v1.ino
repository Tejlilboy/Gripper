#include <Servo.h>

// ==================================================
// SERVO OBJECTS
// ==================================================

Servo swivelServo;
Servo mainArmServo;
Servo secondArmServo;
Servo clawRotationServo;
Servo clawServo;


// ==================================================
// JOYSTICK INPUTS
// ==================================================

// LEFT JOYSTICK
const int LEFT_VRX = A0;
const int LEFT_VRY = A1;

// RIGHT JOYSTICK
const int RIGHT_VRX = A2;
const int RIGHT_VRY = A3;

// RIGHT JOYSTICK BUTTON
const int RIGHT_BUTTON = A4;


// ==================================================
// SERVO SIGNAL PINS
// ==================================================

const int SWIVEL_PIN = 3;
const int MAIN_ARM_PIN = 5;
const int SECOND_ARM_PIN = 6;
const int CLAW_ROTATION_PIN = 9;
const int CLAW_PIN = 10;


// ==================================================
// SERVO ANGLES
// ==================================================

int swivelAngle = 90;
int mainArmAngle = 45;
int secondArmAngle = 180;
int clawRotationAngle = 90;


// Claw state
// 1 = CLOSED
// 0 = OPEN
int clawState = 1;


// ==================================================
// JOYSTICK SETTINGS
// ==================================================

const int DEADZONE_LOW = 400;
const int DEADZONE_HIGH = 600;


// ==================================================
// SETUP
// ==================================================

void setup() {

  // Attach servos
  swivelServo.attach(SWIVEL_PIN);
  mainArmServo.attach(MAIN_ARM_PIN);
  secondArmServo.attach(SECOND_ARM_PIN);
  clawRotationServo.attach(CLAW_ROTATION_PIN);
  clawServo.attach(CLAW_PIN);


  // Starting positions
  swivelServo.write(swivelAngle);
  mainArmServo.write(mainArmAngle);
  secondArmServo.write(secondArmAngle);
  clawRotationServo.write(clawRotationAngle);

  // Claw starts CLOSED
  clawServo.write(165);


  // Joystick button
  pinMode(RIGHT_BUTTON, INPUT_PULLUP);
}


// ==================================================
// MAIN LOOP
// ==================================================

void loop() {

  // Read joystick positions
  int leftVRX = analogRead(LEFT_VRX);
  int leftVRY = analogRead(LEFT_VRY);

  int rightVRX = analogRead(RIGHT_VRX);
  int rightVRY = analogRead(RIGHT_VRY);


  // ==================================================
  // SERVO 1 - SWIVEL
  // LEFT JOYSTICK VRY → A1
  // ==================================================

  // DOWN → decrease angle
  if (leftVRY < DEADZONE_LOW) {

    swivelAngle -= 1;
    swivelAngle = constrain(swivelAngle, 0, 180);

    swivelServo.write(swivelAngle);

    // Further from center = faster
    int speedDelay = map(leftVRY, 0, DEADZONE_LOW, 3, 30);
    delay(speedDelay);
  }

  // UP → increase angle
  if (leftVRY > DEADZONE_HIGH) {

    swivelAngle += 1;
    swivelAngle = constrain(swivelAngle, 0, 180);

    swivelServo.write(swivelAngle);

    int speedDelay = map(leftVRY, DEADZONE_HIGH, 1023, 30, 3);
    delay(speedDelay);
  }


  // ==================================================
  // SERVO 2 - MAIN ARM
  // LEFT JOYSTICK VRX → A0
  // ==================================================

  // LEFT → increase angle
  if (leftVRX < DEADZONE_LOW) {

    mainArmAngle += 1;
    mainArmAngle = constrain(mainArmAngle, 0, 180);

    mainArmServo.write(mainArmAngle);

    int speedDelay = map(leftVRX, 0, DEADZONE_LOW, 3, 30);
    delay(speedDelay);
  }

  // RIGHT → decrease angle
  if (leftVRX > DEADZONE_HIGH) {

    mainArmAngle -= 1;
    mainArmAngle = constrain(mainArmAngle, 0, 180);

    mainArmServo.write(mainArmAngle);

    int speedDelay = map(leftVRX, DEADZONE_HIGH, 1023, 30, 3);
    delay(speedDelay);
  }


  // ==================================================
  // SERVO 3 - SECOND ARM
  // RIGHT JOYSTICK VRX → A2
  // ==================================================

  // LEFT → increase angle
  if (rightVRX < DEADZONE_LOW) {

    secondArmAngle += 1;
    secondArmAngle = constrain(secondArmAngle, 0, 180);

    secondArmServo.write(secondArmAngle);

    int speedDelay = map(rightVRX, 0, DEADZONE_LOW, 3, 30);
    delay(speedDelay);
  }

  // RIGHT → decrease angle
  if (rightVRX > DEADZONE_HIGH) {

    secondArmAngle -= 1;
    secondArmAngle = constrain(secondArmAngle, 0, 180);

    secondArmServo.write(secondArmAngle);

    int speedDelay = map(rightVRX, DEADZONE_HIGH, 1023, 30, 3);
    delay(speedDelay);
  }


  // ==================================================
  // SERVO 4 - CLAW ROTATION
  // RIGHT JOYSTICK VRY → A3
  // ==================================================

  // DOWN → increase angle
  if (rightVRY < DEADZONE_LOW) {

    clawRotationAngle += 1;
    clawRotationAngle = constrain(clawRotationAngle, 0, 180);

    clawRotationServo.write(clawRotationAngle);

    int speedDelay = map(rightVRY, 0, DEADZONE_LOW, 3, 30);
    delay(speedDelay);
  }

  // UP → decrease angle
  if (rightVRY > DEADZONE_HIGH) {

    clawRotationAngle -= 1;
    clawRotationAngle = constrain(clawRotationAngle, 0, 180);

    clawRotationServo.write(clawRotationAngle);

    int speedDelay = map(rightVRY, DEADZONE_HIGH, 1023, 30, 3);
    delay(speedDelay);
  }


  // ==================================================
  // SERVO 5 - CLAW OPEN / CLOSE
  // RIGHT JOYSTICK BUTTON → A4
  // ==================================================

  if (digitalRead(RIGHT_BUTTON) == LOW) {

    // Debounce buffer
    delay(50);

    // Confirm button is still pressed
    if (digitalRead(RIGHT_BUTTON) == LOW) {

      // Toggle state
      clawState = !clawState;


      switch (clawState) {

        case 0:  // OPEN
          clawServo.write(85);
          break;

        case 1:  // CLOSED
          clawServo.write(180);
          break;
      }


      // Wait for button release
      while (digitalRead(RIGHT_BUTTON) == LOW) {
        delay(10);
      }

      // Release debounce
      delay(50);
    }
  }
}