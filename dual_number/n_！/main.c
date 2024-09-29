#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main()
{
	/*int num = 0;
	scanf("%d", &num);
	int ret = 1;
	for (int i = 1; i <= num; i++)
		ret *= i;
	printf("%d\n", ret);*/
	//char a = 'a';
	//char b = 'b';
	//char c = 'c';
	//printf("%d\n", a > b);
	//printf("%d\n", a < b);
	//printf("%d\n", a == b);
	char ch[] = "helloword";
	char ch1[128] = { 0 };
	//ch1 = "helllo";//erro
	strcpy(ch1, "helloword");
	char* str = (char*)malloc(128);
	str = "nihao";
	return 0;
}

