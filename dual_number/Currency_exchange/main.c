#define _CRT_SECURE_NO_WARNINGS 1
//ĳ���뽫���е�һ����ֵ100Ԫ������һ���10Ԫ��5Ԫ��2Ԫ��1Ԫ��ֵ��Ʊ�ӡ�
//Ҫ������40�ţ���ÿ��Ʊ������һ�š��ʣ��м��ֻ�����
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