/*========================================================================
                         LEDs Lightning Modes
==========================================================================
Description:
  This program allows the user to select an LED lighting mode through
  the Serial Monitor.

  Mode 1: Blink
  Mode 2: Alternate
  Mode 3: Running Lights

Programmer:
  Rhile Galpo

Date:
  7 Nov 2026
==========================================================================*/

// GPIOs
const uint8_t LED[] = {19, 18, 5, 17, 16, 4};
const uint8_t NUM_LEDS = sizeof(LED) / sizeof(LED[0]);

// Variables
uint8_t mode = 0;
bool display_msg = true;

void mode_msg() {
  Serial.println(
    "\nSelect Mode:\n"
    "1. Blink\n"
    "2. Alternate\n"
    "3. Running"
  );
}

#include "modes.h"

void setup() {
  // Baud rate
  Serial.begin(9600);

  // Set LEDs as outputs
  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(LED[i], OUTPUT);
    digitalWrite(LED[i], LOW);
  }
}

void loop() {
  if (display_msg) {
    mode_msg();
    display_msg = false;
  }

  // Read mode from Serial Monitor
  if (Serial.available()) {
    mode = Serial.readStringUntil('\n').toInt();
    Serial.printf("Mode %d selected\n", mode);

    // Select LED mode
    switch (mode) {
      case 1:
        led_blink();
        break;

      case 2:
        led_alt();
        break;

      case 3:
        led_run();
        break;

      default:
        Serial.println("Invalid Input");
        break;
    }

    display_msg = true;
  }
}
