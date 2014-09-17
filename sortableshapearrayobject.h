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

/* inclusion guard */
#ifndef __SORTABLE_SHAPE_ARRAY_OBJECT_H__
#define __SORTABLE_SHAPE_ARRAY_OBJECT_H__

#include <glib-object.h>
#include <cairo.h>
#include <gtk/gtk.h>

/*
 * Potentially, include other headers on which this header depends.
 */

/*
 * Type macros.
 */
#define SORTABLE_SHAPE_ARRAY_TYPE_OBJECT                  (sortable_shape_array_object_get_type ())
#define SORTABLE_SHAPE_ARRAY_OBJECT(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), SORTABLE_SHAPE_ARRAY_TYPE_OBJECT, SortableShapeArrayObject))
#define SORTABLE_SHAPE_ARRAY_IS_OBJECT(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SORTABLE_SHAPE_ARRAY_TYPE_OBJECT))
#define SORTABLE_SHAPE_ARRAY_OBJECT_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass), SORTABLE_SHAPE_ARRAY_TYPE_OBJECT, SortableShapeArrayObjectClass))
#define SORTABLE_SHAPE_ARRAY_IS_OBJECT_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass), SORTABLE_SHAPE_ARRAY_TYPE_OBJECT))
#define SORTABLE_SHAPE_ARRAY_OBJECT_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj), SORTABLE_SHAPE_ARRAY_TYPE_OBJECT, SortableShapeArrayObjectClass))

typedef struct _SortableShapeArrayObjectPrivate SortableShapeArrayObjectPrivate;

typedef struct _SortableShapeArrayObject        SortableShapeArrayObject;
typedef struct _SortableShapeArrayObjectClass   SortableShapeArrayObjectClass;

struct _SortableShapeArrayObject
{
  /* Parent instance structure */
  GObject parent_instance;

  /* <private> */
  SortableShapeArrayObjectPrivate *priv;

  /* instance members */
  double padding;
  int len;
  cairo_t *cr;
};

struct _SortableShapeArrayObjectClass
{
  /* Parent class structure */
  GObjectClass parent_class;

  /* class members */
  void (*draw)                   (SortableShapeArrayObject *, double x, double y);
};

/* used by SORTABLE_SHAPE_ARRAY_TYPE_OBJECT */
GType sortable_shape_array_object_get_type (void);

/*
 * Method definitions.
 */

SortableShapeArrayObject *sortable_shape_array_object_new ();
int sortable_shape_array_object_cmp_by_height (void * a, void * b);
void sortable_shape_array_object_set_cairo_context (SortableShapeArrayObject * self, cairo_t *cr);


struct _data_to_image {
  SortableShapeArrayObject *shape_array;
  int step;
};

#endif /* __SORTABLE_SHAPE_ARRAY_OBJECT_H__ */
