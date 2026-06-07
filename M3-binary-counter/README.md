# M3 — Binary LED Counter

## What This Does
A tally counter from 0–15. Each button press increments the count by 1,
displayed across 4 LEDs in binary.

## Pins Used
| Pin | Bit | Position |
|-----|-----|----------|
| 8   | 0   | LSB (rightmost) |
| 9   | 1   | |
| 10  | 2   | |
| 11  | 3   | MSB (leftmost) |
| 2   | —   | Push button (INPUT_PULLUP) |

## Wiring Notes
- Pins 8–11 → 220Ω resistor → LED long leg → LED short leg → GND
- Pin 2 → button → GND
- Button straddles the center gap — pin 2 and GND on opposite sides

## What I Learned
- `>>` right shift — moves all bits right by a given amount
- `&` bitwise AND — compares two values bit by bit, output is 1 only where both are 1
- `(count >> bit) & 1` — extracts a single bit from any position in a number
- Global variables persist between function calls — `count` lives outside `loop()` so `Increment()` can modify it

## Complex Issue
I wasn't familiar with `>>` and `&` but through a quick search found they can be
combined in a technique called bit extraction. First, `>>` shifts the target bit
down to position 0, then `&` masks everything else away, leaving only that bit's
value. This let me isolate each bit of `count` individually and drive the
corresponding LED ON or OFF based on it.

## Connection to FPGA
Bit masking and extraction appear throughout computer science (game development,
networking, algorithms) and are especially fundamental in FPGA design. Data
extraction, bitstream compression, hardware cryptography, and state machine flag
registers all rely on bit masks to read and manipulate individual signals efficiently.
In this project, the same idea appears in how each LED maps to one bit of the counter
state, a direct parallel to how FPGA registers expose individual signal lines.
