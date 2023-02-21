# Bare-metal FizzBuzz

## Summary
A hardware implementation of the classic interview coding problem, written in C and targeting Atmel ATTiny85. Endlessly looping around from 1 to 99 and displaying the loop value on two 7-segment displays while lighting up two LEDs (Fizz and Buzz) when the loop value is either a multiple of 3 (Fizz) or 5 (Buzz), or both.

## Design
The ATTiny85 has 5 IO pins:
- 2 pins for Fizz and Buzz LEDs
- 3 pins used to push the loop value to two 8-bit shift registers (74HC595), connected in series which, in turn, drive two (common cathode) 7-segment displays.

## Tooling
The project was developed using:
- VS Code editor
- Microchip (Atmel) compiler and C header files
- avrdude to program the ATTiny85

The project includes the task and C configuration files used by VS Code.

[Video](https://github.com/zs6dst/FizzBuzz/issues/2) of completed device
