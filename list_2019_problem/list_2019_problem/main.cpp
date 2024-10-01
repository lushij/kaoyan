#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}NODE;
typedef NODE* Node;

void insert_head_list(Node& l)
{
	ElemType data = 0;
	scanf("%d", &data);
	while (data != 9999)
	{
		Node tmp = (Node)malloc(sizeof(NODE));
		tmp->data = data;
		tmp->next = l->next;
		l->next = tmp;
		scanf("%d", &data);
	}
}


void print_list(Node& l)
{
	Node cur = l->next;
	while (cur)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}


Node find_mid(Node& h)
{
	Node pre, cur;
	pre = h->next;
	cur = pre;
	while (cur)
	{
		cur = cur->next;
		if (!cur) break;
		cur = cur->next;
		if (!cur) break;
		pre = pre->next;
	}
	Node l2 = (Node)malloc(sizeof(NODE));
	l2->next = pre->next;
	pre->next = NULL;
	return l2;
}
void reverse_list(Node& l)
{
	Node s, r, t;
	s = l->next, r = s->next, t = r->next;
	s->next = NULL;
	while (t)
	{
		r->next = s;
		s = r;
		r = t;
		t = t->next;
	}
	r->next = s;
	l->next = r;
}

void merge_list(Node& l1, Node& l2)
{
	Node a =  l1->next, b = l2->next;
	Node acur = a;
	a = a->next;
	while (a && b)
	{
		acur->next = b;
		b = b->next;
		acur = acur->next;
		acur->next = a;
		a = a->next;
		acur = acur->next;
	}
	if(!a) acur->next = b;
	
}
int main()
{
	Node l = (Node)malloc(sizeof(NODE)); //存储头节点的头指针
	l->next = NULL;
	insert_head_list(l);//头插法
	print_list(l);
	Node l2 = find_mid(l);
	print_list(l);
	print_list(l2);
	reverse_list(l2);
	print_list(l2);
	merge_list(l, l2);
	print_list(l);
	return 0;
}
