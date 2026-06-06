// M4 — PWM LED Dimmer
// Concept: analogRead() reads a voltage (0-5V) as a value 0-1023.
// analogWrite() outputs PWM — a rapid on/off signal where the duty
// cycle controls the average voltage seen by the LED.
//
// Duty cycle = on-time / total cycle time
// analogWrite(pin, 0)   = 0% duty cycle   = LED off
// analogWrite(pin, 128) = 50% duty cycle  = LED half brightness
// analogWrite(pin, 255) = 100% duty cycle = LED full brightness
//
// map() scales one range to another:
// map(value, fromLow, fromHigh, toLow, toHigh)

const int POT_PIN = A0;  // potentiometer wiper → analog input
const int LED_PIN = 9;   // must be a PWM pin (marked ~ on the board)

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int potValue = analogRead(POT_PIN);  // read pot: 0-1023

  // Scale 0-1023 down to 0-255 for analogWrite
  int brightness = map(potValue, 0, 1023, 0, 255);

  analogWrite(LED_PIN, brightness);  // set LED brightness via PWM

  // Calculate and display duty cycle percentage
  float dutyCycle = (brightness / 255.0) * 100;

  Serial.print("Pot: ");
  Serial.print(potValue);
  Serial.print("  Brightness: ");
  Serial.print(brightness);
  Serial.print("  Duty cycle: ");
  Serial.print(dutyCycle, 1);
  Serial.println("%");

  delay(100);
}