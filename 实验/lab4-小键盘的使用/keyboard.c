#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<bios.h>
#include<ctype.h>
#include<process.h>
#define IOY0 0x3038

#define  MY8255_A     IOY0 + 0x00*2
#define  MY8255_B     IOY0 + 0x01*2
#define  MY8255_C     IOY0 + 0x02*2
#define  MY8255_MODE  IOY0 + 0x03*2

void main()
{
	char output[4] = {0xe,0xd,0xb,0x7};
	int i,j,k;
	char input;
	outp(MY8255_MODE,0x82);
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
						printf("Num: %d",k);
						break;
					}
				}
			}
		}
	}
}