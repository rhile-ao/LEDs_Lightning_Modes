void led_blink() {
  // Turn all LEDs ON and OFF
  for (int count = 0; count < 5; count++) {
    for (int i = 0; i < NUM_LEDS; i++) {
      digitalWrite(LED[i], HIGH);
    }
    delay(500);

    for (int i = 0; i < NUM_LEDS; i++) {
      digitalWrite(LED[i], LOW);
    }
    delay(500);
  }
}

void led_alt() {
  // Turn ON alternate LEDs
  for (int count = 0; count < 5; count++) {
    for (int i = 0; i < NUM_LEDS; i++) {
      if (i % 2 == 0) {
        digitalWrite(LED[i], HIGH);
      } else {
        digitalWrite(LED[i], LOW);
      }
    }
    delay(500);

    for (int i = 0; i < NUM_LEDS; i++) {
      if (i % 2 == 0) {
        digitalWrite(LED[i], LOW);
      } else {
        digitalWrite(LED[i], HIGH);
      }
    }
    delay(500);
  }

  // Turn all LEDs OFF
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(LED[i], LOW);
  }
}

void led_run() {
  // Turn ON LEDs one at a time
  for (int count = 0; count < 3; count++) {
    for (int i = 0; i < NUM_LEDS; i++) {
      digitalWrite(LED[i], HIGH);
      delay(300);
      digitalWrite(LED[i], LOW);
    }
  }
}
