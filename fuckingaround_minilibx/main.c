#include "fractols.h"

// int	close(int keycode, t_vars *vars)
// {
// 	mlx_destroy_window(vars->mlx, vars->win);
// 	return (0);
// }

// int	draw_fractal(t_fractal *fractal, char *query, double cx, double cy)
// {
// 	fractal->x = 0;
// 	fractal->y = 0;

//     char * s = "here";

// 	while (fractal->x < SIZE)
// 	{
// 		while (fractal->y < SIZE)
// 		{
// 			// if (ft_strncmp(query, "mandel", 7) == 0)
// 			// 	calculate_mandelbrot(fractal);
//             if (ft_strncmp(query, "mandel", 7) == 0){
//                 printf("%s", s);
//                 calculate_mandelbrot(fractal);
//             }
// 			else if (ft_strncmp(query, "julia", 6) == 0)
// 				calculate_julia(fractal, cx, cy);
// 			else if (ft_strncmp(query, "ship", 5) == 0)
// 				calculate_burning_ship(fractal);
// 			else
// 			{
// 				ft_putendl_fd("Available fractals: mandel, julia, ship", 1);
// 				exit_fractal(fractal);
// 			}
// 			fractal->y++;
// 		}
// 		fractal->x++;
// 		fractal->y = 0;
// 	}
// 	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image, 0,
// 			0);
// 	return (0);
// }

int classify(){

}

int	main(int argc, char *argv[])
{
	t_vars vars;
    // t_fractal fractal;

	if (argc != 2) { //argc=4? (type, number, complex number + 1 ???????)
		printf("error");
		exit(1);
	}
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Fract-ol!");
	

    // fractal.mlx = vars.mlx;
    // fractal.window = vars.win;
    // fractal.image = mlx_new_image(vars.mlx, FRACTAL_SIZE, FRACTAL_SIZE);
    // fractal.data = (int *) mlx_get_data_addr(fractal.image, &fractal.bpp, &fractal.size_line, &fractal.endian);
    // fractal.x = 0;
    // fractal.y = 0;
    
	// int x = draw_fractal(vars, "mandel", 0, 0);
	// mlx_hook(vars.win, 2, 1L << 0, close, &vars);
	// mlx_loop(vars.mlx);
}