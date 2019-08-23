#include <stdio.h>
#include <stdlib.h>
#include "vec.h"
/*Create vector of specified length */
vec_ptr new_vec(long len){
    /*Allocata header structure */
    vec_ptr result = (vec_ptr) malloc(sizeof(vec_rec));
    data_t *data = NULL;
    if (!result)
    {
        return NULL; /*Coudn't allocate storage */
    }
    result->len = len;
    /*Allocate array */
    if (len > 0)
    {
        data = (data_t *)calloc(len,sizeof(data_t));
        if (!data)
        {
            free((void *) result);
            return NULL;/*Couldn't allocate storage */
        }

    }
    /*Data will either be NULL or allocated array */
    result->data = data;
    return result;
    
}

/*
 * Retrieve vector element and store at dest.
 * return 0 (out of bounds) or 1 (successful)
 *  */
int get_vec_element(vec_ptr v, long index, data_t *dest){
    if (index < 0 || index >=v->len)
    {
        retuen 0;
    }
    *dest = v->data[index];
    return 1;
    
}

/*Return length of vector */
long vec_length(vec_ptr v){
    return v->len;
}

/*main func entry */
int main(int argc, char const *argv[])
{
    
    return 0;
}
