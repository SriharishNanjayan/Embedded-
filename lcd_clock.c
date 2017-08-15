/* 
 * File:   lcd_timer.c
 * Author: Sri
 *
 * Created on August 10, 2017, 3:00 PM
 */

#include <xc.h>
#define lcd PORTD
#define lcd_rs RE0
//#define lcd_rw RE1
#define lcd_e RE2
void init();
void command(unsigned char);
void chartolcd(char);
void stringtolcd(char*);
void delay(int);
void main() {
    int hr=48,hr1=48,min1=48,min=48,sec1=48,sec=48;
    PORTD=0x00;
    PORTE=0x00;
    TRISD=0x00;
    TRISE=0x00;
    ADCON1=0x07;
    init();
    stringtolcd("HH:MM:SS");
    
    while(1)
    {
        sec++;
        if(sec==58)
        {   
            sec=48;
            sec1++;
            if(sec1==54)
            {
                sec1=48;
                min++;
                if(min==58)
                {
                    min=48;
                    min1++;
                    if(min1==54)
                    {
                        min1=48;
                        hr++;
                        if(hr==58)
                        {
                            hr=48;
                            hr1++;
                            if(hr1==50 && hr==52)
                            {
                                hr1=48;
                                hr=48;                            }
                        }
                    }
                }
            }
        }
        command(0xc6);
        chartolcd(sec1);
        command(0xc7);
        chartolcd(sec);

        command(0xc5);
        chartolcd(':');

        command(0xc3);
        chartolcd(min1);
        command(0xc4);
        chartolcd(min);

        command(0xc2);
        chartolcd(':');

        command(0xc0);
        chartolcd(hr1);
        command(0xc1);
        chartolcd(hr);
        
        
        delay(2);
        //command(0x01);
     }
}
void init()
{
    command(0x38);
    delay(1);
    command(0x01);
    delay(1);
    command(0x06);
    delay(1);
    command(0x0c);
    delay(1);
    command(0x80);
    delay(1);
}
void command(unsigned char y)
{
    lcd = y;
    RE0=0;
    RE2=1;
    delay(1);
    RE2=0;
}
void chartolcd(char x)
{
    lcd = x;
    RE0=1;
    RE2=1;
    delay(1);
    RE2=0;
}
void stringtolcd(char *c)
{
    while(*c)
    {
        chartolcd(*c++);
    }
}
void delay(int n){
    int i,j;
    for(j=0;j<n;j++)
        for(i=0;i<2000;i++);
}