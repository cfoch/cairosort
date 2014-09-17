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
