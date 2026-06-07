const int POT_PIN = A0; // analog pin for potentiometer
const int LED_PIN = 9; // LED pin

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int potValue = analogRead(A0); // reads pin A0, returns 0-1023
  int brightness = map(potValue, 0, 1023, 0, 255); // scales pot reading to PWM range
  analogWrite(LED_PIN, brightness);
}
