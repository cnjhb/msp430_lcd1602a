/*
 * StrUtils.c
 *
 *  Created on: 2022��6��25��
 *      Author: Joseph
 */
#include "strUtils.h"
#include <stdio.h>

char* numberToStr(int number,char* result){
    sprintf(result,"%d",number);
    return result;
}

