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
//��������
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

//��ʵû������ֻ������������������������ν�������������ѵ������������˳��
void AdjustDown(int nums[], int pos, int len)
{
    int dad = pos;
    int son = 2 * dad + 1;//�����������±�
    while (son < len)
    {
        if (son + 1 < len && nums[son] < nums[son + 1])
        {
            son++;//��ѡ�����Һ������ģ�ֻ���son+1��Ϊ�Һ����±�
        }
        if (nums[son] > nums[dad])//ֻ�ܸ��״��ں���
        {
            swap(nums[son], nums[dad]);//��������
            dad = son;//�ѵ�ǰ������Ϊ���ף�����ѭ��
            son = 2 * dad + 1;
        }
        else
        {
            break;
        }
    }
}

//���������飬����������ĳ���
void heap_sort(int nums[], int len)
{
    int i;
    //���������
    //�����һ������Ԫ�ؿ�ʼ
    for (i = len / 2 - 1; i >= 0; --i)
    {
        //����û�����׽ڵ�Ϊ�����
        //���飬���׽ڵ�����������±꣬���鳤��
        AdjustDown(nums, i, len);
    }
    //���������֮������������������������н����������������飬������ǻ���Ҫ�����޸�Ϊ������
    swap(nums[0], nums[len - 1]);//�Ƚ������������һ���ڵ������(�������len������)
    // print(nums,len);
    //�����ٴν��뽨������ѣ������ݵ�ѭ���У�ֱ����������
    for (i = len - 1; i > 0; i--)
    {
        AdjustDown(nums, 0, i);//ÿ�δӸ��׽ڵ㿪ʼ�������i�����ȣ�
        swap(nums[0], nums[i - 1]);//ÿһ�ν��������ͣ���ȥ����ĩβ�Ѿ������ģ�ĩβ
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