#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
struct students {
	int age;//4�ֽ�--->int
	char name[20];//20�ֽ�--->char
	char sex;//1�ֽ�--->char
	//�ʳ�Ա���������͵������int--->4�ֽ�
	//�� 4 + 20 + 1 = 25 ����25/4��=0
	//��Ҫ�ڴ���룬25+1 = 26 ��26/4��=0 ��25+2=27 ��27/4��=0,25+3=28 ����28 / 4 == 0���ܱ�����
	//�������ṹ���ܴ�С��28
};

//struct students1 {
//	double age;//8�ֽ�--->double
//	char name[20];//20�ֽ�--->char
//	char sex;//1�ֽ�--->char
//	//�ʳ�Ա���������͵������double--->8�ֽ�
//	//�� 8 + 20 + 1 = 29 ����29/8��=0
//	//��Ҫ�ڴ���룬29+1 = 30 ��30/8��=0 ��29+2=31 ��31/8��=0,29+3=32 ����32 / 8 == 0���ܱ�����
//	//�������ṹ���ܴ�С��32
//};
int main()
{
	struct students s;
	printf("sizeof(s) = %d\n", sizeof(s));
	return 0;
}