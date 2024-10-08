#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
typedef int ElemType;
#define MaxSize 50

typedef struct{
	ElemType data[MaxSize];
	int top;
}SqStack;

void init_stack(SqStack& s)
{
	s.top = -1;
}

bool isEmpty(SqStack& s)
{
	//判断是否为空
	if (s.top == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool push(SqStack&s,ElemType data)
{
	
	//判断栈满
	if (s.top == MaxSize - 1)//栈顶是否等于数组最大长度-1
	{
		return false;
	}
	s.data[++s.top] = data;
	return true;
}

bool getTop(SqStack& s, ElemType& res)
{
	if (isEmpty(s))
	{
		//为空
		return false;
	}
	res = s.data[s.top];
	return true;
}

bool pop(SqStack& s)
{
	if (isEmpty(s))
	{
		//为空
		return false;
	}
	s.top--;
	return true;
}

void print(SqStack& s)
{
	while (s.top != -1)
	{
		ElemType num;
		getTop(s, num);
		pop(s);
		printf("%d ",num);
	}
	puts("");
}

//增删
int main()
{
	SqStack s;
	init_stack(s);
	//入栈
	push(s, 1);
	push(s, 2);
	push(s, 3);
	print(s);
	push(s, 2);
	push(s, 6);
	pop(s);
	print(s);
	return 0;
}