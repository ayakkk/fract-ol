#include "fractol.h"
#include <complex.h>

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

// The mandelbrot function calculates whether a given 
// complex number cr + ci*i (where i is the imaginary unit and cr,
//  ci are real numbers representing the real and imaginary parts of 
// the complex number, respectively) belongs to the Mandelbrot set, 
// based on a maximum number of iterations defined by MAX_ITERATIONS.

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
	// printf("mandelbrot here\n");
	return (n);
}

//z = z^2 + k
// The julia function calculates the iteration count for a point 
// to determine its behavior in the Julia set for
//  a given complex parameter k (represented by fractol->kr + fractol->ki*i).

//starting real and imaginary valyes diff
//find julia starting values


int julia(t_fractol *fractol, double zr, double zi)
{
    int		n;
    double	tmp;

	(void)fractol;
    n = 0;
    while (n < MAX_ITERATIONS)
    {
        if ((zr * zr + zi * zi) > 4.0)
            break ;
        tmp = 2 * zr * zi + JULIA_A; // Use the ci from fractol struct
        zr = (zr * zr) - (zi * zi) + JULIA_B; // Use the cr from fractol struct
        zi = tmp;
        n++;
    }
    // You can add any debug or print statements here if needed
    return (n);
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
int fractal_iter_calculation(t_fractol *f, double ar, double ai)
{
	// int x;
	// int wr;
	// int wi;

	// x = -1;
	// wr = 0;
	// wi = 0;
	int	nb_iter = -1;

	// printf("frac init calc %i \n", f-> set);
	if (f->set == MANDELBROT)
		nb_iter = mandelbrot(ar, ai);
	else if (f->set == JULIA)
		nb_iter = julia(f, ar, ai);
	return (nb_iter);

	// return (julia(f, ar, ai));

	// return (mandelbrot(ar, ai));

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
    if (f->set == JULIA )
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
