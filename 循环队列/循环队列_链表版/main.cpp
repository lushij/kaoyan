#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct node {
	ElemType data;
	struct node* next;
}LNode, * LinkList;

typedef struct {
	LinkList front;
	LinkList rear;
}CirLinkQue;

void init_cir_link_que(CirLinkQue& q)
{
	q.rear = q.front = (LinkList)malloc(sizeof(LNode));
	q.front->next = NULL;
	q.rear->next = q.front;
}

bool insert_que(CirLinkQue& q, ElemType data)
{
	//此版本严格按照数组版本的结构，rear节点所代表数据永远为空
	if (q.rear->next == q.front)
	{
		//表示现有空间已满，需额外开辟空间
		LinkList pnew = (LinkList)malloc(sizeof(LNode));
		q.rear->data = data;
		q.rear->next = pnew;
		pnew->next = q.front;
		q.rear = pnew;
		return true;
	}
	//不需要额外开辟空间
	//意思就是已经有出去过的数据了，但没有断链，可重复使用
	q.rear->data = data;
	q.rear = q.rear->next;
	return true;
}

bool pop_que(CirLinkQue& q, ElemType& data)
{
	//出队
	//判空
	if (q.rear == q.front)
	{
		return false;
	}
	data = q.front->data;
	q.front->data = NULL;//可写可不写，后面新插入的数据会覆盖这些不要的数据
	q.front = q.front->next;
	return true;
}
int main()
{
	CirLinkQue q;
	ElemType data;
	init_cir_link_que(q);
	insert_que(q, 1);
	insert_que(q, 2);
	insert_que(q, 3);
	pop_que(q, data);
	insert_que(q, 4);
	pop_que(q, data);
	insert_que(q, 5);
	/*pop_que(q, data);
	pop_que(q, data) ? puts("true") : puts("false");*/
	return 0;
}
