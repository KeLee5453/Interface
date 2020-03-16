//T8255-1.c
//8255并口控制器应用实验  A口输入，B口输出

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <bios.h>
#include <ctype.h>
#include <process.h>

void key(void);
void delay(int time);
//****************根据查看配置信息修改下列符号值*******************
#define  IOY0         0x3000
//*****************************************************************
#define  MY8255_A     IOY0 + 0x00*2
#define  MY8255_B     IOY0 + 0x01*2
#define  MY8255_C     IOY0 + 0x02*2
#define  MY8255_MODE  IOY0 + 0x03*2

void main()
{
	char a;
	char buff[9];
	int b=0x00;
	outp(MY8255_MODE, 0x82);
	
	while(1)
	{
	  int i;
	   delay(5000);
		b=b+1;
		outp(MY8255_A, b);
		a = inp(MY8255_B);
		itoa(a,buff,2);
		printf("%08s\n",buff);
		
		//key();
	}
}

void key(void)
{
	if (bioskey(1) != 0)
	{
		exit(0);
	}
}
void delay(int time)
{
	int t;
	for(t=0;t<time;t++)
	{
		int i;
		for(i=0;i<0x5000;i++)
		{
			;
		}
	}
}