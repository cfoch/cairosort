#include <gtk/gtk.h>

#include "csort.h"
#include "sortableshape.h"
#include "sortableshapesimplebar.h"
#include "sortableshapearrayobject.h"
/*
static gboolean
draw_cb (GtkWidget *widget, cairo_t *cr, gpointer data)
{


  DEBUG_SORTABLE_SHAPE_ARRAY_OBJECT_BY_HEIGHT (array);
  sortable_shape_array_object_interactive_sort(array, csort_bubble_sort,
      sortable_shape_array_object_cmp_by_height, data);
  DEBUG_SORTABLE_SHAPE_ARRAY_OBJECT_BY_HEIGHT (array);

  struct _foo * mydata = (struct _foo *) data;

  sortable_shape_array_object_set_cairo_context (mydata->shape_array, cr);

  sortable_shape_array_object_draw (mydata->shape_array, 0, 0);

  sortable_shape_array_object_to_image (mydata->shape_array, csort_bubble_sort,
      sortable_shape_array_object_cmp_by_height);

  sortable_shape_array_object_draw (mydata->shape_array, 0, 0);



  return FALSE;
}
*/

/*
int
main (int argc, char *argv[])
{
  int a[5] = {4, 2, 1, 6, 3};
  int i, len = 5;
  for (i = 0; i < len; i++)
    printf ("%d\n", ((int *) a)[i]);
  printf ("\n");
  csort_bubble_sort (a, len, sizeof(int), csort_cmp_int_func, csort_do_int_print_example, NULL);

  for (i = 0; i < len; i++)
    printf ("%d\n", a[i]);
  return 1;
}
*/

int
main (int argc, char *argv[])
{
/*
  GtkWidget *window, *drawing_area;
  struct _foo *data = malloc (sizeof (struct _foo));
*/
  SortableShapeArrayObject *array;
  cairo_surface_t *surface;
  cairo_t *cr;

  array = sortable_shape_array_object_new ();
  surface = cairo_image_surface_create (CAIRO_FORMAT_ARGB32, 400, 400);
  cr = cairo_create (surface);
  sortable_shape_array_object_set_cairo_context (array, cr);

  sortable_shape_array_object_simple_bar_create (array, 4,
      24.0, 60.0, 81.0, 0.0, 0.0,
      24.0, 30.0, 0.0, 28.0, 0.0,
      24.0, 90.0, 0.0, 0.0, 90.0,
      24.0, 70.0, 0.0, 20.0, 60.0);
  //sortable_shape_array_object_draw (array, 0, 0);

  //cairo_surface_write_to_png (surface, "example.png");

  sortable_shape_array_object_draw (array, 0, 0);
  sortable_shape_array_object_sort_to_images (array, csort_bubble_sort,
      sortable_shape_array_object_cmp_by_height);


/*
  gtk_init (&argc, &argv);

  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window), "Window");
  drawing_area = gtk_drawing_area_new ();

  gtk_widget_set_size_request (drawing_area, 100, 100);

  data->shape_array = array;
  data->drawing_area = drawing_area;

  printf ("dddummy: %d\n", data->dummy);

  g_signal_connect (drawing_area, "draw", G_CALLBACK (draw_cb), data);
  g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);


  gtk_container_add (GTK_CONTAINER (window), drawing_area);

  gtk_widget_show (window);
  gtk_widget_show (drawing_area);

  gtk_main ();
*/
  return 0;
}
