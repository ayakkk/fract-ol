#include "fractol.h"

//zooms by keeping the same ratio
static void	zoom(t_fractol *f, double zoom)
{
	double	center_r;
	double	center_i;

	center_r = f->min_r - f->max_r;
	center_i = f->max_i - f->min_i;
	f->max_r = f->max_r + (center_r - zoom * center_r) / 2;
	f->min_r = f->max_r + zoom * center_r;
	f->min_i = f->min_i + (center_i - zoom * center_i) / 2;
	f->max_i = f->min_i + zoom * center_i;
}


//moves by changing the points 
static void	move(t_fractol *f, double distance, char direction)
{
	double	center_r;
	double	center_i;

	center_r = f->max_r - f->min_r;
	center_i = f->max_i - f->min_i;
	if (direction == 'R')
	{
		f->min_r += center_r * distance;
		f->max_r += center_r * distance;
	}
	else if (direction == 'L')
	{
		f->min_r -= center_r * distance;
		f->max_r -= center_r * distance;
	}
	else if (direction == 'D')
	{
		f->min_i -= center_i * distance;
		f->max_i -= center_i * distance;
	}
	else if (direction == 'U')
	{
		f->min_i += center_i * distance;
		f->max_i += center_i * distance;
	}
}


//process key stuff
int key_press(int keycode, void *param){
	if (keycode == 'w')
    {
        printf("Move Forward\n");
    }
    else if (keycode == 'a')
    {
        printf("Move Left\n");
    }
	else if (keycode == 'd')
    {
        printf("Move Right\n");
    }
	else if (keycode == 's')
    {
        printf("Move Back\n");
    }
	else if (keycode == 65307){ //CHECCKCKCKCKKCK
		printf("ESC\n");
		exit(1);
	}
	return 0;
}

int mouse_press(int button, int x, int y, void *param)
{
    // Check which mouse button was pressed
    if (button == 1) // Left click
    {
        printf("Left click at (%d, %d)\n", x, y);
    }
    else if (button == 2) // Right click
    {
        printf("Right click at (%d, %d)\n", x, y);
    }
	else if (button == 4) // Zoom In
    {
        printf("Zoom in at (%d, %d)\n", x, y);
    }
	else if (button == 5) // Zoom out
    {
        printf("Zoom out at (%d, %d)\n", x, y);
    }
    return (0);
}

// int calculate_color(int x){
// 	// printf("%i \n", x);
// 	if (x < 0.005)
// 		return 0x8ae067;
// 	if (x == 0.25)
//         return 0x8ae067;
// 	// if (x > 150)
// 	// 	return 0xc690f5;
// 	else if (x == 0.3861)
// 		return 0xD7E4FF;
// 	return 0xFF4500; 
// }

// int create_rgb(int r, int g, int b) {
//     return (r << 16) | (g << 8) | b;
// }

unsigned int set_color_two(int nb_iter) {
    if (nb_iter == MAX_ITERATIONS)
        return 0x000000; // Black for points inside the fractal
    // Create a gradient effect for points outside the fractal
    // This is a simple example; customize the color transformation as needed
    int red = (nb_iter * 5) % 255;
    int green = (nb_iter * 10) % 255;
    int blue = (255 * nb_iter / MAX_ITERATIONS) % 255;
    return (red << 16) | (green << 8) | blue;
}


//loop through every pixel, and display ("put image to window") at the end
int rerender(t_fractol *f){
    int		x;
	int		y;
	double	ar;
	double	ai;
	int		nb_iter = 1;

	// int color_index = nb_iter % 5; 
	printf("in func rerender: \n");
	mlx_clear_window(f->mlx, f->win);
	y = -1;

	init_color_storage(f);
	// int color = 0;
	while (y++ < WIDTH)
	{
		x = -1;
		while (x++ < HEIGHT)
		{
			// Convert pixel coordinate (x, y) to complex number (ar, ai)
			ar = f->min_r + (double) x * (f->max_r - f->min_r) / WIDTH;
			ai = f->max_i + (double) y * (f->min_i - f->max_i) / HEIGHT;
			nb_iter = fractal_iter_calculation(f, ar, ai);
			// my_mlx_pixel_put(f, x, y, nb_iter); //HEREREREREREREERE

			printf("nb_iter: %d \n", nb_iter);
			printf(" %d  %d \n", x, y);
			// int color = set_color_two(nb_iter);
			// int color = set_color(f, x, nb_iter);
			int color_index = nb_iter % 5; // Choose color based on nb_iter
        	int color = f->color_storage[color_index]; // Get color from storage
			printf("color ind:  %d \n", color_index);
				// for (int i = 0; i < 10; i++) {
				// 	printf("Color %d: #%06X\n", i, f->color_storage[i]);
				// }
			printf("color:  %d \n", color);
       	 	// my_mlx_pixel_put(f, x, y, color); // Use your function to put the pixel
			my_mlx_pixel_put(f, y, x, color); //HEREREREREREREERE
			// set_color(f, x, y, color);
			// set_color
			// sleep(10);
			// exit(1);
			// set_color(f, x, y, 0xD7E4FF);
		}
		// printf("nb iter: %d \n", f->nb_iter);
		
	}

	free(f->color_storage);
	mlx_put_image_to_window(f->mlx, f->win, f->m, 1, 0);

	return 0;
}
