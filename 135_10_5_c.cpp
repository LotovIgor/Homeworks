#include <gtk/gtk.h>
#include <iostream>
#include <math.h>

void sq (cairo_t *cr, int x, int y, int i){
    cairo_set_source_rgb(cr, 0, 0, 0);
    cairo_move_to(cr, x, y);
    cairo_line_to(cr, x, y - 40);
    cairo_line_to(cr, x + 20, y - 20);
    cairo_line_to(cr, x, y);
    cairo_stroke_preserve(cr);
    cairo_set_source_rgb(cr, i % 2, i % 2, i % 2);
    cairo_fill(cr);
    
    cairo_set_source_rgb(cr, 0, 0, 0);
    cairo_move_to(cr, x, y - 40);
    cairo_line_to(cr, x + 40, y - 40);
    cairo_line_to(cr, x + 20, y - 20);
    cairo_line_to(cr, x, y - 40);
    cairo_stroke_preserve(cr);
    cairo_set_source_rgb(cr, (i + 1) % 2, (i + 1) % 2, (i + 1) % 2);
    cairo_fill(cr);
    
    cairo_set_source_rgb(cr, 0, 0, 0);
    cairo_move_to(cr, x + 40, y - 40);
    cairo_line_to(cr, x + 40, y);
    cairo_line_to(cr, x + 20, y - 20);
    cairo_line_to(cr, x + 40, y - 40);
    cairo_stroke_preserve(cr);
    cairo_set_source_rgb(cr, i % 2, i % 2, i % 2);
    cairo_fill(cr);
    
    cairo_set_source_rgb(cr, 0, 0, 0);
    cairo_move_to(cr, x + 40, y);
    cairo_line_to(cr, x, y);
    cairo_line_to(cr, x + 20, y - 20);
    cairo_line_to(cr, x + 40, y);
    cairo_stroke_preserve(cr);
    cairo_set_source_rgb(cr, (i + 1) % 2, (i + 1) % 2, (i + 1) % 2);
    cairo_fill(cr);
}

void on_draw_event (GtkWidget *widget, cairo_t *cr, gpointer data)
{
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 8; j++){
            sq(cr, 100 + j * 40, 200 + i * 40, j + 1 + i % 2);
        }
    }
}
 

int main( int argc, char *argv[])
{
   
    gtk_init(&argc, &argv);
 
    GtkWidget *window;
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
    gtk_window_set_title(GTK_WINDOW(window), "Window");
    gtk_container_set_border_width (GTK_CONTAINER (window), 10);
    
    GtkWidget *vbox;
    vbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 1);
    gtk_container_add(GTK_CONTAINER (window), vbox);
 
    GtkWidget *drawing_area;
    drawing_area = gtk_drawing_area_new();

    gtk_box_pack_start (GTK_BOX(vbox), drawing_area, TRUE, TRUE, 10);

    g_signal_connect(G_OBJECT(drawing_area), "draw", G_CALLBACK(on_draw_event), NULL);

    gtk_widget_show_all(window);

    gtk_main();
 
}

