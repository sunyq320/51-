	#include <reg52.h>
	typedef unsigned int u16;
	typedef unsigned u8;

	sbit lsa=P2^2;
	sbit lsb=P2^3;
	sbit lsc=P2^4;
	sbit k1=P3^1;
	sbit k2=P3^0;

    u8 code smgduan[]={0x3f,0x06,0x5b,0x4f,0x66,
  					0x6d,0x7d,0x07};

    void delay (u16 i)
    {
  		while(i--);	
    }
	u8 i=0;

	void anxianshi()
	{
		switch(i)
		{
			case(0):
				lsa=0;lsb=0;lsc=0;break;
			case(1):
				lsa=1;lsb=0;lsc=0;break;
			case(2):
				lsa=0;lsb=1;lsc=0;break;
			case(3):
				lsa=1;lsb=1;lsc=0;break;
			case(4):
				lsa=0;lsb=0;lsc=1;break;
			case(5):
				lsa=1;lsb=0;lsc=1;break;
			case(6):
				lsa=0;lsb=1;lsc=1;break;
			case(7):
				lsa=1;lsb=1;lsc=1;break;
		}
			P0=smgduan[i];
			delay(1000);
			P0=0x00;	
	}

	void main()
	{
		while(1)
		{
		 	if(k1==0)
		{
				delay(80);
				if(k1==0)
			{
				i=i+1;
			}
			while(!k1);	
			}
			if(k2==0)
			{
				delay(80);
				if(k2==0)
			{
				i=i-1;
			}
			while(!k2);
		}
		anxianshi();
		}
	}

















