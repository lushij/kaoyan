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
	Btree tree;//存放树节点的地址
	struct queTree* next;
}treesQue,*treeQue;//队列

*/
void build_tree(Btree& tree, treeQue &front, treeQue &rear)
{
	ElemType data;
	treeQue cur = NULL;//指向当前父亲节点
	while (scanf("%c", &data) && data != '\n')
	{
		Btree tNew = (Btree)calloc(1, sizeof(trees));//树的新节点
		tNew->data = data;
		//给队列申请新的节点
		treeQue qNew = (treeQue)calloc(1, sizeof(treesQue));
		qNew->tree = tNew;
		if (tree == NULL)
		{
			//树的根
			tree = tNew;
			front=rear=qNew;//入队
			cur = rear;//当前父亲节点
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

//前序遍历：根左右
void pre_print(Btree tree)
{
	if (tree)
	{
		putchar(tree->data);
		pre_print(tree->lc);
		pre_print(tree->rc);
	}
}
//中序遍历：左根右
void InOrder(Btree p)
{
	if (p != NULL)
	{
		InOrder(p->lc);//打印左子树
		printf("%c", p->data);
		InOrder(p->rc);//打印右子树
	}
}
//后序遍历：左右根
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
	Btree tree = NULL;//树根
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