#include "fractol.h"

int key_press(int keycode, t_fractol *param){
	(void ) param;
	if (keycode == 'w')
		{
		param->ratio /= 1.1;
		rerender((t_fractol *)param);
		}
	else if (keycode == 's')
		{
		param->ratio *= 1.1;
		rerender((t_fractol *)param);
		}
	else if (keycode == 65307){
		printf("ESC\n");
		exit(1);
	}
	return 0;
}

int x_button(int keycode, t_fractol *param){
	(void)keycode;
	(void)param;
	printf("closing \n");
	exit(1);
}

int mouse_press(int button, int x, int y, t_fractol *param)
{
	(void)x;
	(void)y;
	if (button == 4) // Zoom In
		{
		param->ratio *= 1.1;
		rerender((t_fractol *)param);
		}
	else if (button == 5) // Zoom out
		{
		param->ratio /= 1.1;
		rerender((t_fractol *)param);
		}
	return (0);
}

//loop through every pixel, and display ("put image to window") at the end
int rerender(t_fractol *f){
	int		x;
	int		y;
	double	ar;
	double	ai;
	int		nb_iter = 1;

	mlx_clear_window(f->mlx, f->win);
	init_color_storage(f);
	y = -1;
	while (y++ < WIDTH)
	{
		x = -1;
		while (x++ < HEIGHT)
		{
			// Convert pixel coordinate (x, y) to complex number (ar, ai)
			ar = f->min_r + (double) x * (f->max_r - f->min_r) / HEIGHT;
			ai = f->max_i + (double) y * (f->min_i - f->max_i) / WIDTH;
			nb_iter = fractal_iter_calculation(f, f-> ratio * ar, f-> ratio * ai);
			int color_index = nb_iter % 5;
			int color = f->color_storage[color_index];
			my_mlx_pixel_put(f, y, x, color);
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->m, 1, 0);
	return 0;
}
