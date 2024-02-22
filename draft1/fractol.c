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
	printf("mandelbrot here\n");
	return (n);
}

//z = z^2 + k
// The julia function calculates the iteration count for a point 
// to determine its behavior in the Julia set for
//  a given complex parameter k (represented by fractol->kr + fractol->ki*i).

// int julia(t_fractol *fractol, int zr, int zi)
// {
// 	int	i;

// 	i = 0;
// 	while (i < 256 && zr * zr + zi * zi < 4)
// 	{
// 		int tmp = zr * zr - zi * zi + fractol->kr;
// 		zi = 2 * zr * zi + fractol->ki;
// 		zr = tmp;
// 		i++;
// 	}
// 	printf("julia here\n");
// 	return (1.0 / (i + 2));
// }

int julia(t_fractol *fractol, double zr, double zi)
{
	int	i;

	i = 0;
	while (i < 256 && zr * zr + zi * zi < 4)
	{
		double tmp = zr * zr - zi * zi + fractol->kr;
		zi = 2 * zr * zi + fractol->ki;
		zr = tmp;
		i++;
	}
	// 直接反復回数を返すことで、色の決定に利用できるようにする
	return i;
}

// int julia(t_fractol *fractol, double zr, double zi)
// {
//     int i;
//     i = 0;
//     while (i < 256 && zr * zr + zi * zi < 4)
//     {
//         double tmp = zr * zr - zi * zi + fractol->kr;
//         zi = 2 * zr * zi + fractol->ki;
//         zr = tmp;
//         i++;
//     }

//     // 色の計算
//     if (i < 256)
//     {
//         // 反復回数に基づいて色を計算する例
//         // ここでは反復回数を基にRGBの各成分を計算しています。
//         // 実際の計算方法は、求めるビジュアル効果に応じて調整してください。
//         int red = (i % 8) * 32; // 例えば、反復回数に基づいて赤色成分を計算
//         int green = (i % 16) * 16; // 緑色成分
//         int blue = (i % 32) * 8; // 青色成分
//         return (red << 16) | (green << 8) | blue; // RGB色を返す
//     }
//     else
//     {
//         // 最大反復回数に達した場合、通常は黒または他の固定色を返す
//         return 0x000000; // 黒
//     }
// }



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

	printf("frac init calc %i \n", f-> set);
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
