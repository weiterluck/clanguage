#include <stdio.h>

void squeeze(char s1[], char s2[])
{
	int i, j, k, spaceflag;
	i = 0;
	j = 0;
	k = 0;
	spaceflag = 0;

	while(s2[j] != '\0')
	{
		while(s1[i] != '\0')
		{
			if(s1[i] == s2[j])
				s1[i] = ' ';
			++i;
		}
		i = 0;
		++j;
	}

	i = 0;
	while(s1[i] != '\0')
	{
		/*if(s1[i] == ' ')
			spaceflag = 1;*/
		if(s1[i] != ' ')
		{
			s1[k] = s1[i];
			//spaceflag = 0;
			++k;
		}
		++i;
	}
	s1[k] = '\0';
}

int main()
{
	char test1[] = "bjc123adb55ciojj231cja 13h";
	char test2[] = "bjc";
	squeeze(test1,test2);
	printf("%s\n%s\n",test1,test2);
	return 0;
}