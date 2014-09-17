/* CairoSort
 * Copyright (C) <2014> Fabian Orccon <fabian.orccon@pucp.pe>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

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

/* TODO This thing is very ugly, maybe set typedef for functions? */
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
      if (do_something)
        (*do_something) (array, len, a, b, do_something_data);
      if ((*csort_cmp_func) (a, b) >= 0)
        csort_swap (a, b, size);
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
