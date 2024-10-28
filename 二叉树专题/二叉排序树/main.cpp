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


//核心函数：构造二叉排序树，此版本为递归版本
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
//中序遍历
void mid_print(BTree t)
{
    if (t)
    {
        mid_print(t->lc);
        printf("%d ", t->val);
        mid_print(t->rc);
    }
}

//查找
void find_tree(BTree tree,ElemType key)
{
    BTree cur = tree;
    while (cur)
    {
        if (key > cur->val)
        {
            //右子树
            cur = cur->rc;
        }
        else if (key < cur->val)
        {
            cur = cur->lc;
        }
        else
        {
            printf("在二叉排序树中找到了%d\n",key);
            break;
        }
    }
}

//删除：此版本为递归版本
void delete_tree(BTree &tree,ElemType del)
{
    if (tree == NULL)
    {
        return;
    }
    if (del < tree->val)
         delete_tree(tree->lc, del);
    else if ( del > tree->val)
         delete_tree(tree->rc, del);
    else
    {
        //找到了要删除的节点
        if (!tree->lc)//等价于tree->lc == NULL
        {
            //左子树为空，右子树直接代替顶上去就行
            BTree tmp = tree;
            tree = tree->rc;
            free(tmp);
        }
        else if (tree->rc == NULL)
        {
            //右子树为空，左子树直接代替顶上去就行
            BTree tmp = tree;
            tree = tree->lc;
            free(tmp);
        }
        else
        {
            //左右子树都不为空，是最为困难的一种
            //策略1：找到左子树的最右边即最大的节点
            //策略2：找到右子树的最左边即最小的节点
            //本次使用策略1
            BTree cur = tree->lc;//查找左子树分支的最大节点
            while (cur->rc!=NULL)
            {
                cur = cur->rc;
            }
            //更换待删除节点和cur此时的值
            tree->val = cur->val;
            delete_tree(tree->lc, cur->val);//删除此时被更换的节点,在左子树分支上
        }
            
        
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
    puts("");
    //find_tree(trees, 65);
    //find_tree(trees, 15);
    //find_tree(trees, 100);
    delete_tree(trees, 25);
    mid_print(trees);
    puts("");
    return 0;
}

