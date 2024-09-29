#define _CRT_SECURE_NO_WARNINGS 1
/*
* 读取一个字符串，字符串可能含有空格，将字符串逆转，原来的字符串与逆转后字符串相同，输出0，
	原字符串小于逆转后字符串输出-1，大于逆转后字符串输出1。
	例如输入 hello，逆转后的字符串为 olleh，因为hello 小于 olleh，所以输出-1
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