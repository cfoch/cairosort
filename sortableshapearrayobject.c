#include <stdlib.h>
#include <unistd.h>

#include "sortableshapearrayobject.h"
#include "sortableshape.h"
#include "sortableshapesimplebar.h"

#define DEFAULT_PADDING       30

struct _SortableShapeArrayObjectPrivate
{
  SortableShapeObject **array;
};

G_DEFINE_TYPE_WITH_PRIVATE (SortableShapeArrayObject,
    sortable_shape_array_object, G_TYPE_OBJECT);

static void
sortable_shape_array_object_class_init (SortableShapeArrayObjectClass *klass)
{
  klass->draw = NULL;
}

static void
sortable_shape_array_object_init (SortableShapeArrayObject *self)
{
  self->priv = G_TYPE_INSTANCE_GET_PRIVATE (self,
      SORTABLE_SHAPE_ARRAY_TYPE_OBJECT, SortableShapeArrayObjectPrivate);
  self->len = 0;
  self->cr = NULL;
  self->padding = DEFAULT_PADDING;
}



/* public */

void
sortable_shape_array_object_draw (SortableShapeArrayObject *self,
    double x, double y)
{
  int i;
  double x_relative, y_relative;

  for (i = 0; i < self->len; i++) {
    SortableShapeObject *shape;

    shape = self->priv->array[i];
    x_relative = i * (shape->width + self->padding);
    y_relative = y;
    SORTABLE_SHAPE_OBJECT_GET_CLASS (shape)->draw (shape, x_relative,
        y_relative);
  }
}

void
sortable_shape_array_object_append (SortableShapeArrayObject *self,
    SortableShapeObject *shape)
{

  self->len++;
  self->priv->array = realloc (self->priv->array,
      self->len * sizeof (SortableShapeObject *));
  self->priv->array[self->len - 1] = shape;
  sortable_shape_object_set_cairo_context (shape, self->cr);
  
  /* TODO: else: Handle Error. */
}



void
sortable_shape_array_object_simple_bar_create (SortableShapeArrayObject *self,
    int len, ...)
{
  va_list arguments;
  int i;

  va_start (arguments, len * 5);
  for (i = 0; i < len; i++) {
    SortableShapeSimpleBar *bar;
    SortableShapeObject *shape;

    bar = g_object_new (SORTABLE_SHAPE_TYPE_SIMPLE_BAR, NULL);
    shape = SORTABLE_SHAPE_OBJECT (bar);

    shape->width = va_arg (arguments, double);
    shape->height = va_arg (arguments, double);
    shape->r = va_arg (arguments, double);
    shape->g = va_arg (arguments, double);
    shape->b = va_arg (arguments, double);

    sortable_shape_array_object_append (self, shape);
  } 
  va_end (arguments);
}

int
sortable_shape_array_object_cmp_by_height (void * a, void * b)
{
  SortableShapeObject **x = (SortableShapeObject **) a;
  SortableShapeObject **y = (SortableShapeObject **) b;

  return (*x)->height - (*y)->height;
}

static void
_do_interactive_sort (void * array, int len, void * a, void * b, void * data)
{
  SortableShapeArrayObject *shape_array = (SortableShapeArrayObject *) data;

  cairo_rectangle (shape_array->cr, 0, 0, 200, 200);
  cairo_set_source_rgb(shape_array->cr, 255, 255, 255);
  cairo_fill (shape_array->cr);

  sortable_shape_array_object_draw (shape_array, 0, 0);

  sleep (1);
}

/* This function is too ugly. Does somebody know how to make it short? */
void
sortable_shape_array_object_interactive_sort (SortableShapeArrayObject * self,
    void (* csort_func) (void *, int, int, int (*) (void *, void *),
        void (*) (void *, int, void *, void *, void *), void *),
    int (* cmp_func) (void *, void *))
{
  csort_func (self->priv->array, self->len, sizeof (SortableShapeObject *),
      cmp_func, _do_interactive_sort, self);
}

void
DEBUG_SORTABLE_SHAPE_ARRAY_OBJECT_BY_HEIGHT (SortableShapeArrayObject * self)
{
  int i;
  printf ("{\n");
  for (i = 0; i < self->len; i++)
    printf ("%.2f,\n", self->priv->array[i]->height);
  printf ("}\n");
}

void
sortable_shape_array_object_set_cairo_context (SortableShapeArrayObject * self,
    cairo_t * cr)
{
  self->cr = cr;

  cairo_rectangle (self->cr, 0, 0, 200, 200);
  cairo_set_source_rgb(self->cr, 255, 255, 255);
  cairo_fill (self->cr);
}

SortableShapeArrayObject *
sortable_shape_array_object_new ()
{
  return g_object_new (SORTABLE_SHAPE_ARRAY_TYPE_OBJECT, NULL);
}
