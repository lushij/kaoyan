
#define _CRT_SECURE_NO_WARNINGS 1
//���������˽⼴�ɿ��г���ѭ������

#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;


typedef struct node {
	ElemType data;
	struct node* next;
}Linklist,*LNode;

typedef struct{
	LNode rear;//����ͷ
	LNode front;//����β
}LinkeQue;

void init_link_que(LinkeQue& q)
{
	q.front = q.rear = (LNode)malloc(sizeof(Linklist));
	q.front->next = NULL;
}

//���
bool insert_link_que(LinkeQue& q, ElemType data)
{
	//β�巨
	LNode pnew = (LNode)malloc(sizeof(Linklist));
	pnew->data = data;
	pnew->next = NULL;
	q.rear->next = pnew;
	q.rear = pnew;
	return true;
}
//����
bool pop_link_que(LinkeQue& q, ElemType& data)
{
	if (q.rear == q.front)
	{
		return false;
	}
	LNode pdata = (LNode)malloc(sizeof(Linklist));
	pdata = q.front->next;//ͷ���ɶ��û�У���һ���ڵ��������
	data = pdata->data;
	q.front->next = pdata->next;
	if (q.rear == pdata)//��ʾ���һ��
	{
		q.front = q.rear;//�����ÿ�
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