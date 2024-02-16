#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
// # include "libft.h"
# include <stdio.h>
# include <math.h>
#include <libc.h>

# define MANDELBROT 1
# define JULIA 2
// # define BURNING_SHIP 3
// # define TRICORN 4
// # define MANDELBOX 5
# define TRIANGLE 3

# define WIDTH 1000
# define HEIGHT 1000
# define MAX_ITERATIONS 60


//k = complex constants , (ki and kr)
//sx, rx, fx for bonus, shifting n rotation stuff

//zi and zr represents the currents pts in the interation process
//cr anc ci represent the real and imaginary parts of c


typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	void	*img;
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
	// int		*palette;
	// int		color_pattern;
	int		color;
}	t_fractol;

#endif