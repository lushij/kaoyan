#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}Lnode,*LinkList;
void insert_head_list(LinkList& l)
{
	ElemType data = 0;
	scanf("%d", &data);	
	while (data != 9999)
	{
		LinkList tmp = (LinkList)malloc(sizeof(Lnode));
		tmp->data = data;
		tmp->next = l->next;
		l->next = tmp;
		scanf("%d", &data);
	}
}
void insert_tail_list(LinkList& l)
{
	LinkList cur = l;
	ElemType data = 0;
	scanf("%d", &data);
	while (data != 9999)
	{
		LinkList tmp = (LinkList)malloc(sizeof(Lnode));
		tmp->next = cur->next;
		tmp->data = data;
		cur->next = tmp;
		cur = tmp;
		scanf("%d", &data);
	}
}
//ɾ��
bool delete_list(LinkList& l,int pos)
{
	//ͷ����λ����0�����������ݵ�Ϊ��һ���ڵ㣬Ҳ���ǵ�һ��λ��
	if (pos < 1)
	{
		return false;
	}
	LinkList cur = l -> next;
	//��Ҫɾ��λ�õ�ǰһ���ڵ��λ��
	for (int i = 1; cur && i < pos-1 ; ++i)
	{
		cur = cur->next;
	}
	LinkList del = cur->next;
	cur->next = del->next;//����
	free(del);
	return true;
}
void print_list(LinkList& l)
{
	LinkList cur = l->next;
	while (cur)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

bool insert_pos(LinkList& l, int pos,int val)
{

	//ͷ����λ����0�����������ݵ�Ϊ��һ���ڵ㣬Ҳ���ǵ�һ��λ��
	if (pos < 1)
	{
		return false;
	}
	LinkList cur = l->next;
	//��Ҫ����λ�õ�ǰһ���ڵ��λ��
	for (int i = 1; cur && i < pos - 1; ++i)
	{
		cur = cur->next;
	}
	LinkList v = (LinkList)malloc(sizeof(LNode));
	v->data = val;
	v->next = cur->next;
	cur->next = v;
	return true;
}

int main()
{
	LinkList l = (LinkList)malloc(sizeof(Lnode)); //�洢ͷ�ڵ��ͷָ��
	l->next = NULL;
	//insert_head_list(l);//ͷ�巨
	insert_tail_list(l);//β�巨
	print_list(l);
	delete_list(l, 2);
	print_list(l);
	insert_pos(l, 3, 999);
	print_list(l);
	return 0;
}
