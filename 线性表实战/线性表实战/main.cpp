#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define MAX_NUM 20
typedef int ElemType;
typedef struct {
	ElemType data[MAX_NUM];
	int len;//实际长度
}SeqList;
bool insert_list(SeqList &l,int pos,int data)
{
	if (pos<1 || pos > l.len + 1)
	{
		return false;
	}
	if (l.len == MAX_NUM)
	{
		return false;
	}
	for (int i = l.len; i >= pos ; --i)
	{
		l.data[i] = l.data[i - 1];
	}
	l.data[pos-1] = data;//位置和下标差1
	++l.len;
	return true;
}
void print_list(SeqList& l)
{
	for (int i = 0; i < l.len; ++i)
	{
		printf("%3d", l.data[i]);
	}
	printf("\n");
}
bool del_list(SeqList& l, int pos)
{
	if (pos<1 || pos > l.len)
	{
		return false;
	}
	for (int i = pos-1; i < l.len-1; ++i)
	{
		l.data[i] = l.data[i + 1];
	}
	--l.len;
	return true;
}
bool search_list(SeqList& l, int pos)
{
	if (pos<1 || pos > l.len)
		return false;
	else
		return true;
}
int main()
{
	SeqList l;
	l.data[0] = 1;
	l.data[1] = 2;
	l.data[2] = 3;
	l.len = 3;
	int insert_data = 0;
	scanf("%d", &insert_data);
	bool ret = insert_list(l, 2, insert_data);
	if (ret)
		print_list(l);
	else
		puts("false");
	int pos = 0;
	scanf("%d", &pos);
	ret = del_list(l, pos);
	if (ret)
		print_list(l);
	else
		puts("false");
	return 0;
}

//int main()
//{
//	int num = 0;
//	char ch = 0;
//	//多组输入
//	//while (scanf("%d", &num) != EOF)
//	while(scanf(" %c", &ch) == 1)
//	{
//		printf("num = %c\n", ch);
//	}
//	return 0;
//}