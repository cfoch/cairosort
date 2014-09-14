/*
 * Copyright/Licensing information.
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
