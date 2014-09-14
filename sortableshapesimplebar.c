#include "sortableshapesimplebar.h"

struct _SortableShapeSimpleBarPrivate
{
  guint dummy;
};

G_DEFINE_TYPE_WITH_PRIVATE (SortableShapeSimpleBar, sortable_shape_simple_bar, SORTABLE_SHAPE_TYPE_OBJECT);


static void
sortable_shape_simple_bar_draw (SortableShapeObject *self, double x, double y)
{

  cairo_set_source_rgb (self->cr, self->r, self->g, self->b);
  cairo_rectangle (self->cr, x, y, self->width, self->height);
  cairo_fill (self->cr);
}

static void
sortable_shape_simple_bar_class_init (SortableShapeSimpleBarClass *klass)
{
  SortableShapeObjectClass *sortable_shape_class =\
      SORTABLE_SHAPE_OBJECT_CLASS (klass);
  sortable_shape_class->draw = sortable_shape_simple_bar_draw;
}



static void
sortable_shape_simple_bar_init (SortableShapeSimpleBar *self)
{
  /* sortable_shape_simple_bar_get_instance_private() is generated by G_DEFINE_TYPE_WITH_PRIVATE()
   * above, and it's local to the current compilation unit.
   */
  /* SortableShapeSimpleBarPrivate *priv = sortable_shape_simple_bar_get_instance_private (self); */

}
