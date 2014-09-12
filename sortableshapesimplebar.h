/*
 * Copyright/Licensing information.
 */

/* inclusion guard */
#ifndef __SORTABLE_SHAPE_SIMPLE_BAR_H__
#define __SORTABLE_SHAPE_SIMPLE_BAR_H__

#include "sortableshape.h"
/*
 * Potentially, include other headers on which this header depends.
 */

/*
 * Type macros.
 */
#define SORTABLE_SHAPE_TYPE_SIMPLE_BAR                  (sortable_shape_simple_bar_get_type ())
#define SORTABLE_SHAPE_SIMPLE_BAR(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), SORTABLE_SHAPE_TYPE_SIMPLE_BAR, SortableShapeSimpleBar))
#define SORTABLE_SHAPE_IS_SIMPLE_BAR(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SORTABLE_SHAPE_TYPE_SIMPLE_BAR))
#define SORTABLE_SHAPE_SIMPLE_BAR_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass), SORTABLE_SHAPE_TYPE_SIMPLE_BAR, SortableShapeSimpleBarClass))
#define SORTABLE_SHAPE_IS_SIMPLE_BAR_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass), SORTABLE_SHAPE_TYPE_SIMPLE_BAR))
#define SORTABLE_SHAPE_SIMPLE_BAR_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj), SORTABLE_SHAPE_TYPE_SIMPLE_BAR, SortableShapeSimpleBarClass))

typedef struct _SortableShapeSimpleBarPrivate SortableShapeSimpleBarPrivate;

typedef struct _SortableShapeSimpleBar        SortableShapeSimpleBar;
typedef struct _SortableShapeSimpleBarClass   SortableShapeSimpleBarClass;


struct _SortableShapeSimpleBar
{
  /* Parent instance structure */
  SortableShapeObject parent_instance;

  /* instance members */
};

struct _SortableShapeSimpleBarClass
{
  /* Parent class structure */
  SortableShapeObjectClass parent_class;

  /* class members */
};

/* used by SORTABLE_SHAPE_TYPE_SIMPLE_BAR */
GType sortable_shape_simple_bar_get_type (void);

/*
 * Method definitions.
 */

#endif /* __SORTABLE_SHAPE_SIMPLE_BAR_H__ */
