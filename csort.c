#include "csort.h"

int
csort_cmp_int_func (void * a, void * b)
{
  int *x = (int *) a;
  int *y = (int *) b;

  return *x - *y;
}

static int csort_swap (void * a, void * b, int size)
{
  void *tmp = malloc (size);
  memcpy (tmp, a, size);
  memcpy (a, b, size);
  memcpy (b, tmp, size);
}

void
csort_bubble_sort (void * array, int len, int size,
    int (* csort_cmp_func) (void *, void *),
    void (* do_something) (void *, int, void *, void *, void *), 
    void * do_something_data)
{
  int i, j;
  for (i = 0; i < len; i++)
    for (j = 0; j < len - i - 1; j++) {
      char *a, *b;
      a = (char *) array + j * size;
      b = (char *) array + (j + 1) * size;

      csort_swap (a, b, size);
      if ((*csort_cmp_func) (a, b) >= 0) {
        if (do_something)
          (*do_something) (array, len, a, b, do_something_data);
      }
    }
}

void
csort_do_int_print_example (void * array, int len, void * a, void * b, void * data)
{
  int *x = (int *) a;
  int *y = (int *) b;
  int i;

  printf ("%d <-> %d\n", *x, *y);
  for (i = 0; i < len; i++)
    printf ("%d\n", ((int *) array)[i]);
  printf ("\n");
}
