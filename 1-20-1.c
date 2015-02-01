#include <stdio.h>

#define STEP	5
#define MAXSIZE	1000

void detab(char s[])
{
	int length;
	int i;
	
	i = length = 0;
	while(s[i] != '\0')
	{
		if(s[i] == '\t')
		{
			for(; length < STEP; ++length)
				putchar(' ');
			length = 0;
		}
		else
		{
			putchar(s[i]);
			++length;
			if(length >= STEP || c == '\n')
				length = 0;
		}
		++i;
	}
}

int getline(char s[], int length)
{
	int i;
	int c;
	
	for(i = 0; i < length -2 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if(c == '\n')
	{
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

int main()
{
	char s[MAXSIZE];
	
	while(getline(s, MAXSIZE) > 0)
	{
		detab(s);
	}
	return 0;
}