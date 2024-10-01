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
//删除
bool delete_list(LinkList& l,int pos)
{
	//头结点的位置是0，真正有数据的为第一个节点，也就是第一个位置
	if (pos < 1)
	{
		return false;
	}
	LinkList cur = l -> next;
	//找要删除位置的前一个节点的位置
	for (int i = 1; cur && i < pos-1 ; ++i)
	{
		cur = cur->next;
	}
	LinkList del = cur->next;
	cur->next = del->next;//断链
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

	//头结点的位置是0，真正有数据的为第一个节点，也就是第一个位置
	if (pos < 1)
	{
		return false;
	}
	LinkList cur = l->next;
	//找要插入位置的前一个节点的位置
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
	LinkList l = (LinkList)malloc(sizeof(Lnode)); //存储头节点的头指针
	l->next = NULL;
	//insert_head_list(l);//头插法
	insert_tail_list(l);//尾插法
	print_list(l);
	delete_list(l, 2);
	print_list(l);
	insert_pos(l, 3, 999);
	print_list(l);
	return 0;
}
