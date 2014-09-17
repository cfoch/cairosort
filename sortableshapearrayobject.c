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
  self->padding = DEFAULT_PADDING;
}



/* public */


static void
sortable_shape_array_object_clear_cairo_context (
    SortableShapeArrayObject * self)
{
  int width, height;
  cairo_surface_t *surface;

  surface = cairo_get_target (self->cr);

  width = cairo_image_surface_get_width (surface);
  height = cairo_image_surface_get_height (surface);

  cairo_rectangle (self->cr, 0, 0, width, height);
  cairo_set_source_rgb(self->cr, 255, 255, 255);
  cairo_fill (self->cr);
}

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

void
_export_to_image (void * array, int len, void * a, void * b, void * dummy_data)
{
  /* TODO: Avoid repeating code. We could create a function that outputs an
    image file. It would save some lines.
  */
  
  cairo_surface_t *surface;
  SortableShapeObject *shape_a, *shape_b;
  struct _data_to_image * data;
  double delta = 70.0;

  data = (struct _data_to_image *) dummy_data;
  surface = cairo_get_target (data->shape_array->cr);
  shape_a = *((SortableShapeObject **) a);
  shape_b = *((SortableShapeObject **) b);

  /* Draw/Output initial state of array*/
  sortable_shape_array_object_clear_cairo_context (data->shape_array);
  sortable_shape_array_object_draw (data->shape_array, 0, 0);
  cairo_surface_write_to_png (surface,
      g_strdup_printf ("out/%d.png", data->step));
  data->step++;

  /* Do animation for item A */
  shape_a->height += delta;  
  sortable_shape_array_object_clear_cairo_context (data->shape_array);
  sortable_shape_array_object_draw (data->shape_array, 0, 0);
  cairo_surface_write_to_png (surface,
      g_strdup_printf ("out/%d.png", data->step));
  data->step++;

  shape_a->height -= delta;  
  sortable_shape_array_object_clear_cairo_context (data->shape_array);
  sortable_shape_array_object_draw (data->shape_array, 0, 0);
  cairo_surface_write_to_png (surface,
      g_strdup_printf ("out/%d.png", data->step));
  data->step++;

  /* Do animation for item B */
  shape_b->height += delta;  
  sortable_shape_array_object_clear_cairo_context (data->shape_array);
  sortable_shape_array_object_draw (data->shape_array, 0, 0);
  cairo_surface_write_to_png (surface,
      g_strdup_printf ("out/%d.png", data->step));
  data->step++;

  shape_b->height -= delta;  
  sortable_shape_array_object_clear_cairo_context (data->shape_array);
  sortable_shape_array_object_draw (data->shape_array, 0, 0);
  cairo_surface_write_to_png (surface,
      g_strdup_printf ("out/%d.png", data->step));
  data->step++;
}

/* This function is too ugly */
void
sortable_shape_array_object_sort_to_images (SortableShapeArrayObject * self,
    void (* csort_func) (void *, int, int, int (*) (void *, void *),
        void (*) (void *, int, void *, void *, void *), void *),
    int (* cmp_func) (void *, void *))
{
  struct _data_to_image *data = malloc (sizeof (struct _data_to_image));
  
  data->shape_array = self;
  data->step = 0;

  csort_func (self->priv->array, self->len, sizeof (SortableShapeObject *),
      *cmp_func, _export_to_image, data);
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
    cairo_t *cr)
{
  int i;
  self->cr = cr;

  for (i = 0; i < self->len; i++) {
    SortableShapeObject *shape;

    shape = self->priv->array[i];
    sortable_shape_object_set_cairo_context (shape, self->cr);
  }

  cairo_rectangle (self->cr, 0, 0, 200, 200);
  cairo_set_source_rgb(self->cr, 255, 255, 255);
  cairo_fill (self->cr);
}

SortableShapeArrayObject *
sortable_shape_array_object_new (cairo_t *cr)
{
  return g_object_new (SORTABLE_SHAPE_ARRAY_TYPE_OBJECT, NULL);
}
