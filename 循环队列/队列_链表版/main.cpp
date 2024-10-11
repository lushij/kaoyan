
#define _CRT_SECURE_NO_WARNINGS 1
//链表版队列了解即可考研常考循环队列

#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;


typedef struct node {
	ElemType data;
	struct node* next;
}Linklist,*LNode;

typedef struct{
	LNode rear;//队列头
	LNode front;//队列尾
}LinkeQue;

void init_link_que(LinkeQue& q)
{
	q.front = q.rear = (LNode)malloc(sizeof(Linklist));
	q.front->next = NULL;
}

//入队
bool insert_link_que(LinkeQue& q, ElemType data)
{
	//尾插法
	LNode pnew = (LNode)malloc(sizeof(Linklist));
	pnew->data = data;
	pnew->next = NULL;
	q.rear->next = pnew;
	q.rear = pnew;
	return true;
}
//出队
bool pop_link_que(LinkeQue& q, ElemType& data)
{
	if (q.rear == q.front)
	{
		return false;
	}
	LNode pdata = (LNode)malloc(sizeof(Linklist));
	pdata = q.front->next;//头结点啥都没有，第一个节点才有数据
	data = pdata->data;
	q.front->next = pdata->next;
	if (q.rear == pdata)//表示最后一个
	{
		q.front = q.rear;//队列置空
	}
	free(pdata);
	return true;	
}

int main()
{
	LinkeQue q;
	init_link_que(q);
	insert_link_que(q, 1);
	insert_link_que(q, 2);
	insert_link_que(q, 3);
	ElemType data;
	pop_link_que(q, data);
	pop_link_que(q, data);
	pop_link_que(q, data);
	pop_link_que(q, data);
	return 0;
}