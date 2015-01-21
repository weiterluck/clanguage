#include <stdio.h>

unsigned int setbits(unsigned int x, int p, int n, unsigned int y)
{
	/*����������һλΪ0����x�ĵ�pλ��ʼ��������n��λ����Ϊy�����ұߵ�n��λ��ֵ��x�������λ���ֲ���
	��x����n��λ��Ϊ0������Ϊ���䣬��y������λ��Ϊ0����n��λ�Ƶ���Ӧλ�ã��ٰ�λ��
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