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
void delete_list(LinkList& l)
{

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
int main()
{
	LinkList l = (LinkList)malloc(sizeof(Lnode));//存储头节点的头指针
	l->next = NULL;
	//insert_head_list(l);//ͷ�巨
	insert_tail_list(l);//β�巨
	print_list(l);
	return 0;
}
