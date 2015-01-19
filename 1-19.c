#include <stdio.h>

#define MAXLENGTH	1000
int head = 0;
int tail = 0;
char result[MAXLENGTH];

void reverse(int c)
{	
	if(c == '\n' || c == EOF)
	{
		while(head != tail)
		{
			putchar(result[head-1]);
			--head;
		}
		putchar('\n');
		head = 0;
	}
	else
	{
		result[head] = c;
		++head;
		//putchar(c);	
	}
}

int main()
{
	int c;
	int done;
	done = 0;

	while(done == 0)
	{
		c = getchar();
		reverse(c);
		if(c == EOF)
			done = 1;
	}
	return 0;
}


/*#include <stdio.h>

#define MAXLENGTH	1000

int getline(char s[], int limit)
{
	int i;
	int c;
	for(i = 0; i<limit-1 && (c=getchar())!=EOF && c != '\n'; i++)
		s[i] = c;
	if(c == '\n')
	{
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void reverse(char s[], char result[], int limit)
{
	int i, j;
	i = 0;
	j = limit - 1;
	while(i < limit && j >= 0)
	{
		result[i] = s[j];
		++i;
		--j;
	}
	for(i = 0; i < limit - 1; i++)
		s[i] = result[i];
	s[i] = '\0';
}

int main()
{
	char now[MAXLENGTH];
	char result[MAXLENGTH];
	int length;
	
	while((length = getline(now,MAXLENGTH)) > 0)
	{
		reverse(now, result,length);
		printf("%d:%s",length,now);
	}
	return 0;
}

void reverse(int c)
{
	int head, tail;
	char result[MAXLENGTH];
	head = tail = 0;
	
	if(c != '\n' || c != EOF)
	{
		result[head] = c;
		++head;
	}
	else
	{
		while(head != tail)
		{
			putchar(result[head]);
			--head;
		}
		head = 0;
	}
}

int main()
{
	int c;
	int done;
	while(done == 0)
	{
		c = getchar();
		reverse(c);
		if(c == EOF)
			done = 1;
	}
	return 0;
}*/