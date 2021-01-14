#include <stdio.h>

int main()
{
	int h, m, s;
	scanf("%d:%d:%d", &h, &m, &s);
	int time = h * 3600 + m * 60 + s;
	time++;
	time %= 86400;
	printf("%02d:%02d:%02d\n", time / 3600, time % 3600 / 60, time % 60);
	return 0;
}
