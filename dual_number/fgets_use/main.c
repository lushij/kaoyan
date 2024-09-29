#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void change_ch(char* str)
{
	str[0] = 'H';
}
int main()
{
	/*char ch[5];
	fgets(ch, 5, stdin);
	printf("%s\n", ch);*/
	/*char ch[] = { 'h','e','l','l','o' };
	char ch2[] = "word";
	printf("ch = %s\n",ch);//erro
	printf("ch2 = %s\n", ch2);*/

	char ch[] = "hello";
	change_ch(ch);
	printf("%s\n", ch);
	return 0;
}