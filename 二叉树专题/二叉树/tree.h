#pragma once
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
}treesQue, * treeQue;
