/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aya <aya@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 21:48:06 by anakasuj          #+#    #+#             */
/*   Updated: 2024/02/25 19:33:05 by aya              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q fractol");
// }

int	main(int argc, char **argv)
{
	t_fractol	a;

	if (argc < 2)
		ft_error();
	fractal_init(&a, argv);
	classify_set(&a, argv);
	ft_mlx_init(&a);
	mlx_clear_window(a.mlx, a.win);
	rerender(&a);
	mlx_hook(a.win, 2, 1L << 0, key_press, &a);
	mlx_hook(a.win, 4, 1L << 2, mouse_press, &a);
	mlx_hook(a.win, 17, 1L << 2, x_button, &a);
	mlx_expose_hook(a.win, rerender, &a);
	mlx_loop(a.mlx);
	return (0);
}
