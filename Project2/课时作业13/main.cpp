#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
typedef int ElemType;
#define MaxSize 50
//包含栈和循环队列的知识

//栈
typedef struct {
	ElemType data[MaxSize];
	int top;
}SqStack;

//循环队列
typedef struct {
	ElemType data[5];
	int front, rear;
}Que;

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

bool push(SqStack& s, ElemType data)
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
		printf("%2d", num);
	}
	puts("");
}

void init_que(Que& q)
{
	q.front = q.rear = 0;
}
bool isEmptyQue(Que& q)
{
	//判断队列是否为空
	if (q.front == q.rear)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isFull(Que& q)
{
	if ((q.rear + 1) % 5 == q.front)
	{
		//判断队列是否满
		return true;
	}
	else
	{
		return false;
	}
}

//入队
bool push_que(Que& q, ElemType num)
{
	if (isFull(q))
	{
		return false;
	}
	q.data[q.rear] = num;
	q.rear = (q.rear + 1) % 5;//此处的5对应题目中的最大容量
	return true;
}

//出队
bool queGetFront(Que& q, ElemType& num)
{
	if (isEmptyQue(q))
	{
		return false;
	}
	num = q.data[q.front];
	q.front = (q.front + 1) % 5;//此处的5对应题目中的最大容量
	return true;
}
//增删
int main()
{
	SqStack s;
	int num = 0;
	init_stack(s);
	for (int i = 0; i < 3; i++)
	{
		scanf("%d", &num);
		push(s, num);
	}
	print(s);
	Que q;
	init_que(q);
	for (int i = 0; i < 5; ++i)
	{
		scanf("%d", &num);
		bool ret = push_que(q, num);
		if (!ret)
		{
			printf("false\n");
		}
	}
	while (!isEmptyQue(q))
	{
		ElemType num;
		queGetFront(q, num);
		printf("%2d", num);
	}
	puts("");
	return 0;
}