/*
 * Copyright/Licensing information.
 */

/* inclusion guard */
#ifndef __SORTABLE_SHAPE_ARRAY_OBJECT_H__
#define __SORTABLE_SHAPE_ARRAY_OBJECT_H__

#include <glib-object.h>
#include <cairo.h>

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

SortableShapeArrayObject *sortable_shape_array_object_new (cairo_t *cr);
int sortable_shape_array_object_cmp_by_height (void * a, void * b);


#endif /* __SORTABLE_SHAPE_ARRAY_OBJECT_H__ */
