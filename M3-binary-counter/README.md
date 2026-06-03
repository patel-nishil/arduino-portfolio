# M3 — Binary LED Counter

## What This Does
Four LEDs display a 4-bit binary counter incrementing from 0 (0000) to 15 (1111),
then repeating. Each LED represents one bit — bit 0 (LSB) on the right to bit 3 (MSB) on the left.

## Pins Used
| Pin | Bit | Position |
|-----|-----|----------|
| 8   | 0   | LSB (rightmost) |
| 9   | 1   |  |
| 10  | 2   |  |
| 11  | 3   | MSB (leftmost) |

## Truth Table
| Count | Bit3 | Bit2 | Bit1 | Bit0 |
|-------|------|------|------|------|
| 0     | 0    | 0    | 0    | 0    |
| 1     | 0    | 0    | 0    | 1    |
| 2     | 0    | 0    | 1    | 0    |
| 3     | 0    | 0    | 1    | 1    |
| 4     | 0    | 1    | 0    | 0    |
| 5     | 0    | 1    | 0    | 1    |
| 6     | 0    | 1    | 1    | 0    |
| 7     | 0    | 1    | 1    | 1    |
| 8     | 1    | 0    | 0    | 0    |
| 9     | 1    | 0    | 0    | 1    |
| 10    | 1    | 0    | 1    | 0    |
| 11    | 1    | 0    | 1    | 1    |
| 12    | 1    | 1    | 0    | 0    |
| 13    | 1    | 1    | 0    | 1    |
| 14    | 1    | 1    | 1    | 0    |
| 15    | 1    | 1    | 1    | 1    |

## What I Learned
- Bitwise AND (&) isolates a specific bit from an integer
- Right shift (>>) moves bits toward the LSB position
- (count >> bit) & 1 extracts any single bit from a number
- Arrays of pins make it easy to control multiple outputs in a loop

## Checkpoint Answer
[fill in after answering]

## Connection to FPGA
This is a 4-bit register with a counter — one of the most fundamental
building blocks in digital design. In Verilog this would be written as
a synchronous counter clocked on a rising edge. The bit extraction logic
maps directly to signal indexing in Verilog: count[0], count[1], etc.