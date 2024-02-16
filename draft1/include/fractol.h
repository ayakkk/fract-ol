#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include <stdio.h>
# include <math.h>
#include <libc.h>
#include <stdbool.h>
#include <string.h>

# define MANDELBROT 1
# define JULIA 2
# define TRIANGLE 3

# define WIDTH 1000
# define HEIGHT 1000
# define MAX_ITERATIONS 50


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

	int		color;
	char * adr;
	int bits_per_pixel;
	int endian;
	int line_length;
}	t_fractol;

//main
void fractal_init(t_fractol *a, char **argv);
void ft_error(void);
// int ignore_case(const char *str1, const char *str2, char c1, char c2);

// int ignore_case();
// int ignore_case(const char *str1, const char *str2, char c1, char c2);

//fractol
void	complex_init(t_fractol *f);
void init_set();
void julia_init();

//colors
void set_color(t_fractol *a);
void	my_mlx_pixel_put( t_fractol *a , int i, int j, int color);

//render
int	fractal_calculation(t_fractol *f, int ar, int ai);


#endif