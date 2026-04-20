#  Vehicle Wireless Charging Station

## Overview
This project demonstrates a wireless vehicle charging station using Arduino, ultrasonic sensors, and a 16x2 LCD display. The system detects the presence of vehicles at two charging stations and displays the charging status.

## Features
- Detects vehicle presence using ultrasonic sensors
- Displays status on 16x2 LCD
- Shows:
  - "IDLE" when no vehicle is present
  - "Station 1 CHARGING" when vehicle is at station 1
  - "Station 2 CHARGING" when vehicle is at station 2
  - Scrolling message when both stations are active

## Components Used
- Arduino Uno
- 2 × HC-SR04 Ultrasonic Sensors
- 16x2 LCD Display (I2C)
- Jumper wires
- Breadboard

## Pin Configuration
- Sensor 1 → Trig: 2, Echo: 3
- Sensor 2 → Trig: 4, Echo: 5
- LCD → SDA: A4, SCL: A5

## Working Principle
The ultrasonic sensors measure the distance between the station and the vehicle. When a vehicle is detected within a predefined threshold distance, the Arduino identifies the active station and displays the corresponding charging status on the LCD. If both stations are occupied, a scrolling message is displayed.

## How to Run
1. Upload the .ino file to Arduino using Arduino IDE
2. Connect all components as per pin configuration
3. Power the Arduino
4. Observe LCD output based on vehicle placement

## Applications
- Smart parking systems
- Wireless EV charging stations
- Automation projects

## Author
Darshan H N
## Project Title
Vehicle Wireless Charging Station