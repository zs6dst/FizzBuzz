// Copyright 2021 Stoffel van Aswegen
// Use of this source code is governed by the MIT licence
// that can be found in the LICENCE file


/*
* FizzBuzz.c
*
* Created: 2021/10/14 07:39:27
*
* Target uC: ATTiny85
*/

#define F_CPU 1000000UL //1MHz

#include <avr/io.h>
#include "util/delay.h"

#define CLOCK   (1 << PB0)
#define LATCH   (1 << PB1)
#define DATA    (1 << PB2)
#define FIZZ    (1 << PB4)  
#define BUZZ    (1 << PB3)

#define HI(P)   PORTB |= P
#define LO(P)   PORTB &= ~P

void showNumber(int);
void pushDigit(int) ;
 
//Mapping for 7-segment display (LSB is for decimal point, which is never used)
int MAP[] = {
    [0] = 0b01111110,
    [1] = 0b00001100,
    [2] = 0b10110110,
    [3] = 0b10011110,
    [4] = 0b11001100,
    [5] = 0b11011010,
    [6] = 0b11111000,
    [7] = 0b00001110,
    [8] = 0b11111110,
    [9] = 0b11001110,
};

int main(void)
{
    DDRB = 0xFF; //All pins output

    int n = 0;
    while (1)
    {
        if (++n == 100)
            n = 1;

        showNumber(n);
        
        //FizzBuzz
        if (n % 3 == 0)
            HI(FIZZ);
        else
            LO(FIZZ);
        if (n % 5 == 0)
            HI(BUZZ);
        else
            LO(BUZZ);

        _delay_ms(500);
    }
}

void showNumber(int n)
{
    int ones = n % 10;
    int tens = (n - ones) / 10;
    pushDigit(MAP[ones]);
    pushDigit(tens ? MAP[tens] : 0); //Suppress tens display when 0
    HI(LATCH);
    LO(LATCH);
}

void pushDigit(int digit)
{
    for (int pos = 7; pos >= 0; pos--)
    {
        if (!!(digit & (1 << pos)))
            HI(DATA);
        else
            LO(DATA);
        HI(CLOCK);
        LO(CLOCK);
    }
}