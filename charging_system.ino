#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Ultrasonic pins
#define trig1 2
#define echo1 3
#define trig2 4
#define echo2 5

long duration;
int distance1, distance2;

// Distance function
int getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;

  return distance;
}

void setup() {
  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);

  lcd.begin();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Wireless Charging");
  delay(2000);
  lcd.clear();
}

// Function for scrolling text
void scrollText(String message) {
  int len = message.length();

  for (int i = 0; i < len - 15; i++) {
    lcd.setCursor(0, 0);
    lcd.print(message.substring(i, i + 16));
    delay(300);
  }
}

void loop() {

  distance1 = getDistance(trig1, echo1);
  distance2 = getDistance(trig2, echo2);

  bool s1 = (distance1 < 10);
  bool s2 = (distance2 < 10);

  lcd.clear();

  if (s1 && s2) {
    String msg = "S1 CHARGING | S2 CHARGING   ";
    scrollText(msg);
  }
  else if (s1) {
    lcd.setCursor(0, 0);
    lcd.print("Station 1");
    lcd.setCursor(0, 1);
    lcd.print("CHARGING");
    delay(500);
  }
  else if (s2) {
    lcd.setCursor(0, 0);
    lcd.print("Station 2");
    lcd.setCursor(0, 1);
    lcd.print("CHARGING");
    delay(500);
  }
  else {
    lcd.setCursor(0, 0);
    lcd.print("System Status");
    lcd.setCursor(0, 1);
    lcd.print("IDLE");
    delay(500);
  }
}
