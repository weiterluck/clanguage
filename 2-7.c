#include <stdio.h>

unsigned int invert(unsigned int x, int p, int n)
{
	return x ^ (~(~0<<(p+1) | ~(~0<<(p+1-n))));
}

unsigned int rightrot(unsigned int x, unsigned int n)
{
	while(n > 0)
	{
		if((x & 1) == 1)
			x = (x >> 1) | ~(~0U >> 1)
		else
			x = x >> 1;
		n--;
	}
	return x;
}