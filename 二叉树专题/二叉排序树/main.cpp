#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
//树结构体
typedef struct tree_node {
    ElemType val;
    struct tree_node* lc;
    struct tree_node* rc;
}Tnode, * BTree;
//注意：考研是会考二叉排序树的建树函数的
//二叉排序树也称为二叉搜索树（二叉查找树）
//特点，左子树都小于根节点，小于右子树
//考中序遍历,查找

int bst_insert(BTree& root, int val)
{
    //每次新来一个先建一个新节点
    BTree newTree = (BTree)calloc(1, sizeof(Tnode));
    newTree->val = val;
    if (root == NULL)
    {
        root = newTree;
        return 1;//插入成功
    }
    if (val > root->val)
    {
        return bst_insert(root->rc, val);
    }
    else if(val < root->val)
    {
        return bst_insert(root->lc, val);
    }
    else
    {
        return 0;//考研不考相等元素的插入
    }
}


void create_bst_tree(BTree &root,int *nums,int len)
{
    for (int i = 0; i < len; ++i)
    {
        bst_insert(root, nums[i]);//核心函数
    }
}
void mid_print(BTree t)
{
    if (t)
    {
        mid_print(t->lc);
        printf("%d ", t->val);
        mid_print(t->rc);
    }
}

void numslen(int nums[])
{
    int len = (int)sizeof(nums) / sizeof(nums[0]);
    printf("函数传的数组的长度=%d\n", len);
}
int main()
{
    BTree trees = NULL;
    int nums[] = { 15,25,65,2,89 };
    int len = (int)sizeof(nums) / sizeof(nums[0]);
   /* printf("主函数数组的长度=%d\n", len);
    numslen(nums);*/
    create_bst_tree(trees, nums,len);
    mid_print(trees);
    return 0;
}

