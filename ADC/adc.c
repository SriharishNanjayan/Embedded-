/* 
 * File:   adc.c
 * Author: Sri
 *
 * Created on August 16, 2017, 4:02 PM
 */

#include <xc.h>
#include<stdio.h>
#define lcd_e RC1
//#define lcd_rw RE1
#define lcd_rs RC0
#define lcd PORTD

void init();
void command(unsigned char);
void chartolcd(char);
void stringtolcd(char*);
void delay(int);
void adc_data(unsigned int);

void main() {
    unsigned char string[16];
    float i;
    PORTD=0x00;
    TRISD=0x00;
    TRISA=0xFF;
    //TRISB=0x00;
    TRISC=0x00;
    ADCON0=0x41;
    ADCON1=0xc0;
    init();
    //command(0x80);
    stringtolcd("VOLTMETER");
    while(1)
    {
        GO_nDONE=1;
        while(GO_nDONE);
        i=ADRESH<<8;
        i=i+ADRESL;
        i=i*0.00489;
        sprintf(string,"%.2f",i);
        command(0xc0);
        stringtolcd(string);
        command(0xc5);
        stringtolcd("V");
        //adc_data(i);
    }
}
/*void adc_data(unsigned int adc_val)
{
    int j,k;
    unsigned int adc[3];
    for(j=0;j<=3;j++)
    {
        adc[j]=adc_val%10;
        adc_val=adc_val/10;
    }
   
    for(k=3;k>=0;k--)
    {
        stringtolcd(adc[k]);
    }
}*/
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
    lcd=y;
    lcd_rs=0;
    lcd_e=1;
    delay(1);
    lcd_e=0;
}
void chartolcd(char x)
{
    lcd=x;
    lcd_rs=1;
    lcd_e=1;
    delay(1);
    lcd_e=0;
}
void stringtolcd(char *c)
{
    while(*c)
    {
        chartolcd(*c++);
    }
}
void delay(int n)
{
    int i,j;
    for(j=0;j<n;j++)
        for(i=0;i<2000;i++);
}

