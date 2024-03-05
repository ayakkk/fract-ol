/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aya <aya@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 21:48:06 by anakasuj          #+#    #+#             */
/*   Updated: 2024/03/05 22:56:52 by aya              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	shift_real_axis(
	double shift_amount,
	double extend_amount,
	t_fractol *param)
{
	param-> min_r += shift_amount;
	param-> max_r += extend_amount;
	rerender((t_fractol *)param);
}

static void	shift_imaginary_axis(
	double shift_amount,
	double extend_amount,
	t_fractol *param)
{
	if (param->set == MANDELBROT)
	{
		param-> min_i += shift_amount;
		param-> max_i += extend_amount;
	}
	else if (param->set == JULIA)
	{
		param-> min_i -= shift_amount;
		param-> max_i -= extend_amount;
	}
	rerender((t_fractol *)param);
}

static void	adjust_zoom(double ratio, t_fractol *param)
{
	param->ratio *= ratio;
	rerender((t_fractol *)param);
}

int	key_press(int keycode, t_fractol *param)
{
	if (keycode == 'w')
		adjust_zoom(1 / 1.1, param);
	else if (keycode == 's')
		adjust_zoom(1.1, param);
	else if (keycode == 65364)
		shift_real_axis(0.1, 0.1, param);
	else if (keycode == 65362)
		shift_real_axis(-0.1, -0.1, param);
	else if (keycode == 65361)
		shift_imaginary_axis(-0.1, -0.1, param);
	else if (keycode == 65363)
		shift_imaginary_axis(0.1, 0.1, param);
	else if (keycode == 65307)
	{
		write(1, "ESC\n", 5);
		exit(1);
	}
	return (0);
}
