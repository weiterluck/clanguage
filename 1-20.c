#include <stdio.h>
#define STEP	5

int position = 0;
int main()
{
	int c;
	int i;
	
	while((c = getchar()) != EOF)
	{
		if(c == '\t')
		{
			for(i = STEP - position; i > 0; i--)
				putchar(' ');
		}
		else
		{
			putchar(c);
			++position;
			if(position >= STEP || c == '\n')
				position = 0;
		}
	}
	return 0;
}