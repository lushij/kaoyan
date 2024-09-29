#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
    //int num = 10;
    //int nums = 100;
    //float f = 1000.2333333333;
    //printf("%3d\n", nums);//%3d表示输出的总宽度至少为3个字符
    //printf("%3d\n", num);
    //printf("%-3d\n", num);
    ////   5表示输出的总宽度至少为5个字符，如果数值宽度不足5个字符，会在前面补空格。
    ////   .2 表示小数点后保留2位小数
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