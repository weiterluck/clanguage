#include <stdio.h>

int main()
{
	int c;
	int BlankFlag = 0;
	while((c = getchar()) != EOF)
	{
		if(c == ' ')
			BlankFlag = 1;
		else if(c != ' ' && BlankFlag == 1)
			putchar(' ');

		if(c != ' ')
		{
			putchar(c);
			BlankFlag = 0;
		}
	}
}