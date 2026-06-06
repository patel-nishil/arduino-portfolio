# M2 — Button + LED

## What This Does
Toggles an LED ON and OFF each time a button is pressed, using software debounce
to ensure one physical press registers as one toggle.

## Pins Used
| Pin | Component |
|-----|-----------|
| 2   | Push button (INPUT_PULLUP) |
| 8   | LED via 220Ω resistor to GND |

## Wiring Notes
- Pin 2 → button → GND
- Pin 8 → 220Ω resistor → LED long leg → LED short leg → GND
- Button must straddle the center gap of the breadboard — pin 2 and GND on opposite sides

## What I Learned
- `digitalRead(pin)` — reads a pin as HIGH (5V) or LOW (0V)
- `INPUT_PULLUP` — enables the Arduino's internal pull-up resistor; pin reads HIGH
  by default and LOW when the button is pressed
- `millis()` — returns total milliseconds elapsed since the Arduino powered on;
  used for non-blocking timing instead of delay()
- `lastButtonReading` must be updated at the end of every loop or the debounce
  timer resets every iteration and the stable state check never triggers

## Complex Issue
Contact bounce is a mechanical issue where button contacts physically bounce off
each other 5–20 times per press, producing rapid HIGH/LOW signals before settling.
The debounce fix records a timestamp when the signal changes, then waits 50ms —
if the signal is still the same after 50ms, it is treated as a real state change.
The key insight is that `lastButtonReading` must be updated at the end of every loop.
Without it, the timer resets every iteration because the code always thinks the
signal just changed, so the 50ms stability window never passes.

## Connection to FPGA
Both microcontrollers and FPGAs interface with the physical world and must filter
out noise before acting on input signals. In FPGA design, a debounce module is
typically one of the first components written for any project using physical buttons
— the same problem, solved in Verilog instead of C++.
