#include<stdio.h>
void l()
{
	int i;
	while(1)
	{
	i++;
        i=i+1000;
	i=i*i;
	i=i*i;
	l();		
	}
}
void main()
{l();
}
