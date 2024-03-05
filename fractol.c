/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aya <aya@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 21:48:06 by anakasuj          #+#    #+#             */
/*   Updated: 2024/03/05 13:14:45 by aya              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	return (n);
}

//z = z^2 + k
// The julia function calculates the iteration count for a point
// to determine its behavior in the Julia set for
//  a given complex parameter k (represented by fractol->kr + fractol->ki*i).

//starting real and imaginary valyes diff
//find julia starting values

//change the sign of i  
int	julia(t_fractol *fractol, double zr, double zi)
{
	int		n;
	double	tmp;

	n = 0;
	while (n < MAX_ITERATIONS)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		// tmp = 2 * zr * zi + fractol->j_constant_r;
		// zr = (zr * zr) - (zi * zi) + fractol->j_constant_i;
		tmp = 2 * zr * zi + fractol->j_constant_i;
		zr = (zr * zr) - (zi * zi) + fractol->j_constant_r;
		zi = tmp;
		n++;
	}
	return (n);
}

int	fractal_iter_calculation(t_fractol *f, double ar, double ai)
{
	int	nb_iter;

	nb_iter = -1;
	if (f->set == MANDELBROT)
		nb_iter = mandelbrot(ar, ai);
	else if (f->set == JULIA)
		nb_iter = julia(f, ar, ai);
	return (nb_iter);
}

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

void	ft_error(void)
{
	write(1, "error\n", 6);
	exit(1);
}
