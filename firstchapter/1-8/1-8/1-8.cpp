#include <stdio.h>

int main()
{
	int CharCount = 0;
	int BlankCount = 0;
	int TabCount = 0;
	int LineCount = 0;
	int done = 0;
	int c,lastchar;
	while(done == 0)
	{
		c = getchar();

		if(c == ' ')
			++BlankCount;
		else if(c == '\t')
			++TabCount;
		else if(c == '\n')
			++LineCount;
		else
			++CharCount;

		if(c == EOF)
		{
			if(lastchar != '\n')
				++LineCount;
			done = 1;
		}
		lastchar = c;
	}
	printf("char=%d,blank=%d,tab=%d,line=%d\n",CharCount,BlankCount,TabCount,LineCount);
	return 0;
}