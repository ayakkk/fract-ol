#include <mlx.h>
#include "libft/libft.h"

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	close(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int draw_fractal(t_fractal *fractal, char *query, double cx, double cy)
{
 fractal->x = 0;
 fractal->y = 0;
 while (fractal->x < SIZE)
 {
  while (fractal->y < SIZE)
  {
   if (ft_strncmp(query, "mandel", 7) == 0)
    calculate_mandelbrot(fractal);
   else if (ft_strncmp(query, "julia", 6) == 0)
    calculate_julia(fractal, cx, cy);
   else if (ft_strncmp(query, "ship", 5) == 0)
    calculate_burning_ship(fractal);
   else
   {
    ft_putendl_fd("Available fractals: mandel, julia, ship", 1);
    exit_fractal(fractal);
   }
   fractal->y++;
  }
  fractal->x++;
  fractal->y = 0;
 }
 mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image, 0,
  0);
 return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Fract-ol!");

	int x = draw_fractal(vars, "mandel", 0, 0):

	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_loop(vars.mlx);
}