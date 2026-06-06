# M1 — Blink LED

## What This Does
Blinks the built-in LED on pin 13 ON and OFF every 500ms.

## Pins Used
| Pin | Component |
|-----|-----------|
| 13  | Built-in LED (labeled L on the board) |

## Wiring Notes
No external wiring needed. The built-in LED is connected to pin 13 on the board.

## What I Learned
Arduino programs are built around two core functions — `setup()` runs once on power-on
for initialization, and `loop()` runs continuously for logic and control.

- `pinMode(pin, mode)` — assigns a pin as INPUT or OUTPUT before using it
- `digitalWrite(pin, value)` — sets a pin HIGH (5V) or LOW (0V)
- `delay(ms)` — pauses execution for a given number of milliseconds before moving to the next line

## Complex Issue
Coming from C++, the initial challenge wasn't the syntax — it was the mental shift from
writing programs that run start to finish, to writing programs structured around hardware.
`setup()` and `loop()` force you to think in terms of initialization and continuous state,
which reflects how real embedded systems actually operate rather than how software programs run.

## Connection to FPGA
Arduino uses C++ to bridge code and electronics — `digitalWrite()` directly controls
voltage on a physical pin. FPGAs do the same thing but at a lower level using Verilog
or VHDL, where you describe hardware behavior directly rather than writing sequential
instructions. The concept is the same: control signals in the physical world through code.
