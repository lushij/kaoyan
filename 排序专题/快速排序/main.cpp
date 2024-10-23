#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
//����
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

//���ź��ģ��ָ��
int partition(int *nums,int left,int right)
{
    int prt_val = nums[left];//����������Ϊ�ָ�ֵ,���Ҵ洢����
    while (left < right)
    {
        while (left < right && nums[right] >= prt_val)
            right--;
        nums[left] = nums[right];//����ѭ���ʾ�ҵ��ұ߱����С���ˣ����Ҹ���
        while (left < right && nums[left] <= prt_val)
            left++;
        nums[right] = nums[left];//������
    }
    //��left��right��ȼ���ʾһ��Ԫ��ʱ���˳�ѭ������������ݴ��ֵ����nums[left]
    nums[left] = prt_val;
    return left;//�ѷָ�ֵ���±귵��
}
void quick_sort(int nums[], int left,int right)//�ȼ�void quick_sort(int *nums, int len)
{
    //�ݹ�һ���н�������
    if (left < right)
    {
        int prt_pos = partition(nums,left,right);//����±꣬�ұ��±�
        quick_sort(nums, left, prt_pos - 1);
        quick_sort(nums, prt_pos + 1, right);
    }
   
}


int main()
{
    int len = sizeof(nums) / sizeof(nums[0]);
    init_rand(nums, len);
    quick_sort(nums, 0, len - 1);//�±�
    print(nums, len);
    return 0;
}