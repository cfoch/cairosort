#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef void (* CSortCmpFunction) (void *, void *);
typedef void (* CSortFunction) (void *, int, int, int (*) (void *, void *),
    void (*) (void *, int, void *, void *, void *, void *), void *);

int csort_cmp_int_func (void * a, void * b);

void csort_bubble_sort (void * array, int len, int size,
    int (* csort_cmp_func) (void *, void *),
    void (* do_something) (void *, int, void *, void *, void *), 
    void * do_something_data);

void csort_do_int_print_example (void * array, int len, void * a, void * b,
    void * data);
