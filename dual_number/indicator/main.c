#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int i[] = { 1,2,3,4,5 };
	char ch[] = "hello";
	int* pInt = &i;
	char* pCh = &ch;
	printf("%d\n", pInt[0]);
	printf("%c\n", pCh[0]);

	/*printf("%d\n", *pInt);
	printf("*(pInt+1) == %d\n", *(pInt + 1));

	printf("%c\n", *pCh);
	printf("*(pCh+1) == %c\n", *(pCh + 1));*/
	return 0;
}