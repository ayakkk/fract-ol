#include "fractol.h"

//checks for values,
//if none provided, default julia values
void init_set(){
    // set_color();

}

//check if julia set
//diff case for julia set 
void julia_init(){

    // set_color();

}

//z = z^2 + k
// double mandelbrot(t_fractol *fractol )
// {
// 	double	zr;
// 	double	zi;
// 	int		i;

// 	zr = 0;
// 	zi = 0;
// 	i = -1;
// 	while (i++ < 256 && zr * zr + zi * zi < 4)
// 	{
// 		double tmp = zr * zr - zi * zi + fractol->kr;
// 		zi = 2 * zr * zi + fractol->ki;
// 		zr = tmp;
// 	}
// 	return (1.0 / (i + 2));
// }

// double mandelbrot(t_fractol *f, double ar, double ai)
// {
// 	double	zr;
// 	double	zi;
// 	int		i;

// 	zr = 0;
// 	zi = 0;
// 	i = -1;
// 	while (i++ < 256 && zr * zr + zi * zi < 4)
// 	{
// 		double tmp = zr * zr - zi * zi + ar;
// 		zi = 2 * zr * zi + ai;
// 		zr = tmp;
// 	}
// 	return (1.0 / (i + 2));
// }

int	mandelbrot(double cr, double ci)
{
	int		n;
	double	zr;
	double	zi;
	double	tmp;

	zr = 0;
	zi = 0;
	n = 0;
	while (n < MAX_ITERATIONS)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		tmp = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = tmp;
		n++;
	}
	return (n);
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


// int calculate_color(int nb_iter, int fractal_type) {
//     if (fractal_type == MANDELBROT) {
//         // Mandelbrot specific coloring
//         if (nb_iter >= MAX_ITERATIONS) return 0x000000; // Black for inside
//         return 0x0000FF + (nb_iter * 255 / MAX_ITERATIONS) * 0x00010101; // Gradient from blue to white
//     } else if (fractal_type == JULIA) {
//         // Julia specific coloring
//         if (nb_iter >= MAX_ITERATIONS) return 0x404040; // Dark gray for inside
//         return 0xFF0000 + (nb_iter * 255 / MAX_ITERATIONS) * 0x00010101; // Gradient from red to white
//     } else {
//         // Default or other fractals
//         return 0x8AE067; // A default green color for others
//     }
// }
int fractal_calculation(t_fractol *f, int ar, int ai)
{
	// int x;
	// int wr;
	// int wi;

	// x = -1;
	// wr = 0;
	// wi = 0;
	int	nb_iter;

	if (f->set == MANDELBROT)
		nb_iter = mandelbrot(ar, ai);
	else if (f->set == JULIA)
		nb_iter = julia(f, ar, ai);
	return (nb_iter);

	// while (what < 256 && wr * wr + wi * wi < 4)
	// {
	// 	int tmp = wr * wr - wi * wi + f->kr;
	// 	wi = 2 * wr * wi + f->ki;
	// 	wr = tmp;
	// }
	// my_mlx_pixel_put(&f, wr, wi, what);
// if (f->set == MANDELBROT)
// 	x = mandelbrot(f);
// 	// nb_iter = mandelbrot(f, ar, ai);
// else if (f->set == JULIA)
// 	x = julia(f, ar, ai);
// return (x);
}

void	complex_init(t_fractol *f)
{
	printf("in func complex_init\n");
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
		// print_fractol(f);
	}
}
