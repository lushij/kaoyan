#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n = 0;
	scanf("%d", &n);
	//因为接下来要存入的字符串，故要清楚此时缓冲区残留的'\n'
	getchar();
	char* p = (char*)malloc(n);
	fgets(p, n, stdin);
	printf("%s\n", p);
	free(p);
	return 0;
}