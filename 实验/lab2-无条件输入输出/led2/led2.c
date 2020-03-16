#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<bios.h>
#include<ctype.h>
#include<process.h>
void main()
{
long p;
p=inp(0x3006);
outp(0x3000,p);
}