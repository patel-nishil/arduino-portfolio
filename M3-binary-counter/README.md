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
To extract bit 2 from count: (count >> 2) & 1

- (count >> 2) shifts count right by 2 positions, moving bit 2 into the bit 0 position
- & 1 masks all other bits to 0, leaving only the value of bit 0 (which is now bit 2)
- The result is 1 if bit 2 was set, 0 if not

& 1 is a bitwise mask, not a comparison — it forces all bits except bit 0 to 0.
A comparison would use ==, which returns true/false rather than isolating a bit.

## Connection to FPGA
This is a 4-bit register with a counter — one of the most fundamental
building blocks in digital design. In Verilog this would be written as
a synchronous counter clocked on a rising edge. The bit extraction logic
maps directly to signal indexing in Verilog: count[0], count[1], etc.