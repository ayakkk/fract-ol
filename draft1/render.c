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
int key_press(){
	return 0;
}

int trackpad(t_fractol *a){
	
	zoom(a, 1);
	move(a, 1, 1);
	return 0;
}

int rerender(t_fractol *f){
    int		x;
	int		y;
	int	ar;
	int	ai;
	int		nb_iter;

	mlx_clear_window(f->mlx, f->win);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			ar = f->min_r + x * (f->max_r - f->min_r) / WIDTH;
			ai = f->max_i + y * (f->min_i - f->max_i) / HEIGHT;
			nb_iter = fractal_calculation(f, ar, ai);
			my_mlx_pixel_put(f, i, j, 127);
			//set color HERE
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->m, 0, 0);

	return 0;
}


// for (int i = 0; i< HEIGHT; i++){
// 		for (int j = 0 ; j < WIDTH / 2; j ++){
			
// 		}
// 	}
// 	mlx_put_image_to_window(f->mlx, f->win, f->m, 0, 0);