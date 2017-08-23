/* 
 * File:   timer1.c
 * Author: Sri
 *
 * Created on August 18, 2017, 11:31 AM
 */

#include <stdio.h>
#include<xc.h>
#define LED RB0
void main()
{
    int count=0;
    PORTB=0x00;
    TRISB=0x00;
    T1CON=0b00110001;
    TMR1H=0X00;
    TMR1L=0X00;
    while(1)
    {
        while(!TMR1IF);
        TMR1IF=0;
        count++;
        if(count==2)
        {
            LED=~LED;
            count=0;
        }
    }
}

