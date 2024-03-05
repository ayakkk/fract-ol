/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakasuj <anakasuj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 21:48:06 by anakasuj          #+#    #+#             */
/*   Updated: 2024/03/05 12:41:58 by anakasuj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q fractol");
// }
static int	is_float(const char *str)
{
	int		dot_count;
	size_t	i;

	if (ft_strlen((char *)str) == 1 && !ft_isdigit(str[0]))
		return (-1);
	if (str[0] != '\0' && str[1] != '\0'
		&& !ft_isdigit(str[0]) && str[0] != '+' && str[0] != '-'
		&& !ft_isdigit(str[1]))
		return (-1);
	dot_count = 0;
	i = 1;
	while (str[i] != '\0')
	{
		if (str[i] == '.')
			dot_count++;
		if (dot_count > 1)
			return (-1);
		if (!ft_isdigit(str[i]) && str[i] != '.')
			return (-1);
		i++;
	}
	return (1);
}

static int	is_valid_parameter(int argc, char **argv)
{
	char	*str;

	if (argc < 2 || argc > 4)
		return (-1);
	str = convert_to_upper(argv[1]);
	if (ft_strcmp(str, "MANDELBROT") == 0 && argc == 2)
		return (0);
	if (ft_strcmp(str, "JULIA") == 0)
	{
		if (argc == 3)
		{
			if (ft_strcmp(argv[2], "a") == 0 || ft_strcmp(argv[2], "b") == 0)
				return (0);
		}
		else if (argc == 4)
		{
			if (is_float(argv[2]) == 1 && is_float(argv[3]) == 1)
				return (0);
		}
		else
			return (-1);
	}
	return (-1);
}

static int	print_parameter_error(void)
{
	ft_putstr_fd("\033[31mError: Invalid arguments provided.\n"
		"Usage:\n"
		"  ./fractol MANDELBROT\n"
		"  ./fractol JULIA a\n"
		"  ./fractol JULIA b\n"
		"  ./fractol JULIA [imaginary_part] [real_part]  \n\n"
		"Where [real_part] and [imaginary_part] are floating-"
		"point numbers representing the complex number for the "
		"Julia set calculation.\n\n"
		"Please provide the correct arguments according to the "
		"usage guidelines above.\n\033[0m", 2);
	return (-1);
}

static void	ft_mlx_init(t_fractol *f)
{
	f->mlx = mlx_init();
	if (!f->mlx)
	{
		printf("mlx connection error");
		exit(1);
	}
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Fract-ol");
	if (!f->win)
		ft_error();
	complex_init(f);
	f->m = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->adr = mlx_get_data_addr(f->m, &f->bits_per_pixel, &f->line_length,
			&f->endian);
}

int	main(int argc, char **argv)
{
	t_fractol	a;

	if (is_valid_parameter(argc, argv) < 0)
		return (print_parameter_error());
	fractal_init(&a, argc, argv);
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
