/*
 * StrUtils.c
 *
 *  Created on: 2022Äê6ÔÂ25ÈÕ
 *      Author: Joseph
 */
#include "strUtils.h"
#include <stdio.h>

char* numberToStr(int number,char* result){
    sprintf(result,"%d",number);
    return result;
}

