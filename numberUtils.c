/*
 * numberUtils.c
 *
 *  Created on: 2022Äê6ÔÂ25ÈÕ
 *      Author: Joseph
 */
#include "numberUtils.h"

int getNumberLen(int number){
    int next=number/10;
    return next?1+getNumberLen(next):1;
}

