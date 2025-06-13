#include <Servo.h>
#include "HX711.h"
#include <ArduinoJson.h>

#define SERVO_PIN 5
#define LED_PIN 9
#define BUTTON_PIN 2
#define HX711_DT 13
#define HX711_SCK 10

Servo servoMotor;
HX711 balanca;

int buttonState = 0;
bool processoAtivo = false;

void setup() {
  Serial.begin(9600);
  servoMotor.attach(SERVO_PIN);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  balanca.begin(HX711_DT, HX711_SCK);
  balanca.set_scale();
  balanca.tare();
  servoMotor.write(0);
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == LOW && !processoAtivo) {
    processoAtivo = true;
    digitalWrite(LED_PIN, HIGH);
    servoMotor.write(90);
    delay(3000);
    float peso = balanca.get_units(10);
    servoMotor.write(0);
    digitalWrite(LED_PIN, LOW);

    StaticJsonDocument<200> doc;
    doc["status"] = "closed";
    doc["peso"] = peso;

    serializeJson(doc, Serial);
    Serial.println();

    delay(1000);
    processoAtivo = false;
  }
}
