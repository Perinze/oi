#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int T;
	double pi = 3.141593;
	scanf("%d", &T);
	switch (T)
	{
		case 1:
			printf("I love Luogu!\n");
			break;
		case 2:
			printf("6 4\n");
			break;
		case 3:
			printf("3\n12\n2\n");
			break;
		case 4:
			printf("166.667\n");
			break;
		case 5:
			printf("15\n");
			break;
		case 6:
			cout << sqrt(117) << endl;
			break;
		case 7:
			printf("110\n90\n0\n");
			break;
		case 8:
			cout << 10.0 * pi << endl << 25.0 * pi << endl << 500.0 / 3.0 * pi << endl;
			break;
		case 9:
			printf("22\n");
			break;
		case 10:
			printf("9\n");
			break;
		case 11:
			cout << 100.0 / 3.0 << endl;
			break;
		case 12:
			printf("%d\n%c\n", 'M' - 'A' + 1, 'A' + 17);
			break;
		case 13:
			//printf("%lf\n", pow(4.0 / 3.0 * pi * 1064.0, 1.0 / 3.0));
			printf("16\n");
			break;
		case 14: ;
			int i, j;
			for (i = 110, j = 10; ; i--, j++)
				if (i * j >= 3500)
				{
					printf("%d\n", j);
					break;
				}
			break;
	}
	return 0;
}
