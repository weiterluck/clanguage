#include <stdio.h>

int main()
{
	float fahr,celsius;
	float lower,upper,step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;
	printf("this is f to c:\n");
	printf("  F     C\n");
	while(fahr <= upper)
	{
		celsius = (5.0/9.0)*(fahr - 32.0);
		fahr += step;
		printf("%3.0f %6.1f\n",fahr,celsius);
	}
	return 0;
}
