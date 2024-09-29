#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n = 0;
	char ch = 0;
	scanf("%d", &n);
	getchar();
	scanf("%c", &ch);
	printf("%d---%c\n", n, ch);
	return 0;
}