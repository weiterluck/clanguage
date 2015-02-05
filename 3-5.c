#include <stdio.h>

#define MAXSIZE	1000

void reverse(char s[]);
void itob(int n, char s[], int b);

void itob(int n, char s[], int b)
{
	int i, sign;
	i = 0;

	if((sign = n) < 0)
		n = -n;
	do
	{
		s[i++] = (n % b) <= 9 ? (n % b + '0') : (n % b + 'a' - 10 );
	}while((n /= b) > 0);
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
	while(j < i)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		--i;
		++j;
	}
}

int main()
{
	int n, b;
	char s[MAXSIZE];
	
	scanf("%d %d", &n, &b);
	itob(n, s, b);
	printf("%d,%d,%s\n", n, b, s);
	return 0;
}
