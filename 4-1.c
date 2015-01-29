#include <stdio.h>

int strindex(char s[], char t)
{
	int i = 0;
	int result = -1;
	while(s[i] != '\0')
	{
		if(s[i] == t)
			result = i;
		++i;
	}
	return result;
}

int main()
{
	char test[] = "abc19kajdkgaldcijh";
	char testchar = 'd';
	int position = 0;
	position = strindex(test,testchar);
	if(position != -1)
		printf("%d\n",position);
	else
		printf("No char!\n");
	return 0;
}