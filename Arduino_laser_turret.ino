#include <Wire.h>
#include <Servo.h>

#define POTENTIOMETER_PIN1 A0
#define POTENTIOMETER_PIN2 A1
#define SERVO_PIN1 9
#define SERVO_PIN2 10

Servo servo1;
Servo servo2;

void setup() {
  Serial.begin(9600);
  servo1.attach(SERVO_PIN1);
  servo2.attach(SERVO_PIN2);
  servo1.write(90); // Set initial angle for servo 1
  servo2.write(90); // Set initial angle for servo 2
}
void loop() {
  int potValue1 = analogRead(POTENTIOMETER_PIN1); // Read potentiometer value 1
  int servoAngle1 = map(potValue1, 0, 1023, 0, 180); // Map potentiometer to servo angle
  servo1.write(servoAngle1); // Set servo angle 1

  int potValue2 = analogRead(POTENTIOMETER_PIN2); // Read potentiometer value 2
  int servoAngle2 = map(potValue2, 0, 1023, 0, 180); // Map potentiometer to servo angle
  servo2.write(servoAngle2); // Set servo angle 2

  Serial.print("Servo 1 Angle: ");
  Serial.print(servoAngle1);
  Serial.print("\tServo 2 Angle: ");
  Serial.println(servoAngle2);

  delay(20); // Small delay for smoother operation
}
