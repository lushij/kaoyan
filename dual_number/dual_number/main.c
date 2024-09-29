#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//int main()
//{
//	int num = 0;
//	int nums[1024] = { 0 };
//	int flag = 1;
//	while (scanf("%d", &num))
//	{
//		int i = 0;
//		while (num)
//		{
//			nums[i++] = num % 10;
//			num /= 10;
//		}
//		for (int j = 0; j < i / 2; j++)
//		{
//			if (nums[j] != nums[i - 1 - j])
//			{
//				flag = 0;
//				break;
//			}
//		}
//		flag ? printf("yes\n") : printf("no\n");
//	}
//	return 0;
//}

int main()
{
	//版本2
	char ch[1024] = { 0 };
	scanf("%s", ch);
	int len = strlen(ch);
	int flag = 1;
	for (int i = 0; i < len / 2; i++)
	{
		if (ch[i]!=ch[len - 1 - i])//字符可以==比较，字符串不可以==比较，要用strcmp函数
		{
			flag = 0;
			break;
		}
	}
	flag ? printf("yes\n") : printf("no\n");
	return 0;
}