#include<stdio.h>
#include<stdlib.h>
typedef char ElemType;
//树结构体
typedef struct tree_node{
  ElemType val;
  struct tree_node*lc;
  struct tree_node*rc;
}Tnode,*BTree;
 
//链表
typedef struct link{
  BTree tree;//存储的是树的节点
  struct link*next;
}LinkNode,*LinkList;
 
void build_tree(BTree&tree,LinkList&front,LinkList& rear)
{
    //还需要一个指向当前父亲节点的指针
    LinkList cur = NULL;
    ElemType data;
    while(scanf("%c",&data) && data != '\n')
    {
        //每次来一个新建一个树的节点和链表的节点
        BTree newTree = (BTree)calloc(1,sizeof(Tnode));
        LinkList newList = (LinkList)calloc(1,sizeof(LinkNode));
        newTree->val = data;
        newList->tree=newTree;
        //进行判读是不是父亲节点
        if(tree == NULL)
        {
            tree = newTree;
            //入队
            front = rear = newList;
            cur=rear;
        }
        else
        {
            if(cur->tree->lc == NULL)
            {
                //插入左子树
                cur->tree->lc=newTree;
                //入队并更新尾指针
                rear->next=newList;
                rear = rear->next;
            }
            else
            {
                cur->tree->rc = newTree;
                //入队并更新尾指针
                rear->next=newList;
                rear = rear->next;
                //注意这里左右子树都满了，当前父亲节点要换
                cur= cur->next;
            }
        }
    }
}
 
//前序便利
void pre_print(BTree tree)
{
    if(tree)
    {
        putchar(tree->val);
        pre_print(tree->lc);
        pre_print(tree->rc);
    }
}
void mid_print(BTree tree)
{
    if(tree)
    {
        //左跟右
        mid_print(tree->lc);
        putchar(tree->val);
        mid_print(tree->rc);
    }
}
void post_print(BTree tree)
{
    if(tree)
    {
        //左右跟
        post_print(tree->lc);
        post_print(tree->rc);
        putchar(tree->val);
    }
}
int main()
{
    BTree tree = NULL;//树根
    LinkList front=NULL;
    LinkList rear=NULL;//需要用到尾插法
    build_tree(tree,front,rear);
    pre_print(tree);
    puts("");
    mid_print(tree);
    puts("");
    post_print(tree);
	return 0;
}
 
 
 
