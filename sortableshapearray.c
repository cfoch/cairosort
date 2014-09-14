#include "sortableshapearray.c"
#include "sortableshapearrayobject.h"

SortableShapeArrayObject *
sortable_shape_array_random_new (int len, int height)
{
  SortableShapeArrayObject *shape_array;
  GRand *rand;
  int i;

  shape_array = sortable_shape_array_object_new (len);
  rand = g_rand_new ();

  for (i = 0; i < len; i++) {
    SortableShapeObject *shape;

    shape = sortable_shape_object_new ();
    sortable_shape_array_object_insert (shape_array, i, shape);
  }
}
