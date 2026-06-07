# M4 — PWM LED Dimmer

## What This Does
Controls LED brightness via a potentiometer. Turning the knob smoothly
varies the brightness from off to full using PWM.

## Pins Used
| Pin | Component |
|-----|-----------|
| A0  | Potentiometer wiper (middle leg) |
| 9   | LED via 220Ω resistor to GND (PWM pin) |

## Wiring Notes
- Pin 9 → 220Ω resistor → LED long leg → LED short leg → GND
- Potentiometer: left leg → 5V, middle leg → A0, right leg → GND
- Pin 9 is PWM-capable, marked with ~ on the UNO board

## What I Learned
- Potentiometer — a 3-legged component with a manually adjustable internal
  resistor that controls voltage output on the middle (wiper) leg
- PWM-enabled pins — pins marked ~ can output a variable duty cycle signal
  via analogWrite(), accepting values 0–255
- `analogRead()` — reads analog voltage on a pin, returns 0–1023
- `map(value, fromLow, fromHigh, toLow, toHigh)` — proportionally translates
  a value from one range into another

## Complex Issue
The first challenge was identifying which potentiometer leg does what — the outer
two legs connect to power and ground, and the middle wiper leg outputs a voltage
that varies as the knob turns. The second issue was physical: the potentiometer
wouldn't stay firmly seated in the breadboard while turning the dial, causing
intermittent connections and an unresponsive LED. Pressing it down firmly while
turning, or using a breadboard with tighter pin grip, resolved it.

## Connection to FPGA
Potentiometers are the first example of Analog to Digital Converters (analog data
being captured and converted into digital data) also called ADCs. FPGAs work with
dedicated ADC chips to read real-world signals like temperature, pressure, and audio
to then process digital output in hardware logic. Both microcontrollers and FPGAs use
ADCs and in this case we read a potentiometer's voltage and converted it to a number
the code can use.
