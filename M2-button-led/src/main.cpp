const int LED_PIN = 8;
const int BUTTON_PIN = 2;
const int DEBOUNCE_DELAY = 50; //time between checks to determine stable state

int ledState = LOW; // current LED state
int lastButtonReading = HIGH; // stores the raw reading from last loop

unsigned long lastDebounceTime; // timestamp of the last signal change
int lastStableState; // stores the last confirmed stable button state

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  digitalWrite(LED_PIN, ledState);
}

void loop()
{
  int currentReading = digitalRead(BUTTON_PIN);

  if (currentReading != lastButtonReading)
  {
    lastDebounceTime = millis();
  }

  if((millis() - lastDebounceTime) > DEBOUNCE_DELAY)
  {
    if (currentReading != lastStableState)
    {
      lastStableState = currentReading;

      if (lastStableState == LOW)
      {
        ledState = !ledState;
        digitalWrite(LED_PIN, ledState);
      }
    }
  }

  lastButtonReading = currentReading;
}
