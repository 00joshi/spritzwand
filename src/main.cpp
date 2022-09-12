#include <Arduino.h>

int fluid_level_pin_0 = A0;
int fluid_level_pin_1 = A5;
int relay_pin_0 = 2;
int relay_pin_1 = 3;

int fluid_level_0 = 0;
int fluid_level_1 = 0;

int on_fluid_level = 500;
int off_fluid_level = on_fluid_level - 50;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(relay_pin_0, OUTPUT);
  pinMode(relay_pin_1, OUTPUT);
  digitalWrite(relay_pin_0, HIGH);
  digitalWrite(relay_pin_1, HIGH);
}

void loop() {
  fluid_level_0 = analogRead(fluid_level_pin_0);
  Serial.println(fluid_level_0);
  Serial.println(fluid_level_1);

  if (fluid_level_0 > on_fluid_level){
    digitalWrite(relay_pin_0, LOW);
  } else if (fluid_level_0 < off_fluid_level) {
    digitalWrite(relay_pin_0, HIGH);
  }

  fluid_level_1 = analogRead(fluid_level_pin_1);
  //fluid_level_1 = 0;
  if (fluid_level_1 > on_fluid_level){
    digitalWrite(relay_pin_1, LOW);
  } else if (fluid_level_1 < off_fluid_level) {
    digitalWrite(relay_pin_1, HIGH);
  }
  
  delay(300);
}
