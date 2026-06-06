<<<<<<< HEAD
// M2 — Button + LED with Debounce
// Concept: digitalRead() reads pin voltage — HIGH or LOW.
// Problem: physical buttons bounce — one press sends many rapid signals.
// Solution: debounce — only register a press if the signal is stable for 50ms.

const int BUTTON_PIN = 2;
const int LED_PIN = 8;
const int DEBOUNCE_DELAY = 50; // milliseconds signal must be stable to count

int ledState = LOW;             // current LED state (starts off)
int lastButtonReading = HIGH;   // last raw reading from the button pin

unsigned long lastDebounceTime = 0; // when the button signal last changed
int lastStableState = HIGH;         // last confirmed stable button state

void setup() {
  // INPUT_PULLUP enables the Arduino's internal resistor
  // This means the pin reads HIGH by default, LOW when button is pressed
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, ledState);

  Serial.begin(9600); // open serial monitor to watch what's happening
}

void loop() {
  int currentReading = digitalRead(BUTTON_PIN);

  // If the raw reading changed, reset the debounce timer
  if (currentReading != lastButtonReading) {
    lastDebounceTime = millis(); // record the time of the change
  }

  // If the signal has been stable for longer than DEBOUNCE_DELAY, trust it
  if ((millis() - lastDebounceTime) > DEBOUNCE_DELAY) {

    // Only act if the stable state actually changed
    if (currentReading != lastStableState) {
      lastStableState = currentReading;

      // Button pressed = LOW (because of INPUT_PULLUP)
      if (lastStableState == LOW) {
        ledState = !ledState;           // toggle LED
        digitalWrite(LED_PIN, ledState);
        Serial.println("Button pressed — LED toggled");
      }
    }
  }

  lastButtonReading = currentReading; // save raw reading for next loop
}
=======
// M2 — Button + LED with Debounce
// Concept: digitalRead() reads pin voltage — HIGH or LOW.
// Problem: physical buttons bounce — one press sends many rapid signals.
// Solution: debounce — only register a press if the signal is stable for 50ms.

const int BUTTON_PIN = 2;
const int LED_PIN = 8;
const int DEBOUNCE_DELAY = 50; // milliseconds signal must be stable to count

int ledState = LOW;             // current LED state (starts off)
int lastButtonReading = HIGH;   // last raw reading from the button pin

unsigned long lastDebounceTime = 0; // when the button signal last changed
int lastStableState = HIGH;         // last confirmed stable button state

void setup() {
  // INPUT_PULLUP enables the Arduino's internal resistor
  // This means the pin reads HIGH by default, LOW when button is pressed
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, ledState);

  Serial.begin(9600); // open serial monitor to watch what's happening
}

void loop() {
  int currentReading = digitalRead(BUTTON_PIN);

  // If the raw reading changed, reset the debounce timer
  if (currentReading != lastButtonReading) {
    lastDebounceTime = millis(); // record the time of the change
  }

  // If the signal has been stable for longer than DEBOUNCE_DELAY, trust it
  if ((millis() - lastDebounceTime) > DEBOUNCE_DELAY) {

    // Only act if the stable state actually changed
    if (currentReading != lastStableState) {
      lastStableState = currentReading;

      // Button pressed = LOW (because of INPUT_PULLUP)
      if (lastStableState == LOW) {
        ledState = !ledState;           // toggle LED
        digitalWrite(LED_PIN, ledState);
        Serial.println("Button pressed — LED toggled");
      }
    }
  }

  lastButtonReading = currentReading; // save raw reading for next loop
}
>>>>>>> 3aab019 (M1: Blink LED — digital output and timing)
