#include <stdio.h>

unsigned int setbits(unsigned int x, int p, int n, unsigned int y)
{
	/*从右数，第一位为0，将x的第p位开始向右数的n个位设置为y的最右边的n各位的值，x的其余各位保持不变
	将x的那n个位置为0，其余为不变，将y的其余位置为0，那n个位移到相应位置，再按位与
	*/
	return ((x&((~0<<(p+1))|(~(~0<<(p+1-n))))) | ((y&~(~0<<n))<<(p+1-n)));
}

int main()
{
	int p, n;
	unsigned int i, j, k;
	
	for(i = 0; i < 1000; i += 511)
	{
		for(j = 0; j < 100; j += 37)
		{
			for(p = 0; p < 16; p++)
				for(n = 1; n <= p+1; n++)
				{
					k = setbits(i, p, n, j);
					printf("%u %d %d %u %u\n",i,p,n,j,k);
				}
		}
	}
	return 0;
}