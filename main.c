#include <gtk/gtk.h>

#include "csort.h"
#include "sortableshape.h"
#include "sortableshapesimplebar.h"
#include "sortableshapearrayobject.h"

static gboolean
draw_cb (GtkWidget *widget, cairo_t *cr, gpointer data)
{
  SortableShapeArrayObject *array = (SortableShapeArrayObject *) data;

  sortable_shape_array_object_set_cairo_context (array, cr);

  sortable_shape_array_object_interactive_sort (array, csort_bubble_sort,
      sortable_shape_array_object_cmp_by_height);

  return FALSE;
}

int
main (int argc, char *argv[])
{
  GtkWidget *window, *drawing_area;

  SortableShapeArrayObject *array;

  array = sortable_shape_array_object_new ();

  sortable_shape_array_object_simple_bar_create (array, 4,
      24.0, 60.0, 81.0, 0.0, 0.0,
      24.0, 30.0, 0.0, 28.0, 0.0,
      24.0, 90.0, 0.0, 0.0, 90.0,
      24.0, 70.0, 0.0, 20.0, 60.0);


  gtk_init (&argc, &argv);

  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window), "Window");
  drawing_area = gtk_drawing_area_new ();

  gtk_widget_set_size_request (drawing_area, 100, 100);

  g_signal_connect (drawing_area, "draw", G_CALLBACK (draw_cb), NULL);
  g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), array);


  gtk_container_add (GTK_CONTAINER (window), drawing_area);

  gtk_widget_show (window);
  gtk_widget_show (drawing_area);

  gtk_main ();

  return 0;
}
