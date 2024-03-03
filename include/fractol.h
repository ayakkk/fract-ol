/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 22:14:00 by anakasuj          #+#    #+#             */
/*   Updated: 2024/03/03 15:11:56 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
// # include "mlx_int.h" //for linux ver of minilibx
# include "libft.h"
# include <libc.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h> //possibly not necessary
# include <string.h>

# define MANDELBROT 1
# define JULIA 2
# define WIDTH 1000
# define HEIGHT 1000
# define MAX_ITERATIONS 200

//k = complex constants , (ki and kr)
//sx, rx, fx for bonus, shifting n rotation stuff

//zi and zr represents the currents pts in the interation process
//cr anc ci represent the real and imaginary parts of c

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	void	*m;
	char	*buf;
	int		set;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
	double	kr;
	double	ki;
	double	sx;
	double	rx;
	double	fx;
	double	ratio;
	int		nb_iter;
	double	j_constant_x;
	double	j_constant_y;
	int		color;
	char	*adr;
	int		bits_per_pixel;
	int		endian;
	int		line_length;
	int		color_storage[5];
}			t_fractol;

//main
void		ft_error(void);
void		print_fractol(t_fractol *frac);
int			x_button(int keycode, t_fractol *param);

//utils
char		*convert_to_upper(char *s1);
int			ft_strcmp(const char *s1, const char *s2);
void		classify_set(t_fractol *a, char **argv);
void		fractal_init(t_fractol *a, int argc, char **argv);

//fractol
void		complex_init(t_fractol *f);
void		init_set(void);
void		julia_init(void);
int			fractal_iter_calculation(t_fractol *f, double ar, double ai);
int			mandelbrot(double cr, double ci);

//colors
void		set_color(t_fractol *a, int i, int color);
void		my_mlx_pixel_put(t_fractol *a, int i, int j, int color);
void		init_color_storage(t_fractol *f);

//render
int			rerender(t_fractol *f);
int			key_press(int keycode, t_fractol *param);
int			mouse_press(int button, int x, int y, t_fractol *param);

//ft_atof
double		ft_atof(const char *str);

#endif