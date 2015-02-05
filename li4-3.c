#include <stdio.h>
#include <stdlib.h>  // use atof()
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAXSIZE	100
#define NUMBER	'0'
#define NAME	'n'

double atof(char s[]);
void push(double f);
double pop(void);
int getop(char s[]);
int getch(void);
void ungetch(int c);
void clear(void);
void mathfnc(char s[]);

int main()
{
	int Type;
	int i, var = 0;
	double op1, op2, v;
	char s[MAXSIZE];
	double variable[26];

	for(i = 0; i < 26; i++)
		variable[i] = 0.0;
	while((Type = getop(s)) != EOF)
	{
		switch(Type)
		{
			case NUMBER:
				push(atof(s));
				break;
			case NAME:
				mathfnc(s);
				break;
			case '*':
				push(pop() * pop());
				break;
			case '+':
				push(pop() + pop());
				break;
			case '/':
				op2 = pop();
				if(op2 != 0.0)
					push(pop() / op2);
				else
					printf("error: zero divisor\n");
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '%':
				op2 = pop();
				if(op2 != 0.0)
					push(fmod(pop(), op2));
				else
					printf("error: zero divisor\n");
				break;
			case '?':
				op2 = pop();
				printf("\t%.8g\n", op2);
				push(op2);
				break;
			case 'c':
				clear();
				break;
			case 'd':
				op2 = pop();
				push(op2);
				push(op2);
				break;
			case 's':
				op1 = pop();
				op2 = pop();
				push(op1);
				push(op2);
				break;
			case '=':
				pop();
				if(var >= 'A' && var <= 'Z')
					variable[var - 'A'] = pop();
				else
					printf("error: no variable name\n");
				break;
			case '\n':
				v = pop();
				printf("\t%.8g\n", v);
				break;
			default:
				if(Type >= 'A' && Type <= 'Z')
					push(variable[Type - 'A']);
				else if(Type == 'v')
					push(v);
				else
					printf("error: unkown command %s\n", s);
				break;
		}
		var = Type;
	}
	return 0;
}

double atof(char s[])
{
	double value, power;
	int i, sign, exp;

	for(i = 0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-') ? -1 : 1;
	if(s[i] == '+' || s[i] == '-')
		i++;
	for(value = 0.0; isdigit(s[i]); i++)
		value = 10 * value + (s[i] - '0');
	if(s[i] == '.')
		i++;
	for(power = 1.0; isdigit(s[i]); i++)
	{
		value = 10 * value + (s[i] - '0');
		power *= 10; 
	}
	value = sign * value / power;

	if(s[i] == 'e' || s[i] == 'E')
	{
		i++;
		sign = (s[i] == '-') ? -1 : 1;
		if(s[i] == '+' || s[i] == '-')
			i++;
		for(exp = 0; isdigit(s[i]); i++)
			exp = 10 * exp + (s[i] - '0');
		if(sign == 1)
			while(exp--)
				value *= 10;
		else
			while(exp--)
				value /= 10;
	}
	return value;
}

#define MAXVAL	100

int sp = 0;
double val[MAXVAL];

void push(double f)
{
	if(sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
	if(sp > 0)
		return val[--sp];
	else
	{
		printf("error: stack empty\n");
		return 0.0;
	}
}

int getop(char s[])
{
	int i, c;

	while((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	i = 0;
	if(islower(c))
	{
		while(islower(s[++i] = c = getch()))
			;
		s[i] = '\0';
		if(c != EOF)
			ungetch(c);
		if(strlen(s) > 1)
			return NAME;
		else
			return c;
	}
	if(!isdigit(c) && c != '.' && c != '-')
		return c;
	if(c == '-')
		if(isdigit(c = getch()) || c == '.')
			s[++i] = c;
		else
		{
			if(c != EOF)
				ungetch(c);
			return '-';
		}
	if(isdigit(c))
		while(isdigit(s[++i] = c = getch()))
			;
	if(c == '.')
		while(isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if(c != EOF)
		ungetch(c);
	return NUMBER;
}

#define BUFSIZE	100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if(bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

void clear(void)
{
	sp = 0;
}

void mathfnc(char s[])
{
	double op2;

	if(strcmp(s, "sin") == 0)
		push(sin(pop()));
	else if(strcmp(s, "cos") == 0)
		push(cos(pop()));
	else if(strcmp(s, "exp") == 0)
		push(exp(pop()));
	else if(strcmp(s, "pow") == 0)
	{
		op2 = pop();
		push(pow(pop(), op2));
	}
	else
		printf("error: %s not supported\n" , s);
}
