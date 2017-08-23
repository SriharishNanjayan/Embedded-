/* 
 * File:   timer2.c
 * Author: Sri
 *
 * Created on August 18, 2017, 11:36 AM
 */

#include <stdio.h>
#include<xc.h>
#define LED RB0

void main()
{
    int count=0;
    PORTB=0X00;
    TRISB=0X00;
    T2CON=0b01111100;
    TMR2=0;
    PR2=0XFF;
     while(1)
    {
        while(!TMR2IF);
        TMR2IF=0;
        count++;
        if(count==244)
        {
            LED=~LED;
            count=0;
        }
    }
    
}

