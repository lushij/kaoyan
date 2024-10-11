#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//队列先进先出
//数字版循环队列
typedef int ElemType;
#define MaxSize 20

typedef struct{
	ElemType data[MaxSize];
	int front, rear;
}Que;

void init_que(Que& q)
{
	q.front = q.rear = 0;
}

bool insert_que(Que& q, ElemType data)
{
	//入队
	//判断队列是否满
	if ((q.rear + 1) % MaxSize == q.front)
	{
		return false;
	}
	q.data[q.rear] = data;
	q.rear = ( q.rear + 1 )% MaxSize;
	return true;
}

bool pop_que(Que& q, ElemType& data)
{
	//出队
	//判断是否为空
	if (q.front == q.rear)
	{
		return false;
	}
	data = q.data[q.front];
	q.front = (q.front + 1 )% MaxSize;
	return true;
}
int main()
{
	Que q;
	init_que(q);
	insert_que(q, 1);
	insert_que(q, 2);
	insert_que(q, 3);
	ElemType data;
	pop_que(q, data);
	pop_que(q, data);
	pop_que(q, data);
	return 0;
}