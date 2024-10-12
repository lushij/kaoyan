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
	//�˰汾�ϸ�������汾�Ľṹ��rear�ڵ�������������ԶΪ��
	if (q.rear->next == q.front)
	{
		//��ʾ���пռ�����������⿪�ٿռ�
		LinkList pnew = (LinkList)malloc(sizeof(LNode));
		q.rear->data = data;
		q.rear->next = pnew;
		pnew->next = q.front;
		q.rear = pnew;
		return true;
	}
	//����Ҫ���⿪�ٿռ�
	//��˼�����Ѿ��г�ȥ���������ˣ���û�ж��������ظ�ʹ��
	q.rear->data = data;
	q.rear = q.rear->next;
	return true;
}

bool pop_que(CirLinkQue& q, ElemType& data)
{
	//����
	//�п�
	if (q.rear == q.front)
	{
		return false;
	}
	data = q.front->data;
	q.front->data = NULL;//��д�ɲ�д�������²�������ݻḲ����Щ��Ҫ������
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
