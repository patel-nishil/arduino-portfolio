// M3 — Binary LED Counter
// Concept: bit manipulation. Extract individual bits from an integer
// and use each bit to drive one LED. This is a 4-bit register in hardware.
//
// Bitwise AND (&): isolates a specific bit
//   example: 0b1010 & 0b0001 = 0b0000 (bit 0 is 0)
//            0b1010 & 0b0010 = 0b0010 (bit 1 is 1)
//
// Right shift (>>): moves bits to the right
//   example: 0b1010 >> 1 = 0b0101 (shifted one position right)
//
// Combined: (count >> n) & 1 extracts bit n from count

const int LED_PINS[] = {8, 9, 10, 11}; // bit 0 (LSB) to bit 3 (MSB)
const int NUM_LEDS = 4;
const int DELAY_MS = 500; // time between counts

void setup() {
  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(LED_PINS[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  for (int count = 0; count <= 15; count++) {

    // Extract each bit and drive the corresponding LED
    for (int bit = 0; bit < NUM_LEDS; bit++) {
      int bitValue = (count >> bit) & 1; // extract bit 'bit' from count
      digitalWrite(LED_PINS[bit], bitValue);
    }

    // Print binary representation to serial monitor
    Serial.print("Count: ");
    Serial.print(count);
    Serial.print("  Binary: ");
    for (int bit = NUM_LEDS - 1; bit >= 0; bit--) {
      Serial.print((count >> bit) & 1);
    }
    Serial.println();

    delay(DELAY_MS);
  }
}