// M1 — Blink LED
// Concept: digitalWrite() controls pin voltage — HIGH = 5V, LOW = 0V.
// delay() pauses the program for a set number of milliseconds.
// The result is a repeating HIGH/LOW signal — exactly like a clock pulse.

const int BUILTIN_LED = 13;  // built-in LED pin
const int EXTERNAL_LED = 8;  // external LED pin (with 220 ohm resistor to GND)

void setup() {
  // pinMode tells the Arduino whether a pin is an INPUT or OUTPUT
  // We're sending voltage out, so both pins are OUTPUT
  pinMode(BUILTIN_LED, OUTPUT);
  pinMode(EXTERNAL_LED, OUTPUT);
}

void loop() {
  // Blink built-in LED at 1Hz (on 500ms, off 500ms = 1 full cycle per second)
  digitalWrite(BUILTIN_LED, HIGH);
  delay(500);
  digitalWrite(BUILTIN_LED, LOW);
  delay(500);

  // Blink external LED at 2Hz (on 250ms, off 250ms = 2 full cycles per second)
  // Notice: faster blink = higher frequency signal
  digitalWrite(EXTERNAL_LED, HIGH);
  delay(250);
  digitalWrite(EXTERNAL_LED, LOW);
  delay(250);
}