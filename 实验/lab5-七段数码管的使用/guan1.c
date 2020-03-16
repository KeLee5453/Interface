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
	int b=0x3f;
	int out2[6]={0x3f,0x06,0x5b,0x4f,0x66,0x6d};
	int out1;
	int i,j,k;
	char output[4] = {0xe,0xd,0xb,0x7};
		char input;
    outp(MY8255_MODE, 0x82);

	while(1)
	{
		for(i=0;i<4;i++)
		{
			outp(MY8255_A,output[i]);
			input = inp(MY8255_B);
			if(input != 0xf)
			{
				for(j=0;j<4;j++)
				{
					if(input == output[j])
					{
						k = i*4+j;
						printf("Num: %d\n",k);
						break;
					}
				}
			}
		}
	

	switch(k){
	case 0:
	      out1=0x3f;
	      break;
	case 1:
	      out1=0x06;
	      break;
	case 2:
	      out1=0x5b;
	      break;
	case 3:
	      out1=0x4f;
	      break;
	case 4:
	      out1=0x66;
	      break;
	case 5:
	      out1=0x6d;
	      break;
	case 6:
	      out1=0x7d;
	      break;
	case 7:
	      out1=0x07;
	      break;
	case 8:
	      out1=0x7f;
	      break;
	case 9:
	      out1=0x6f;
	      break;
	}
	
	
	//outp(MY8255_A,0x3f);
	
	outp(MY8255_A,b);
	outp(MY8255_C,out1);
	delay(30000);
	
	
	
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