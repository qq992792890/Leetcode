#include <inttypes.h>
//code in chapter 3 
long exchange(long *xp,long y){
    long x = *xp;
    *xp = y;
    return x;
}

long shift_left4_rightn(long x, long n){
    x <<= 4;
    x >>= n;
    return x;
}

typedef unsigned __int128 uint128_t;
void store_uprod(uint128_t *dest, uint64_t x,uint64_t y){
    *dest = x * (uint128_t) y;
}