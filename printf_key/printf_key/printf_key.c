#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
    //int num = 10;
    //int nums = 100;
    //float f = 1000.2333333333;
    //printf("%3d\n", nums);//%3d��ʾ������ܿ������Ϊ3���ַ�
    //printf("%3d\n", num);
    //printf("%-3d\n", num);
    ////   5��ʾ������ܿ������Ϊ5���ַ��������ֵ��Ȳ���5���ַ�������ǰ�油�ո�
    ////   .2 ��ʾС�������2λС��
    //printf("%5.2f\n", f);
  /*  int i = 0;
    char c = 0;
    int ret = scanf("%d", &i);
    getchar();
    int res = scanf("%c", &c);*/

    int i;
    float f;
    double d;
    int ret = scanf("%d %lf %f", &i, &d, &f);
    return 0;
}