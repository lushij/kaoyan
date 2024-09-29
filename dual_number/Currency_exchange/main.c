#define _CRT_SECURE_NO_WARNINGS 1
//某人想将手中的一张面值100元的人民币换成10元、5元、2元和1元面值的票子。
//要求换正好40张，且每种票子至少一张。问：有几种换法？
#if 0
#include<stdio.h>
int main()
{
	int ret = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			for (int m = 0; m < 40; m++)
			{
				for (int n = 0; n < 40; n++)
				{
					if (m + n + i + j == 36 && 10 * i + 5 * j + m * 2 + n == 82)
					{
						ret++;
					}
				}
			}
		}
	}
	printf("%d\n", ret);
	return 0;
}
#endif
#if 0
#include<stdio.h>
int main()
{
	int ret = 0;
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 20; j++)
		{
			for (int m = 1; m <= 40; m++)
			{
				for (int n = 1; n <= 40; n++)
				{
					if (m + n + i + j == 40 && 10 * i + 5 * j + m * 2 + n == 100)
					{
						ret++;
					}
				}
			}
		}
	}
	printf("%d\n", ret);
	return 0;
}
#endif
#if 1
#include<stdio.h>
int main()
{
	int ret = 0;
	for (int i = 0; i <= 10; i++)
	{
		for (int j = 0; j <= 20; j++)
		{
			for (int m = 0; m <= 40; m++)
			{
				for (int n = 0; n <= 40; n++)
				{
					if (m + n + i + j == 40 && 10 * i + 5 * j + m * 2 + n == 100 && m>=1 && n>=1 && i>=1 &&j>=1)
					{
						ret++;
					}
				}
			}
		}
	}
	printf("%d\n", ret);
	return 0;
}
#endif