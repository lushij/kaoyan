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

/*
* 算法设计思想：递归遍历若是树的叶子节点就累加该节点的wpl值，反之继续遍历
*/

void getWPL(Tree& t, int deep,int &sum)
{
    //判断左子树
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
        //叶子结点
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