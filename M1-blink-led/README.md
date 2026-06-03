# M1 — Blink LED

## What This Does
Controls the built-in LED on pin 13 using digital output.
Blinks at 1Hz (500ms on, 500ms off) by default.

## Pins Used
| Pin | Component |
|-----|-----------|
| 13  | Built-in LED (labeled L on the board) |

## What I Learned
- `pinMode()` configures a pin as INPUT or OUTPUT before using it
- `digitalWrite()` sets a pin HIGH (5V = on) or LOW (0V = off)
- `delay()` pauses execution in milliseconds — controls timing
- The HIGH delay controls on-time (flash length)
- The LOW delay controls off-time (gap between flashes)
- Together they set frequency and duty cycle

## Checkpoint Answer
Changing both delays from 500ms to 250ms doubles the frequency from 1Hz to 2Hz —
the LED blinks twice as fast because each full on/off cycle takes 500ms instead of 1000ms.

Changing only the HIGH delay shortens the flash (lower duty cycle — short bursts).
Changing only the LOW delay shortens the gap between flashes without changing flash length.

## Connection to FPGA
This on/off signal is the same concept as a clock pulse in digital logic.
Frequency and duty cycle control are the foundation of clock dividers and PWM in FPGA design.