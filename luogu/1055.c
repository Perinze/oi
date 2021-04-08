#include <stdio.h>
#include <stdlib.h>

char* read()
{
	int i, p = 0; char c;
	char* res = (char*)malloc(10);
	for (i = 0; i < 13; i++)
	{
		c = getchar();
		if (c == '-') continue;
		else if (c == 'X') res[p++] = 10;
		else res[p++] = c - '0';
	}
	return res;
}

int main()
{
	char* code = read();
	int correct = 0;
	int i;
	for (i = 0; i < 9; i++) correct += code[i] * (i + 1);
	if (code[9] == correct % 11) printf("Right");
	else
	{
		code[9] = correct % 11;
		for (i = 0; i < 10; i++)
		{
			if (i == 1 || i == 4 || i == 9) putchar('-');
			if (i == 9 && code[9] == 10) putchar('X');
			else putchar(code[i] + '0');
		}
	}

	return 0;
}
