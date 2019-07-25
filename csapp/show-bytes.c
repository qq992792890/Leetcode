#include <stdio.h>
//to use strlen include the string.h
#include <string.h>

//第二章的大部分代码

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len){
    size_t i;
    for (i = 0; i < len; i++)
    {
        printf(" %.2x",start[i]);
    }
    printf("\n");
    
}

void show_int(int x){
    show_bytes((byte_pointer) &x,sizeof(int));
    // printf("show_int finished\n");
    //from this test we can see that on my machine, windows64 on intel x86-64, it is little endian. You can
    //test if your machine is running on big endian
}

void show_float(float x){
    show_bytes((byte_pointer) &x,sizeof(float));  //(byte_pointer) &x强制类型转换，但并不会改变真实真实的指针，
    //只是告诉编译器以新的数据类型看待被指向的数据
    // printf("show_float finished\n");
}

void show_pointer(void *x){
    show_bytes((byte_pointer) &x,sizeof(void *));
    // printf("show_pointer finished\n");
}

void test_show_bytes(int val){
    int ival = val;
    float fval = (float) ival;
    int *pval = &ival;
    show_int(ival);
    show_float(fval);
    show_pointer(pval);
}

//例2.10的异或运算的智力游戏
void inplace_swap(int *x, int *y){
    *y = *x ^ *y;//*x=*x
    *x = *x ^ *y;//*y = *x ^ *y, *x=*y
    *y = *x ^ *y;//*x=*y, *y=*x

}

//Determine whether arguments can be added without overflow
//例2.27 PDF98
int uadd_ok(unsigned x, unsigned y){
    int s = x + y;
    if (s >= x)
    /*if not overflow then x + y >=x, so s >= x;
    if overflowed then: (w is the byte length)
    s = x + y - 2^w and assume y is less than 2^w, so
    s = x + (y - 2^w) < x

    */
    {
        return 1;
    } else
    {
        return 0;
    }
    return 1;
    
    
}

//Determine whether arguments can be added without overflow
//例2.30 PDF101
//return 1 if not overflow
int tadd_ok(int x, int y){
    int s = x + y;
    if (x > 0 && y > 0 && s <= 0)
    {
        return 0;
    }
    if (x < 0 && y < 0 && s >= 0)
    {
        return 0;
    }
    
    return 1;
}

//Determine whether arguments can be added without overflow
//例2.31 PDF101
//return 1 if not overflow
// this code is buggy
int tadd_ok_bug(int x, int y){
    int s = x + y;
    return (s-x==y)&&(s-y==x);// this will always return 1 buggy code
}
//Determine whether arguments can be added without overflow
//例2.32 PDF101
//return 1 if not overflow
// this code is buggy
int tadd_ok_bug2(int x, int y){
    // 0x80000000;
    //补码的取反是按位取反+1 是其自身
    return tadd_ok(x,-y);// sometimes wrong because range of numbers is not eqaul补码中最小的负数没有对应的正数表示
    //补码的取反是按位取反+1
    
}


//Determine whether arguments can be mutiplied without overflow
//例2.35 PDF104
//return 1 if not overflow
int tmul_ok(int x, int y){
    int p = x * y;
    //either x is zero, or dividing p by x gives y
    return !x || p/x==y;//逻辑判断当x=0，该语句在x=0时不会执行||后面的判断，因为!x已经可以得到结果 still don't know why it is right.
}



int main(int argc, char const *argv[])
{
    //程序示例 p68(p32)
    printf("---- example p68 ----\n");
    test_show_bytes(12345);
    
    //练习题2.5 p70(34)
    printf("---- example 2.5 ----\n");
    int val = 0x87654321;
    byte_pointer valp = (byte_pointer) &val;
    show_bytes(valp, 1);
    show_bytes(valp, 2);
    show_bytes(valp, 3);
    
    //练习2.7
    printf("---- example 2.7 ----\n");
    const char *s = "abcdef";
    show_bytes((byte_pointer) s, strlen(s)+1);//字符串以终止符结尾，因此第七个输出的是0x00
    //ASCII码表中数字x的ASCII为0x3x
    //ASCII表中小写字母a-z的表示为0x61-0x7a

    //练习2.10实现
    printf("---- example 2.10 ----\n");
    int x210=10;
    int y210=100;
    printf("x=%d,y=%d\n",x210,y210);
    inplace_swap(&x210,&y210);
    printf("after inplace_swap:x=%d,y=%d\n",x210,y210);

    //PDF84书第48页 为了便于理解补码的表示
    printf("---- example p48 ----\n");
    short x = 0x1234;
    short mx = -x;

    show_bytes((byte_pointer) &x, sizeof(short));
    show_bytes((byte_pointer) &mx, sizeof(short));

    //test overflow of unsigned add 
    //判定无符号数的溢出
    //例2.27 PDF98
    printf("---- example 2.27 ----\n");
    unsigned ta, tb;
    // ta=2147483648u;
    ta= 1u;
    tb=0xfffffffeu;
    printf("x + y is not overflow? %d\n",uadd_ok(ta,tb));

    //test overflow of int add 
    //判定整数加法的溢出
    //例2.30 PDF101
    printf("---- example 2.30 ----\n");
    int tc, td;
    // ta=2147483648u;
    tc= 2147483647;
    td= 2147483612;
    printf("x + y is not overflow? %d %d\n",tadd_ok(tc,td),tadd_ok_bug(tc,td));
    tc= -2147483647;
    td= -2147483612;
    printf("x + y is not overflow? %d %d\n",tadd_ok(tc,td),tadd_ok_bug(tc,td));
    tc= -2147483647;
    td= 2147483612;
    printf("x + y is not overflow? %d %d\n",tadd_ok(tc,td),tadd_ok_bug(tc,td));
    tc= 2147483647;
    td= -2147483612;
    printf("x + y is not overflow? %d %d\n",tadd_ok(tc,td),tadd_ok_bug(tc,td));
    // printf("%f",1.9e308);
    
    //整型与浮点数值转换的测试
    //例2.54 PDF123
    printf("---- example 2.54 ----\n");
    float f=1.0/3;
    float ff= -f;
    printf("f = %f,\t-f = %f\n",f,ff);
    printf("f == -(-f)?\t%d\n",f==ff);
    return 0;
}
