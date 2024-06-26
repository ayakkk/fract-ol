/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakasuj <anakasuj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 21:48:06 by anakasuj          #+#    #+#             */
/*   Updated: 2024/03/14 17:40:45 by anakasuj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char	*convert_to_upper(char *s1)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(s1))
	{
		if (s1[i] >= 'a' && s1[i] <= 'z')
		{
			s1[i] -= 32;
		}
		i++;
	}
	return (s1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(const unsigned char *)s1 - *(const unsigned char *)s2);
}

void	classify_set(t_fractol *a, char **argv)
{
	char	*str;

	str = convert_to_upper(argv[1]);
	if (ft_strcmp(str, "JULIA") == 0)
	{
		a->set = JULIA;
		return ;
	}
	else if (ft_strcmp(str, "MANDELBROT") == 0)
	{
		a->set = MANDELBROT;
		return ;
	}
	ft_error();
}

static void	set_j_constant(t_fractol *a, int argc, char **argv)
{
	if (argc == 3)
	{
		if (ft_strcmp(argv[2], "a") == 0)
		{
			a->j_constant_i = -0.043;
			a->j_constant_r = 0.32;
		}
		else if (ft_strcmp(argv[2], "b") == 0)
		{
			a->j_constant_i = 0.63;
			a->j_constant_r = -0.3;
		}
	}
	else if (argc == 4)
	{
		a->j_constant_r = ft_atof(argv[2]);
		a->j_constant_i = ft_atof(argv[3]);
	}
}

void	fractal_init(t_fractol *a, int argc, char **argv)
{
	a->mlx = NULL;
	a->win = NULL;
	a->m = NULL;
	a->buf = NULL;
	a->set = -1;
	a->min_r = 0;
	a->max_r = 0;
	a->min_i = 0;
	a->max_i = 0;
	a->ratio = 1;
	a->color = 0;
	a->adr = NULL;
	a->bits_per_pixel = 0;
	a->line_length = 0;
	classify_set(a, argv);
	set_j_constant(a, argc, argv);
}
