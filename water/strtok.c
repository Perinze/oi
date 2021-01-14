#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char* str = (char*)malloc(32);
	strcpy(str, "wslnm fnmdp nmsl");
	char* substr = strtok(str, "w");
	while (substr != NULL)
	{
		printf("%s\n", substr);
		substr = strtok(NULL, "w");
	}
	return 0;
}
