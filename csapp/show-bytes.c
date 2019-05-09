#include <stdio.h>

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
    //from this test we can see that on my machine, windows64 on intel x86-64, it is little endian
}

void show_float(float x){
    show_bytes((byte_pointer) &x,sizeof(float));
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

int main(int argc, char const *argv[])
{
    test_show_bytes(12345);
    return 0;
}
