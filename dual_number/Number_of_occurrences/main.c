#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int num[110] = { 0 };
	int cnt = 0;
	int ret = 0;
	scanf("%d", &cnt);
	for (int i = 0; i < cnt; ++i)
	{
		scanf("%d",&num[i]);
		num[i] == 2 ? ret++ : ret;
	}
	printf("%d\n", ret);
	return 0;
}