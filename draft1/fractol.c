#include "fractol.h"

//checks for values,
//if none provided, default julia values
void init_set(){
    get_color();

}

//check if julia set
//diff case for julia set 
static void julia_init(){

    set_color();
}

//z = z^2 + k
double mandelbrot(t_fractol *fractol, int kr, int ki)
{
	double	zr;
	double	zi;
	int		i;

	zr = 0;
	zi = 0;
	i = -1;
	while (++i < 256 && zr * zr + zi * zi < 4)
	{
		double tmp = zr * zr - zi * zi + fractol->kr;
		zi = 2 * zr * zi + fractol->ki;
		zr = tmp;
	}
	return (1.0 / (i + 2));
}

//z = z^2 + k
int julia(t_fractol *fractol, int zr, int zi)
{
	int	i;

	i = 0;
	while (i < 256 && zr * zr + zi * zi < 4)
	{
		int tmp = zr * zr - zi * zi + fractol->kr;
		zi = 2 * zr * zi + fractol->ki;
		zr = tmp;
		i++;
	}
	return (1.0 / (i + 2));
}

int	fractal_calculation(t_fractol *f, int ar, int ai)
{
    int		x;
	int		y;
	int	ar;
	int	ai;
	int	nb_iter;

	if (f->set == MANDELBROT)
		nb_iter = mandelbrot(f, ar, ai);
	else if (f->set == JULIA)
		nb_iter = julia(f, ar, ai);
	return (nb_iter);
}


/* set_complex:
*	Maps the complex number axes to the window width and height to
*	create an equivalence between a given pixel and a complex number.
*		- The Mandelbox set real and imaginary axes range from 4 to -4
*		so the edges are mapped to those numbers for the fractal to appear
*		centered.
*		- Julia needs a bit more space to the right than Mandelbrot or
*		Burning Ship, so the mapping must also be shifted slightly.
*	Also, one of the edges is always calculated according to the other edges
*	to avoid fractal distortion if the window proportions change.
*/

void	complex_init(t_fractol *f)
{
    if (f->set == JULIA)
	{
		f->min_r = -2.0;
		f->max_r = 2.0;
		f->min_i = -2.0;
		f->max_i = f->min_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
	}
	else
	{
		f->min_r = -2.0;
		f->max_r = 1.0;
		f->max_i = -1.5;
		f->min_i = f->max_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
	}
}
