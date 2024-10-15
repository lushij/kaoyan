#include"tree.h"
/*tree.h

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef char ElemType;
typedef struct tree_node {
	ElemType data;
	struct tree_node* lc;
	struct tree_node* rc;
}trees,*Btree;

typedef struct queTree {
	Btree tree;//������ڵ�ĵ�ַ
	struct queTree* next;
}treesQue,*treeQue;//����

*/
void build_tree(Btree& tree, treeQue &front, treeQue &rear)
{
	ElemType data;
	treeQue cur = NULL;//ָ��ǰ���׽ڵ�
	while (scanf("%c", &data) && data != '\n')
	{
		Btree tNew = (Btree)calloc(1, sizeof(trees));//�����½ڵ�
		tNew->data = data;
		//�����������µĽڵ�
		treeQue qNew = (treeQue)calloc(1, sizeof(treesQue));
		qNew->tree = tNew;
		if (tree == NULL)
		{
			//���ĸ�
			tree = tNew;
			front=rear=qNew;//���
			cur = rear;//��ǰ���׽ڵ�
		}
		else 
		{
			if (cur->tree->lc == NULL)
			{
				cur->tree->lc = tNew;
				rear->next = qNew;
				rear = rear->next;
			}
			else
			{
				cur->tree->rc = tNew;
				rear->next=qNew;
				rear = rear->next;
				cur = cur->next;
			}
		}

	}
}

//ǰ�������������
void pre_print(Btree tree)
{
	if (tree)
	{
		putchar(tree->data);
		pre_print(tree->lc);
		pre_print(tree->rc);
	}
}
//��������������
void InOrder(Btree p)
{
	if (p != NULL)
	{
		InOrder(p->lc);//��ӡ������
		printf("%c", p->data);
		InOrder(p->rc);//��ӡ������
	}
}
//������������Ҹ�
void post_print(Btree tree)
{
	if (tree)
	{
		post_print(tree->lc);
		post_print(tree->rc);
		putchar(tree->data);
	}
}

int main()
{
	Btree tree = NULL;//����
	treeQue front = NULL;
	treeQue rear = NULL;
	build_tree(tree,front,rear);
	pre_print(tree);
	puts("");
	InOrder(tree);
	puts("");
	post_print(tree);
	puts("");
	return 0;
	//425163
}