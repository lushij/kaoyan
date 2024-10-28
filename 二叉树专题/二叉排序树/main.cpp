#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
//���ṹ��
typedef struct tree_node {
    ElemType val;
    struct tree_node* lc;
    struct tree_node* rc;
}Tnode, * BTree;
//ע�⣺�����ǻῼ�����������Ľ���������
//����������Ҳ��Ϊ�����������������������
//�ص㣬��������С�ڸ��ڵ㣬С��������
//���������,����


//���ĺ���������������������˰汾Ϊ�ݹ�汾
int bst_insert(BTree& root, int val)
{
    //ÿ������һ���Ƚ�һ���½ڵ�
    BTree newTree = (BTree)calloc(1, sizeof(Tnode));
    newTree->val = val;
    if (root == NULL)
    {
        root = newTree;
        return 1;//����ɹ�
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
        return 0;//���в������Ԫ�صĲ���
    }
}


void create_bst_tree(BTree &root,int *nums,int len)
{
    for (int i = 0; i < len; ++i)
    {
        bst_insert(root, nums[i]);//���ĺ���
    }
}
//�������
void mid_print(BTree t)
{
    if (t)
    {
        mid_print(t->lc);
        printf("%d ", t->val);
        mid_print(t->rc);
    }
}

//����
void find_tree(BTree tree,ElemType key)
{
    BTree cur = tree;
    while (cur)
    {
        if (key > cur->val)
        {
            //������
            cur = cur->rc;
        }
        else if (key < cur->val)
        {
            cur = cur->lc;
        }
        else
        {
            printf("�ڶ������������ҵ���%d\n",key);
            break;
        }
    }
}

//ɾ�����˰汾Ϊ�ݹ�汾
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
        //�ҵ���Ҫɾ���Ľڵ�
        if (!tree->lc)//�ȼ���tree->lc == NULL
        {
            //������Ϊ�գ�������ֱ�Ӵ��涥��ȥ����
            BTree tmp = tree;
            tree = tree->rc;
            free(tmp);
        }
        else if (tree->rc == NULL)
        {
            //������Ϊ�գ�������ֱ�Ӵ��涥��ȥ����
            BTree tmp = tree;
            tree = tree->lc;
            free(tmp);
        }
        else
        {
            //������������Ϊ�գ�����Ϊ���ѵ�һ��
            //����1���ҵ������������ұ߼����Ľڵ�
            //����2���ҵ�������������߼���С�Ľڵ�
            //����ʹ�ò���1
            BTree cur = tree->lc;//������������֧�����ڵ�
            while (cur->rc!=NULL)
            {
                cur = cur->rc;
            }
            //������ɾ���ڵ��cur��ʱ��ֵ
            tree->val = cur->val;
            delete_tree(tree->lc, cur->val);//ɾ����ʱ�������Ľڵ�,����������֧��
        }
            
        
    }
}




void numslen(int nums[])
{
    int len = (int)sizeof(nums) / sizeof(nums[0]);
    printf("������������ĳ���=%d\n", len);
}
int main()
{
    BTree trees = NULL;
    int nums[] = { 15,25,65,2,89 };
    int len = (int)sizeof(nums) / sizeof(nums[0]);
   /* printf("����������ĳ���=%d\n", len);
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

