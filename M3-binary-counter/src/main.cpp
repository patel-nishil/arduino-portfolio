const int LED_PINS[] = {8, 9, 10, 11};
const int NUM_LEDS = 4;
const int BUTTON_PIN = 2;
const int DEBOUNCE_DELAY = 50;

int ledState = LOW;
int lastButtonReading = HIGH;

unsigned long lastDebounceTime;
int lastStableState = HIGH;

int count;

void setup()
{
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  for (int i = 0; i < NUM_LEDS; i++)
  {
    pinMode(LED_PINS[i], OUTPUT);
    digitalWrite(LED_PINS[i], ledState);
  }

  Serial.begin(9600);
}

void loop()
{
  int currentReading = digitalRead(BUTTON_PIN);

  if (currentReading != lastButtonReading)
  {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > DEBOUNCE_DELAY)
  {
    if (currentReading != lastStableState)
    {
      lastStableState = currentReading;

      if(lastStableState == LOW)
      {
        Increment();
      }
    }
  }

  lastButtonReading = currentReading;
}

void Increment()
{
  count++;

  if (count > 15) count = 0;

  for (int bit = 0; bit < NUM_LEDS; bit++)
  {
    int bitValue = (count >> bit) & 1;
    digitalWrite(LED_PINS[bit], bitValue);
  }
}
