/*
 * Licensed under the Apache License 2.0
 * Copyright (c) 2025 Saad (SSADEVS)
 * See LICENSE file for details.
 */
#include <Wire.h>
#include <DFRobot_BMI160.h>
#include <BleMouse.h>

// ====== Pin Setup ======
#define SDA_PIN 8
#define SCL_PIN 9
#define LEFT_BUTTON_PIN 4
#define RIGHT_BUTTON_PIN 5

BleMouse bleMouse("AirMouse", "ESP32-C3", 100);
DFRobot_BMI160 bmi160;

int avgDx = 0, avgDy = 0;
bool arrowScreenActive = false;

void setup() {
  Serial.begin(115200);
  Wire.begin(SDA_PIN, SCL_PIN);

  // BMI160 init
  if (bmi160.softReset() != BMI160_OK) {
    Serial.println("BMI160 soft reset failed!");
  }
  if (bmi160.I2cInit(0x69) != BMI160_OK) {
    Serial.println("BMI160 init failed!");
    while (1);
  }

  bleMouse.begin();
  pinMode(LEFT_BUTTON_PIN, INPUT_PULLUP);
  pinMode(RIGHT_BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  if (!bleMouse.isConnected() && !arrowScreenActive) {
    delay(300);
    return;
  }
  if (bleMouse.isConnected() && !arrowScreenActive) {
    delay(800);  
    arrowScreenActive = true;
  }

  // ---- Motion control ----
  int16_t accel[3], gyro[3];
  bmi160.getAccelData(accel);
  bmi160.getGyroData(gyro);

  int dx = gyro[1] / 500;
  int dy = -gyro[0] / 500;

  if (abs(dx) < 2) dx = 0;
  if (abs(dy) < 2) dy = 0;

  avgDx = (avgDx * 4 + dx) / 5;
  avgDy = (avgDy * 4 + dy) / 5;

  if (avgDx != 0 || avgDy != 0)
    bleMouse.move(avgDx, avgDy);

  // ---- Buttons ----
  if (digitalRead(LEFT_BUTTON_PIN) == LOW)
    bleMouse.press(MOUSE_LEFT);
  else
    bleMouse.release(MOUSE_LEFT);

  if (digitalRead(RIGHT_BUTTON_PIN) == LOW)
    bleMouse.press(MOUSE_RIGHT);
  else
    bleMouse.release(MOUSE_RIGHT);

  delay(0);
}
