#include <stdio.h>

#define MAXLENGTH	1000

int main()
{
	int c;
	int blank[MAXLENGTH];
	int head,tail;
	int nonspace;
	
	nonspace = head = tail = 0;
	
	while((c = getchar()) != EOF)
	{
		if(c == '\n')
		{
			head = tail =0;
			if(nonspace)
				putchar('\n');
			nonspace = 0;
		}
		else if(c == ' ' || c == '\t')
		{
			blank[head] = c;
			++head;
		}
		else
		{
			while(head != tail)
			{
				putchar(blank[tail]);
				++tail;
			}
			putchar(c);
			nonspace = 1;
		}
	}
	return 0;
}