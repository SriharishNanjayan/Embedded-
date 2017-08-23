 /*
 * File:   timer0.c
 * Author: Sri
 *
 * Created on August 18, 2017, 11:25 AM
 */

#include <xc.h>
#define LED RB0
void main()
{
    int count=0;
    PORTB=0x00;
    TRISB=0x00;
    TMR0=0;
    //OPTION_REG=0x07;
    T0CS=0;
    T0SE=0;
    PSA=0;
    PS0=1;
    PS1=1;
    PS2=1;
    while(1)
    {
        while(!T0IF);
        T0IF=0;
        count++;
        if(count==15)
        {
            LED=~LED;
            count=0;
        }
    }

}

