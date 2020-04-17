#include <stdio.h>

void multstore(long,long,long*);
//定义在mstore.c文件中，编译时需要编译两个文件

//PDF248 3.11.4定义和使用浮点数例子的摄氏度到华氏度转换
double cel2fahr(double temp){
    return 1.8 * temp + 32.0;
}


int main(int argc, char const *argv[])
{
    long d;
    multstore(2,3,&d);
    printf("2 * 3 --> %ld\n",d);

    //PDF234确定“典型的”栈地址的方法
    printf("d at %p(栈地址随机化)\n",&d);
    //每次结果都会不一样，原因是栈随机化 变化范围0x7fff0001b698--0x7ffffffaa4a8
    //栈随机化是更大技术中的一种，称为地址空间布局随机化ASLR address-space layout randomization

    //PDF248 3.11.4定义和使用浮点数例子的摄氏度到华氏度转换
    printf("24.0 ℃  转换成华氏度为：%.2f ℉  \n",cel2fahr(24));
    return 0;
    
}

long mult2(long a,long b){
    long s = a * b;
    return s;
}
