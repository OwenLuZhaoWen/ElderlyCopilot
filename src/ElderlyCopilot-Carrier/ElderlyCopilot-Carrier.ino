/*
命令表
forward: 1
backward: 2
turnLeft: 3
turnRight: 4
frontLeft: 5
frontRight: 6
backLeft: 7
backRight: 8
stairUp: 9
stairDown: 10
stop: s
*/
#include <SoftwareSerial.h>
#define SPEED 255  // 0 - 255
int compensation = 150;
const int frontLEN = 3;
const int frontREN = 5;
const int backLEN = 9;
const int backREN = 11;
const int frontLF = 2;
const int frontLB = 4;
const int frontRF = 6;
const int frontRB = 7;
const int backLF = 8;
const int backLB = 10;
const int backRF = 12;
const int backRB = 13;
SoftwareSerial BTSerial(14, 15);

void stop() {
  Serial.println("stop");
  digitalWrite(frontLF, LOW);
  digitalWrite(frontLB, LOW);
  digitalWrite(frontRF, LOW);
  digitalWrite(frontRB, LOW);
  digitalWrite(backLF, LOW);
  digitalWrite(backLB, LOW);
  digitalWrite(backRF, LOW);
  digitalWrite(backRB, LOW);
  delay(10);
}

void forward() {
  Serial.println("Forward!");
  digitalWrite(frontLF, HIGH);
  digitalWrite(frontLB, LOW);
  digitalWrite(frontRF, LOW);
  digitalWrite(frontRB, HIGH);
  digitalWrite(backLF, HIGH);
  digitalWrite(backLB, LOW);
  digitalWrite(backRF, LOW);
  digitalWrite(backRB, HIGH);
  analogWrite(frontLEN, SPEED);
  analogWrite(frontREN, SPEED);
  analogWrite(backLEN, SPEED);
  analogWrite(backREN, SPEED);
  delay(10);
}

void backward() {
  Serial.println("Backward!");
  digitalWrite(frontLF, LOW);
  digitalWrite(frontLB, HIGH);
  digitalWrite(frontRF, HIGH);
  digitalWrite(frontRB, LOW);
  digitalWrite(backLF, LOW);
  digitalWrite(backLB, HIGH);
  digitalWrite(backRF, HIGH);
  digitalWrite(backRB, LOW);
  analogWrite(frontLEN, SPEED);
  analogWrite(frontREN, SPEED);
  analogWrite(backLEN, SPEED);
  analogWrite(backREN, SPEED);
  delay(10);
}

void turnLeft() {
  digitalWrite(frontLF, LOW);
  digitalWrite(frontLB, HIGH);
  digitalWrite(frontRF, LOW);
  digitalWrite(frontRB, HIGH);
  digitalWrite(backLF, LOW);
  digitalWrite(backLB, HIGH);
  digitalWrite(backRF, LOW);
  digitalWrite(backRB, HIGH);
  analogWrite(frontLEN, SPEED);
  analogWrite(frontREN, SPEED);
  analogWrite(backLEN, SPEED);
  analogWrite(backREN, SPEED);
  delay(10);
}

void turnRight() {
  digitalWrite(frontLF, HIGH);
  digitalWrite(frontLB, LOW);
  digitalWrite(frontRF, HIGH);
  digitalWrite(frontRB, LOW);
  digitalWrite(backLF, HIGH);
  digitalWrite(backLB, LOW);
  digitalWrite(backRF, HIGH);
  digitalWrite(backRB, LOW);
  analogWrite(frontLEN, SPEED);
  analogWrite(frontREN, SPEED);
  analogWrite(backLEN, SPEED);
  analogWrite(backREN, SPEED);
  delay(10);
}

void frontLeft() {
  digitalWrite(frontLF, HIGH);
  digitalWrite(frontLB, LOW);
  digitalWrite(frontRF, LOW);
  digitalWrite(frontRB, HIGH);
  digitalWrite(backLF, HIGH);
  digitalWrite(backLB, LOW);
  digitalWrite(backRF, LOW);
  digitalWrite(backRB, HIGH);
  analogWrite(frontLEN, SPEED - compensation);
  analogWrite(frontREN, SPEED);
  analogWrite(backLEN, SPEED - compensation);
  analogWrite(backREN, SPEED);
  delay(10);
}

void frontRight() {
  digitalWrite(frontLF, HIGH);
  digitalWrite(frontLB, LOW);
  digitalWrite(frontRF, LOW);
  digitalWrite(frontRB, HIGH);
  digitalWrite(backLF, HIGH);
  digitalWrite(backLB, LOW);
  digitalWrite(backRF, LOW);
  digitalWrite(backRB, HIGH);
  analogWrite(frontLEN, SPEED);
  analogWrite(frontREN, SPEED - compensation);
  analogWrite(backLEN, SPEED);
  analogWrite(backREN, SPEED - compensation);
  delay(10);
}

void backLeft() {
  digitalWrite(frontLF, LOW);
  digitalWrite(frontLB, HIGH);
  digitalWrite(frontRF, HIGH);
  digitalWrite(frontRB, LOW);
  digitalWrite(backLF, LOW);
  digitalWrite(backLB, HIGH);
  digitalWrite(backRF, HIGH);
  digitalWrite(backRB, LOW);
  analogWrite(frontLEN, SPEED - compensation);
  analogWrite(frontREN, SPEED);
  analogWrite(backLEN, SPEED - compensation);
  analogWrite(backREN, SPEED);
  delay(10);
}

void backRight() {
  digitalWrite(frontLF, LOW);
  digitalWrite(frontLB, HIGH);
  digitalWrite(frontRF, HIGH);
  digitalWrite(frontRB, LOW);
  digitalWrite(backLF, LOW);
  digitalWrite(backLB, HIGH);
  digitalWrite(backRF, HIGH);
  digitalWrite(backRB, LOW);
  analogWrite(frontLEN, SPEED);
  analogWrite(frontREN, SPEED - compensation);
  analogWrite(backLEN, SPEED);
  analogWrite(backREN, SPEED - compensation);
  delay(10);
}

void stairUp() {
}

void stairDown() {
}

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
  pinMode(frontLEN, OUTPUT);
  pinMode(frontREN, OUTPUT);
  pinMode(backLEN, OUTPUT);
  pinMode(backREN, OUTPUT);
  pinMode(frontLF, OUTPUT);
  pinMode(frontLB, OUTPUT);
  pinMode(frontRF, OUTPUT);
  pinMode(frontRB, OUTPUT);
  pinMode(backLF, OUTPUT);
  pinMode(backLB, OUTPUT);
  pinMode(backRF, OUTPUT);
  pinMode(backRB, OUTPUT);
}
void loop() {
  if (BTSerial.available()) {
    int command = BTSerial.parseInt();
    Serial.println(command);
    switch (command) {
      case 0:
        stop();
        break;
      case 1:
        forward();
        break;
      case 2:
        backward();
        break;
      case 3:
        turnLeft();
        break;
      case 4:
        turnRight();
        break;
      case 5:
        frontLeft();
        break;
      case 6:
        frontRight();
        break;
      case 7:
        backLeft();
        break;
      case 8:
        backRight();
        break;
      case 9:
        stairUp();
        break;
      case 10:
        stairDown();
        break;
    }
  }
}
