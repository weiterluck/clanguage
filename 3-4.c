#include <stdio.h>
#define ABS(x)	((x) < 0 ? -(x) : (x))
#define MAXSIZE	1000

void reverse(char s[]);
void itoa(int n, char s[]);

void itoa(int n, char s[])
{
	int i, sign;

	sign = n;	
	i = 0;
	do
	{
		s[i++] = ABS(n % 10) + '0';
	}while((n /= 10) != 0);
	if(sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

void reverse(char s[])
{
	int i, j;
	char temp;

	i = j = 0;
	while(s[i] != '\0')
		++i;
	--i;
	if(s[i] == '\n')
		--i;
	while( j < i)
	{
		temp = s[j];
		s[j] = s[i];
		s[i] = temp;
		--i;
		++j;
	}
}

int main()
{
	int n;
	char s[MAXSIZE];
	scanf("%d %s", &n, s);
	printf("%d \n%s\n", n, s);
	itoa(n, s);
	printf("%d\n%s\n", n, s);
	printf("hello!\n");
	return 0;
}
