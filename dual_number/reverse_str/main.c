#define _CRT_SECURE_NO_WARNINGS 1
/*
* ��ȡһ���ַ������ַ������ܺ��пո񣬽��ַ�����ת��ԭ�����ַ�������ת���ַ�����ͬ�����0��
	ԭ�ַ���С����ת���ַ������-1��������ת���ַ������1��
	�������� hello����ת����ַ���Ϊ olleh����Ϊhello С�� olleh���������-1
*/
#include<stdio.h>
#include<string.h>
void reverse_str(char* str,char*reverse_strs,int len)
{
	for (int i = 0; i < len / 2; ++i)
	{
		char ch = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = ch;
	}
}

int main()
{
	char str[1024] = { 0 };
	char reverse_strs[1024] = { 0 };
	fgets(str,1023,stdin);
	int len = strlen(str);
	reverse_str(str, reverse_strs, len);
	if (strcmp(str, reverse_strs) < 0)
	{
		printf("%d\n", -1);
	}
	else if(strcmp(str, reverse_strs) > 0)
	{
		printf("%d\n", -1);
	}
	else
	{
		printf("%d\n", 0);
	}
	return 0;
}