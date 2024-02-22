#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
// # include "mlx_int.h" //for linux ver of minilibx
# include "libft.h"
# include <stdio.h>
# include <math.h>
#include <libc.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h> //possibly not necessary

# define MANDELBROT 1
# define JULIA 2
# define TRIANGLE 3

# define WIDTH 1000
# define HEIGHT 1000
# define MAX_ITERATIONS 200


//k = complex constants , (ki and kr)
//sx, rx, fx for bonus, shifting n rotation stuff

//zi and zr represents the currents pts in the interation process
//cr anc ci represent the real and imaginary parts of c


typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	void	*m;
	char	*buf;
	int		set;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
	double	kr;
	double	ki;
	double	sx;
	double	rx;
	double	fx;

	int nb_iter;

	int		color;
	char * adr;
	int bits_per_pixel;
	int endian;
	int line_length;

	int * color_storage; //free this later
}	t_fractol;

//main
void fractal_init(t_fractol *a, char **argv);
void ft_error(void);
void print_fractol(t_fractol *frac);
// int ignore_case(const char *str1, const char *str2, char c1, char c2);

// int ignore_case();
// int ignore_case(const char *str1, const char *str2, char c1, char c2);

//fractol
void	complex_init(t_fractol *f);
void init_set();
void julia_init();
// void fractal_calculation(t_fractol *f, int ar, int ai);
int fractal_iter_calculation(t_fractol *f, double ar, double ai);
int	mandelbrot(double cr, double ci);
// int julia(t_fractol *fractol, double zr, double zi);

//colors
// void set_color(t_fractol *a);
// void set_color(t_fractol *a, int x, int y, int color);
void set_color(t_fractol *a, int i, int color);
void	my_mlx_pixel_put( t_fractol *a , int i, int j, int color);
void init_color_storage(t_fractol *f);

//render
int rerender(t_fractol *f);
int key_press(int keycode, void *param);
int mouse_press(int button, int x, int y, void *param);

#endif