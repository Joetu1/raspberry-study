
/**
 * @file blink.c
 * @author Joetu (tuweidongg@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-20
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "stdio.h"
#include "wiringPi.h"

int main(int argc, char const *argv[])
{
    wiringPiSetup();
    pinMode(0, OUTPUT);
    for (;;)
    {
        digitalWrite(0, HIGH);
        delay(500);
        digitalWrite(0, LOW);
        delay(500);
    }
    return 0;
}
