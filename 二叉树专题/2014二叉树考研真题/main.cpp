#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef char ElemType;

//��
typedef struct trees {
    ElemType data;
    struct trees* lc;
    struct trees* rc;
}treeNode, * Tree;

//����
typedef struct Links {
    Tree tree;
    struct Links* next;
}LNode, * LinkList;

//����
typedef struct {
    LinkList front;
    LinkList rear;
}LinkQue;

void init_que(LinkQue& q)
{
    q.front = q.rear = (LinkList)calloc(1, sizeof(LNode));
    q.front = q.rear;
}

bool isEmpty(LinkQue& q)
{
    return q.front == q.rear;
}

//���
void push_que(LinkQue& q, Tree tree)
{
    //�½�����ڵ�
    LinkList newList = (LinkList)calloc(1, sizeof(LNode));
    newList->next = NULL;
    newList->tree = tree;
    q.rear->next = newList;
    q.rear = q.rear->next;
}
bool pop_que(LinkQue& q, Tree& tree)
{
    if (isEmpty(q))
    {
        return false;
    }
    LinkList del = q.front->next;//ͷ��㲻�����ݣ���һ���ڵ�������������ʼλ��
    q.front->next = del->next;//����
    tree = del->tree;
    if (q.rear == del)//ֻʣ��β�ڵ������
    {
        q.rear = q.front;//�ÿ�
    }
    free(del);
    return true;
}

void build_tree(Tree& tree)
{
    LinkQue q;
    init_que(q);
    LinkList cur = NULL;
    ElemType data;
    while (scanf("%c", &data) && data != '\n')
    {
        Tree newTree = (Tree)calloc(1, sizeof(treeNode));//�����µ����Ľڵ�
        newTree->data = data;
        if (tree == NULL)
        {
            tree = newTree;
            push_que(q, tree);//���
            cur = q.rear;
        }
        else
        {
            if (cur->tree->lc == NULL)
            {
                cur->tree->lc = newTree;
                push_que(q, newTree);
            }
            else
            {
                cur->tree->rc = newTree;
                push_que(q, newTree);
                //�ı䵱ǰ���׽ڵ�
                cur = cur->next;
            }
        }
    }
}

/*
* �㷨���˼�룺�ݹ������������Ҷ�ӽڵ���ۼӸýڵ��wplֵ����֮��������
*/

void getWPL(Tree& t, int deep,int &sum)
{
    //�ж�������
    if (t->lc)
    {
        getWPL(t->lc, deep + 1, sum);
    }
    if (t->rc)
    {
        getWPL(t->rc, deep + 1, sum);
    }
    if (!t->lc && !t->rc)
    {
        //Ҷ�ӽ��
        sum += deep * t->data;
        return;
    }
}

int main()
{
    Tree tree = NULL;
    build_tree(tree);
    int sum = 0;
    getWPL(tree, 0, sum);
    printf("%d\n", sum);
    return 0;
}