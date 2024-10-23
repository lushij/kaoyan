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
void print(int nums[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

//快排核心，分割函数
int partition(int *nums,int left,int right)
{
    int prt_val = nums[left];//假设把最左边为分隔值,并且存储下来
    while (left < right)
    {
        while (left < right && nums[right] >= prt_val)
            right--;
        nums[left] = nums[right];//跳出循序表示找到右边比左边小的了，找右赋左
        while (left < right && nums[left] <= prt_val)
            left++;
        nums[right] = nums[left];//找左赋右
    }
    //当left和right相等即表示一个元素时，退出循环，并把最初暂存的值付给nums[left]
    nums[left] = prt_val;
    return left;//把分隔值的下标返回
}
void quick_sort(int nums[], int left,int right)//等价void quick_sort(int *nums, int len)
{
    //递归一定有结束条件
    if (left < right)
    {
        int prt_pos = partition(nums,left,right);//左边下标，右边下标
        quick_sort(nums, left, prt_pos - 1);
        quick_sort(nums, prt_pos + 1, right);
    }
   
}


int main()
{
    int len = sizeof(nums) / sizeof(nums[0]);
    init_rand(nums, len);
    quick_sort(nums, 0, len - 1);//下标
    print(nums, len);
    return 0;
}