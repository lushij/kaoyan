#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
//数组
int nums[] = { 3,87,2,93,78,56,61,38,12,40 };
void init_rand(int nums[], int len)
{
    srand(time(NULL));
    for (int i = 0; i < len; ++i)
    {
        nums[i] = rand() % 100 + 1;//(1,100)
    }
}
//交换数据
void swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
void print(int nums[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

//其实没有树，只不过是我们在心里根据数组层次建树来构建大根堆调整数组的排列顺序
void AdjustDown(int nums[], int pos, int len)
{
    int dad = pos;
    int son = 2 * dad + 1;//左孩子在数组下标
    while (son < len)
    {
        if (son + 1 < len && nums[son] < nums[son + 1])
        {
            son++;//挑选出左右孩子最大的，只需把son+1变为右孩子下标
        }
        if (nums[son] > nums[dad])//只能父亲大于孩子
        {
            swap(nums[son], nums[dad]);//交换数据
            dad = son;//把当前孩子作为父亲，重新循环
            son = 2 * dad + 1;
        }
        else
        {
            break;
        }
    }
}

//待排序数组，待排序数组的长度
void heap_sort(int nums[], int len)
{
    int i;
    //建立大根堆
    //从最后一个父亲元素开始
    for (i = len / 2 - 1; i >= 0; --i)
    {
        //调整没个父亲节点为大根堆
        //数组，父亲节点所在数组的下标，数组长度
        AdjustDown(nums, i, len);
    }
    //建立大根堆之后，有序的数据是在我们内心中建的树，而不是数组，因此我们还需要把他修改为数组中
    swap(nums[0], nums[len - 1]);//先交换树根和最后一个节点的数据(我这里的len代表长度)
    // print(nums,len);
    //接着再次进入建立大根堆，换数据的循环中，直到数组有序
    for (i = len - 1; i > 0; i--)
    {
        AdjustDown(nums, 0, i);//每次从父亲节点开始（这里的i代表长度）
        swap(nums[0], nums[i - 1]);//每一次交换树根和（除去数组末尾已经换过的）末尾
        // print(nums,len);
    }

}

int main()
{
    int len = sizeof(nums) / sizeof(nums[0]);
    init_rand(nums, len);
    heap_sort(nums, len);
    print(nums, len);
}