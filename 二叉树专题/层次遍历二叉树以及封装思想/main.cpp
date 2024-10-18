#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef char ElemType;

//树
typedef struct trees {
    ElemType data;
    struct trees* lc;
    struct trees* rc;
}treeNode, * Tree;

//链表
typedef struct Links {
    Tree tree;
    struct Links* next;
}LNode, * LinkList;

//队列
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

//入队
void push_que(LinkQue& q, Tree tree)
{
    //新建链表节点
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
    LinkList del = q.front->next;//头结点不存数据，第一个节点才是真的数据起始位置
    q.front->next = del->next;//断链
    tree = del->tree;
    if (q.rear == del)//只剩下尾节点的数据
    {
        q.rear = q.front;//置空
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
        Tree newTree = (Tree)calloc(1, sizeof(treeNode));//申请新的树的节点
        newTree->data = data;
        if (tree == NULL)
        {
            tree = newTree;
            push_que(q, tree);//入队
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
                //改变当前父亲节点
                cur = cur->next;
            }
        }
    }
}

void pre_print(Tree t)
{
    if (t)
    {
        putchar(t->data);
        pre_print(t->lc);
        pre_print(t->rc);
    }
}
void mid_print(Tree t)
{
    if (t)
    {
        mid_print(t->lc);
        putchar(t->data);
        mid_print(t->rc);
    }
}
void post_print(Tree t)
{
    if (t)
    {
        post_print(t->lc);
        post_print(t->rc);
        putchar(t->data);
    }
}

void level_print(Tree t)
{
    Tree cur;
    LinkQue q;//队列建立
    init_que(q);
    push_que(q, t);//树根入队
    while (!isEmpty(q))//队列不为空
    {
        //出队
        pop_que(q, cur);
        putchar(cur->data);
        if (cur->lc)
        {
            push_que(q, cur->lc);//左子树入队
        }
        if (cur->rc)
        {
            push_que(q, cur->rc);//右子树入队
        }
    }
}
int main()
{
    Tree tree = NULL;
    build_tree(tree);
    // pre_print(tree);
    level_print(tree);
    return 0;
}