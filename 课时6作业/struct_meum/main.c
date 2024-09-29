#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
struct students {
	int age;//4字节--->int
	char name[20];//20字节--->char
	char sex;//1字节--->char
	//故成员变量的类型的最大是int--->4字节
	//则 4 + 20 + 1 = 25 但是25/4！=0
	//故要内存对齐，25+1 = 26 但26/4！=0 ，25+2=27 但27/4！=0,25+3=28 而且28 / 4 == 0故能被整除
	//因此这个结构体总大小是28
};

//struct students1 {
//	double age;//8字节--->double
//	char name[20];//20字节--->char
//	char sex;//1字节--->char
//	//故成员变量的类型的最大是double--->8字节
//	//则 8 + 20 + 1 = 29 但是29/8！=0
//	//故要内存对齐，29+1 = 30 但30/8！=0 ，29+2=31 但31/8！=0,29+3=32 而且32 / 8 == 0故能被整除
//	//因此这个结构体总大小是32
//};
int main()
{
	struct students s;
	printf("sizeof(s) = %d\n", sizeof(s));
	return 0;
}