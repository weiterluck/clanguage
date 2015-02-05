#include <stdio.h>
#include <ctype.h>

double atof(char s[])
{
	int i;
	int sign;
	double value, power;
	sign = 1;

	for(i = 0; isspace(s[i]); ++i)
		;
	if(s[i] == '-')
		sign = -1;
	if(s[i] == '+' || s[i] == '-')
		++i;
	for(value = 0.0; isdigit(s[i]); ++i)
		value = 10 * value + (s[i] - '0');
	if(s[i] == '.')
		i++;
	for(power = 1.0; isdigit(s[i]); ++i)
		power = 10 * power + (s[i] - '0');

}
