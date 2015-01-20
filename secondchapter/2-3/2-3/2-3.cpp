#include <stdio.h>

int HexToInt(int c)
{
	char h[] = "aAbBcCdDeEfF";
	int i = 0;
	int answer = 0;

	while(h[i] != '\0' && answer == 0)
	{
		if(c == h[i])
		{
			answer = 10 + i/2;
		}
		++i;
	}
	return answer;
}

unsigned int htoi(char s[])
{
	int answer;
	int i;
	int hexval;
	int valflag = 1;
	hexval = i = answer = 0;

	if(s[i] == '0')
	{
		++i;
		if(s[i] == 'x' || s[i] == 'X')
			++i;
	}

	while(valflag && s[i] != '\0')
	{
		answer = answer * 16;
		if(s[i] >= '0' && s[i] <= '9')
			answer += s[i] - '0';
		else
		{
			hexval = HexToInt(s[i]);
			if(hexval == 0)
				valflag = 0;
			else
				answer += hexval;
		}
		++i;
	}
	if(!valflag)
		answer = 0;
	return answer;
}

int main()
{
	unsigned int answer = 0;
	int testlen = 0;
	int thistest;
	char *test[] = {"0X1","0x031","ABC1","0100","0F9","ABcda023","0ae74","568","023g5"};

	testlen = sizeof test / sizeof test[0];
	for(thistest = 0; thistest < testlen; thistest++)
	{
		answer = htoi(test[thistest]);
		printf("%s: %d\n",test[thistest],answer);
	}
	return 0;
}