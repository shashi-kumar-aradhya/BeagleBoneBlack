#include <stdio.h>

//#include "clock.h"


void byte_to_binary( int x )
{
	int y;
	long long z;
	for (z=1LL<<sizeof(int)*8-1,y=0; z>0; z>>=1,y++)
	{
		if  ((x & z) == z) 
			printf("%c",'1');
		else
			printf("%c",'0');
	}

	return ;
}


int main()
{
	int a = 0x7c;
	printf("A = ");
	byte_to_binary(a);
	printf("\n");
	printf("B = "); 
	byte_to_binary(~a);
	printf("\n");
	//	printf("size = %ld\n",sizeof(CM_MODULE_REG));
	return 0;
}
