#include <stdio.h>
//to use strlen include the string.h
#include <string.h>

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

    //联系2.10实现
    printf("---- example 2.10 ----\n");
    int x210=10;
    int y210=100;
    printf("x=%d,y=%d\n",x210,y210);
    inplace_swap(&x210,&y210);
    printf("after inplace_swap:x=%d,y=%d\n",x210,y210);


    return 0;
}
