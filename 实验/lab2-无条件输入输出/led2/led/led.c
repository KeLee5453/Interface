#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<bios.h>
#include<ctype.h>
#include<process.h>
void main()
{
long i,k;
for(i=0;1;i++)
{
if(i>=256)
i-=256;
for(k=0;k<10000000;k++);
outp(0x3002,0x00+i );

}




}