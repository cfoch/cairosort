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
#ifndef __SORTABLE_SHAPE_OBJECT_H__
#define __SORTABLE_SHAPE_OBJECT_H__

#include <glib-object.h>
#include <cairo.h>

/*
 * Potentially, include other headers on which this header depends.
 */

/*
 * Type macros.
 */
#define SORTABLE_SHAPE_TYPE_OBJECT                  (sortable_shape_object_get_type ())
#define SORTABLE_SHAPE_OBJECT(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), SORTABLE_SHAPE_TYPE_OBJECT, SortableShapeObject))
#define SORTABLE_SHAPE_IS_OBJECT(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SORTABLE_SHAPE_TYPE_OBJECT))
#define SORTABLE_SHAPE_OBJECT_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass), SORTABLE_SHAPE_TYPE_OBJECT, SortableShapeObjectClass))
#define SORTABLE_SHAPE_IS_OBJECT_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass), SORTABLE_SHAPE_TYPE_OBJECT))
#define SORTABLE_SHAPE_OBJECT_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj), SORTABLE_SHAPE_TYPE_OBJECT, SortableShapeObjectClass))

typedef struct _SortableShapeObjectPrivate SortableShapeObjectPrivate;

typedef struct _SortableShapeObject        SortableShapeObject;
typedef struct _SortableShapeObjectClass   SortableShapeObjectClass;

struct _SortableShapeObject
{
  /* Parent instance structure */
  GObject parent_instance;

  /* <private> */
  SortableShapeObjectPrivate *priv;

  /* instance members */
  cairo_t *cr;
  double height;
  double width;
  double r, g, b;
};

struct _SortableShapeObjectClass
{
  /* Parent class structure */
  GObjectClass parent_class;

  /* class members */
  void (*draw)                   (SortableShapeObject *, double x, double y);
  void (*set_cairo_context)      (SortableShapeObject *, cairo_t *);
};

/* used by SORTABLE_SHAPE_TYPE_OBJECT */
GType sortable_shape_object_get_type (void);

/*
 * Method definitions.
 */

void sortable_shape_object_set_color (SortableShapeObject *self, double r,
    double g, double b);
void sortable_shape_object_set_cairo_context (SortableShapeObject *self,
    cairo_t *cr);

#endif /* __SORTABLE_SHAPE_OBJECT_H__ */
