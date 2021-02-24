#include <gtk/gtk.h>
#include <iostream>
#include <math.h>

void on_draw_event (GtkWidget *widget, cairo_t *cr, gpointer data)
{
    cairo_set_source_rgb(cr, 0, 0, 0);
    cairo_move_to(cr, 100, 200);
    cairo_line_to(cr, 100, 300);
    
    cairo_move_to(cr, 200, 150);
    cairo_line_to(cr, 300, 200);
    
    cairo_move_to(cr, 200, 350);
    cairo_line_to(cr, 300, 300);
    int n = 10;
    for (int i = 0; i <= n; i++){
        cairo_move_to(cr, 100 + i*100/n, 200 + i*50/n);
        cairo_line_to(cr, 200 + i*100/n, 150 + i*50/n);
    }
    for (int i = 0; i <= n; i++){
        cairo_move_to(cr, 100, 200 + i*100/n);
        cairo_line_to(cr, 200, 250 + i*100/n);
    }
    for (int i = 0; i <= n; i++){
        cairo_move_to(cr, 200 + i*100/n, 250 - i*50/n);
        cairo_line_to(cr, 200 + i*100/n, 350 - i*50/n);
    }
    cairo_stroke(cr);
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
