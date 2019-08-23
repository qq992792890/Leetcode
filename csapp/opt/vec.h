typedef long data_t; //set data_t to long

/*Create abstract data for vector */
typedef struct 
{
    long len;
    data_t *data;
}vec_rec,*vec_ptr;


