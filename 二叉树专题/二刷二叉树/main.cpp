#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef char ElemType;
//���ṹ��
typedef struct tree_node {
    ElemType val;
    struct tree_node* lc;
    struct tree_node* rc;
}Tnode, * BTree;

//����
typedef struct link {
    BTree tree;//�洢�������Ľڵ�
    struct link* next;
}LinkNode, * LinkList;

void build_tree(BTree& tree, LinkList& front, LinkList& rear)
{
    //����Ҫһ��ָ��ǰ���׽ڵ��ָ��
    LinkList cur = NULL;
    ElemType data;
    while (scanf("%c", &data) && data != '\n')
    {
        //ÿ����һ���½�һ�����Ľڵ������Ľڵ�
        BTree newTree = (BTree)calloc(1, sizeof(Tnode));
        LinkList newList = (LinkList)calloc(1, sizeof(LinkNode));
        newTree->val = data;
        newList->tree = newTree;
        //�����ж��ǲ��Ǹ��׽ڵ�
        if (tree == NULL)
        {
            tree = newTree;
            //���
            front = rear = newList;
            cur = rear;
        }
        else
        {
            if (cur->tree->lc == NULL)
            {
                //����������
                cur->tree->lc = newTree;
                //��Ӳ�����βָ��
                rear->next = newList;
                rear = rear->next;
            }
            else
            {
                cur->tree->rc = newTree;
                //��Ӳ�����βָ��
                rear->next = newList;
                rear = rear->next;
                //ע�������������������ˣ���ǰ���׽ڵ�Ҫ��
                cur = cur->next;
            }
        }
    }
}

//ǰ�����
void pre_print(BTree tree)
{
    if (tree)
    {
        putchar(tree->val);
        pre_print(tree->lc);
        pre_print(tree->rc);
    }
}
//�������
void mid_print(BTree tree)
{
    if (tree)
    {
        //�����
        mid_print(tree->lc);
        putchar(tree->val);
        mid_print(tree->rc);
    }
}

//�������
void post_print(BTree tree)
{
    if (tree)
    {
        //���Ҹ�
        post_print(tree->lc);
        post_print(tree->rc);
        putchar(tree->val);
    }
}


int main()
{
    BTree tree = NULL;//����
    LinkList front = NULL;
    LinkList rear = NULL;//��Ҫ�õ�β�巨
    build_tree(tree, front, rear);
    pre_print(tree);
    puts("");
    mid_print(tree);
    puts("");
    post_print(tree);
    return 0;
}



