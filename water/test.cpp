#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	// init
	int mod = 101;
	srand((unsigned)time(NULL));
	int a, b, op, ans;	// 0 for +, 1 for -, 2 for *, 3 for /

	// generate random items
	a = rand() % mod;
	b = rand() % mod;
	op = rand() % 4;

	// process operator char and answer
	char opc;
	switch (op)
	{
		case 0: opc = '+'; ans = a + b; break;
		case 1: opc = '-'; ans = a - b; break;
		case 2: opc = '*'; ans = a * b; break;
		case 3: opc = '/'; ans = a / b; break;
	}

	// ask for input
	printf("%d %c %d = ", a, opc, b);
	int out;
	scanf("%d", &out);

	// judge
	if (out == ans) printf("Accepted\n");
	else printf("Wrong Answer\n");

	return 0;
}
