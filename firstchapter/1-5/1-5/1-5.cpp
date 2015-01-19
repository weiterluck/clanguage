#include <stdio.h>

int main()
{
	float celsius,fahr;
	float lower,upper,step;

	lower = 0;
	upper = 300;
	step = 20;
	fahr = upper;

	for(fahr;fahr >= lower;fahr -= step)
	{
		celsius = (5.0/9.0)*(fahr + 32.0);
		printf("%3.0f %6.1f\n",fahr,celsius);
	}
	return 0;
}