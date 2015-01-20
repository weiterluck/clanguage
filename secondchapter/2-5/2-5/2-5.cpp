#include <stdio.h>

void any(char s1[], char s2[])
{
	int i, j;
	i = j = 0;

	while(s2[j] != '\0')
	{
		while(s1[i] != '\0')
		{
			if(s1[i] == s2[j])
			{
				printf("%d\n",i+1);
				break;
			}
			++i;
		}
		i = 0;
		++j;
	}
}

int main()
{
	char test1[] = "ij123ald3befpp";
	char test2[] = "3dfpq";

	any(test1,test2);

	return 0;
}