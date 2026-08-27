#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int sensorPin = A0;
int ledPin = 8;
int buzzerPin = 9;
int buttonPin = 7;

int threshold = 500;

bool engineOn = false;
int lastButtonReading = HIGH;
int buttonState = HIGH;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  lcd.begin(16, 2);
  lcd.clear();

  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  bool childDetected = sensorValue > threshold;

  int reading = digitalRead(buttonPin);

  if (reading != lastButtonReading) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;

      if (buttonState == LOW) {
        engineOn = !engineOn;
      }
    }
  }

  lastButtonReading = reading;

  bool engineOff = !engineOn;

  if (childDetected && engineOff) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
  }

  lcd.clear();

  lcd.setCursor(0, 0);
  if (childDetected) {
    lcd.print("Seat1: Occupied");
  } else {
    lcd.print("Seat1: Empty");
  }

  lcd.setCursor(0, 1);
  if (childDetected && engineOff) {
    lcd.print("Child in bus!");
  } else if (engineOn) {
    lcd.print("Engine: ON");
  } else {
    lcd.print("Engine: OFF");
  }

  Serial.print("Sensor: ");
  Serial.print(sensorValue);
  Serial.print(" | Engine: ");
  if (engineOn) {
    Serial.print("ON");
  } else {
    Serial.print("OFF");
  }
  Serial.print(" | Child: ");
  if (childDetected) {
    Serial.println("YES");
  } else {
    Serial.println("NO");
  }

  delay(300);
}
