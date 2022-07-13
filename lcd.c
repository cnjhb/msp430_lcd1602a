/*
 * lcd.c
 *
 *  Created on: 2022��6��25��
 *      Author: Joseph
 */
#include <msp430.h>
#include "lcd.h"
#include "strUtils.h"
#include "numberUtils.h"

#define RS_L P6OUT&=~BIT1
#define RS_H P6OUT|=BIT1
#define RW_L P6OUT&=~BIT2
#define RW_H P6OUT|=BIT2
#define E_L P6OUT&=~BIT3
#define E_H P6OUT|=BIT3;

#define delay(ms) __delay_cycles((long)(500000*(double)ms/1000.0));

#define dataOut(data) P3OUT=data

void lcdInit()
{
    P6DIR |= BIT0 + BIT1 + BIT2 + BIT3;

    lcdWriteCom(0x38);
    lcdWriteCom(8);
    lcdClear();
    lcdWriteCom(6);
    lcdWriteCom(0x0c);
    lcdSetCursor(1, 1);
}

void lcdWriteCom(char com)
{
    P3DIR = 0xFF;

    E_L;
    RS_L;
    RW_L;

    dataOut(com);
    delay(1);

    E_H
    ;
    delay(5);
    E_L;
}
void lcdWriteData(char data)
{
    P3DIR = 0xFF;

    E_L;
    RS_H;
    RW_L;

    dataOut(data);
    delay(1);
    P3OUT = data;
    E_H
    ;
    delay(5);
    E_L;
}
void lcdClear()
{
    lcdWriteCom(0x01);
}

void lcdShowStr(char *str, int start)
{
    if (start > 15)
        lcdSetCursor(1, start - 16);
    else
        lcdSetCursor(0, start);
    int i = 0;
    while (str[i])
    {
        if (i + start == 16)
            lcdSetCursor(1, 0);
        lcdWriteData(str[i++]);
    }
}

void lcdShowNumber(int number, int position)
{
    char *numberStr = (char*) malloc((getNumberLen(number) + 1) * sizeof(char));
    numberToStr(number, numberStr);
    lcdShowStr(numberStr, position);
    free(numberStr);
}

void lcdSetCursor(int row, int column)
{
    lcdWriteCom(0x80 | (column + (row ? 0x40 : 0)));
}
