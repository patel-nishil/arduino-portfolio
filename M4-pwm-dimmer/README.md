# M4 — PWM LED Dimmer

## What This Does
A potentiometer controls LED brightness via PWM. Turning the pot
smoothly varies the duty cycle from 0% (off) to 100% (full brightness).

## Pins Used
| Pin | Component |
|-----|-----------|
| A0  | Potentiometer wiper (analog input) |
| 9   | LED via 220Ω resistor (PWM output) |

## Wiring Notes
- Pot: left leg → 5V, middle leg → A0, right leg → GND
- LED: long leg → resistor → pin 9, short leg → GND
- Pin 9 is PWM-capable (marked ~ on the UNO board)

## What I Learned
- analogRead() returns 0–1023 representing 0–5V on an analog pin
- analogWrite() outputs PWM — only works on pins marked ~
- Duty cycle = on-time / total period — controls average power to the LED
- map() scales a value from one range to another
- PWM pins on UNO: 3, 5, 6, 9, 10, 11

## Checkpoint Answer
[fill in after answering]

## Connection to FPGA
PWM generation in FPGAs uses a counter and a comparator — when the
counter value is below the threshold, output is HIGH; above it, LOW.
The threshold sets the duty cycle. Clock dividers use the same principle
to generate slower clocks from a fast master clock.