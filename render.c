/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aya <aya@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 21:48:17 by anakasuj          #+#    #+#             */
/*   Updated: 2024/02/24 16:50:29 by aya              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_press(int keycode, t_fractol *param)
{
	if (keycode == 'w')
	{
		param->ratio /= 1.1;
		rerender((t_fractol *)param);
	}
	else if (keycode == 's')
	{
		param->ratio *= 1.1;
		rerender((t_fractol *)param);
	}
	// else if (keycode ==  65362){ //ARROW UP
		
	// }
	// else if (keycode ==  65364){ //ARROW DOWN
		
	// }
	// else if (keycode ==  65361){ //ARROW LEFT
		
	// }
	// else if (keycode ==  65363){ //ARROW RIGHT
		
	// }
	else if (keycode == 65307)
	{
		printf("ESC\n");
		exit(1);
	}
	return (0);
}

int	x_button(int keycode, t_fractol *param)
{
	(void)keycode;
	(void)param;
	printf("closing \n");
	exit(1);
}

//4 = zoom in, 5 = zoom out
int	mouse_press(int button, int x, int y, t_fractol *param)
{
	(void)x;
	(void)y;
	if (button == 4)
	{
		param->ratio *= 1.1;
		rerender((t_fractol *)param);
	}
	else if (button == 5)
	{
		param->ratio /= 1.1;
		rerender((t_fractol *)param);
	}
	return (0);
}

//loop through every pixel, and display ("put image to window") at the end
int	rerender(t_fractol *f)
{
	int		x;
	int		y;
	double	ar;
	double	ai;
	int		nb_iter;

	nb_iter = 1;
	// mlx_clear_window(f->mlx, f->win);
	init_color_storage(f);
	y = -1;
	while (y++ < WIDTH)
	{
		x = -1;
		// x = HEIGHT;
		while (x++ < HEIGHT)
		// while (x-- > 0)
		{
			ai = f->min_r + (double)x * (f->max_r - f->min_r) / HEIGHT;
			ar = f->max_i + (double)y * (f->min_i - f->max_i) / WIDTH;
			nb_iter = fractal_iter_calculation(f, f->ratio * ar, f->ratio * ai);
			my_mlx_pixel_put(f, x, y, f->color_storage[nb_iter % 5]);
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->m, 1, 0);
	return (0);
}
