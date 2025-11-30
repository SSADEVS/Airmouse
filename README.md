# ESP32-C3 BLE AirMouse using BMI160

This project converts an ESP32-C3 Supermini into a **Bluetooth Low Energy (BLE) AirMouse** using the BMI160 IMU sensor. It allows you to control your computer or mobile device cursor by moving the device in the air. The setup also supports left and right mouse clicks via buttons.

---

## Features

* BLE mouse control using ESP32-C3 Supermini
* Motion sensing via BMI160 (accelerometer + gyroscope)
* Adjustable sensitivity and deadzone
* Supports left and right click buttons
* Works on Windows, Linux and Android. (note: it don't work on iphone,ipad)

---

## Hardware Requirements

* ESP32-C3 development board
* BMI160 sensor
* Two push buttons for left/right click

---

## Wiring

| Component    | ESP32-C3 Pin |
| ------------ | ------------ |
| BMI160 SDA   | 8            |
| BMI160 SCL   | 9            |
| BMI160 VCC   | 3.3V         |
| BMI160 GND   | GND          |
| Left Button  | 4            |
| Right Button | 5            |

> Ensure the BMI160 is powered by 3.3V. Connect the GND of the sensor to the ESP32-C3 ground.

---

## Software Requirements

* **Libraries** (install via Arduino Library Manager):

  * [DFRobot_BMI160](https://github.com/DFRobot/DFRobot_BMI160)
  * [BleMouse](https://github.com/T-vK/ESP32-BLE-Mouse)
  * Wire (comes with Arduino)

---

## Usage

1. Connect the ESP32-C3 and BMI160 as per wiring above.
2. Connect buttons for left and right mouse click.
3. Upload the Arduino sketch.
4. Power on the ESP32-C3; it will advertise as a BLE mouse.
5. Pair with your device and start controlling the cursor using motion.

---

## Notes

* Sensitivity and deadzone values can be adjusted in the sketch.
