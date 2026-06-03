# M2 — Button + LED

## What This Does
Press a button to toggle an LED on/off. Software debounce ensures
one physical press = one toggle, not multiple.

## Pins Used
| Pin | Component |
|-----|-----------|
| 2   | Push button (INPUT_PULLUP) |
| 8   | LED (220Ω resistor to GND) |

## Wiring Notes
- Button straddles the center gap of the breadboard
- Pin 2 connects to one side of the gap, GND to the other side
- LED long leg → resistor → pin 8 / LED short leg → GND

## What I Learned
- `digitalRead()` reads HIGH or LOW from a pin
- INPUT_PULLUP enables an internal resistor — pin reads HIGH by default, LOW when pressed
- Contact bounce: physical button contacts bounce 5–20 times per press,
  sending multiple rapid signals that look like separate presses to the Arduino
- Debounce fix: only trust a reading if it has been stable for 50ms —
  by then the mechanical bouncing has stopped
- `millis()` returns ms since the Arduino powered on — used for non-blocking timing

## Checkpoint Answer
Contact bounce is a mechanical issue — when a button is pressed, the metal contacts
physically bounce off each other 5–20 times before settling, producing multiple
HIGH/LOW signals from a single press. Without debounce, the toggle logic fires on
every bounce, leaving the LED in an unpredictable state.

This is different from digital logic propagation delay (tpd/tcd), where the output
temporarily undefined but always reaches the correct final value on its own.
Contact bounce never self-corrects — it requires software filtering.

## Connection to FPGA
Input conditioning in digital logic solves the same problem — noisy real-world
signals must be filtered before a digital system can act on them reliably.
In FPGA design, debounce logic is typically one of the first modules written
for any project that takes physical button input.