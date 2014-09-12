#include <gtk/gtk.h>
#include "sortableshape.h"
#include "sortableshapesimplebar.h"

static gboolean
draw_cb (GtkWidget *widget, cairo_t *cr, gpointer data)
{
  guint width, height;
  GdkRGBA color;
  SortableShapeSimpleBar *bar;
  SortableShapeObject *shape;

  bar = g_object_new (SORTABLE_SHAPE_TYPE_SIMPLE_BAR, NULL);
  shape = SORTABLE_SHAPE_OBJECT (bar);

  //SORTABLE_SHAPE_OBJECT_CLASS (shape)->set_cairo_context (shape, cr);

/*
  width = gtk_widget_get_allocated_width (widget);
  height = gtk_widget_get_allocated_height (widget);
  cairo_arc (cr,
             width / 2.0, height / 2.0,
             MIN (width, height) / 2.0,
             0, 2 * G_PI);


  SORTABLE_SHAPE_OBJECT_CLASS (shape)->set_cairo_context (shape, cr);

  gtk_style_context_get_color (gtk_widget_get_style_context (widget),
                               0,
                               &color);
  gdk_cairo_set_source_rgba (cr, &color);

  cairo_fill (cr);
*/
  return FALSE;
}

int
main (int argc, char *argv[])
{
  GtkWidget *window, *drawing_area;

  gtk_init (&argc, &argv);

  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window), "Window");
  drawing_area = gtk_drawing_area_new ();

  gtk_widget_set_size_request (drawing_area, 100, 100);

  g_signal_connect (drawing_area, "draw", G_CALLBACK (draw_cb), NULL);
  g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);


  gtk_container_add (GTK_CONTAINER (window), drawing_area);

  gtk_widget_show (window);
  gtk_widget_show (drawing_area);

  gtk_main ();

  return 0;
}
