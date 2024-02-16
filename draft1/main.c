#include "fractol.h"


static void classify_set(t_fractol *a, char **argv){
    // if (ignore_case(argv[1], "mandelbrot", 'm', '1'))
	// 	a->set = MANDELBROT;
	// else if (ignore_case(argv[1], "julia", 'j', '2'))
	// 	a->set = JULIA;
	// else //KOKOKOKOKOKOKO
		// ft_error();
	(void ) a;
	(void ) argv;
}


void parse_args(t_fractol *a, char **argv){
	classify_set(a, argv);
	julia_init();
}

void ft_error(){
	write(1, "error\n", 6);
	exit(1);
}

// int ignore_case(){

// 	return 0;
// }

// void fractal_init(t_fractol *a, int argc, char **argv){
void fractal_init(t_fractol *a, char **argv){
    a->mlx = NULL;
	a->win = NULL;
	a->m = NULL;
	a->buf = NULL;
	a->set = -1;
	a->min_r = 0;
	a->max_r = 0;
	a->min_i = 0;
	a->max_i = 0;
	a->kr = 0;
	a->ki = 0;
	a->sx = 0;
	a->rx = 0;
	a->fx = 0;
	// a->color = 0;
    classify_set(a, argv);
    init_set();
    set_color(a); //need colors
}


void	ft_mlx_init(t_fractol *f)
{
	f->mlx = mlx_init();
	if (!f->mlx){
		printf("error connecting to mlx");
		exit(1);
	}
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Fractol");
	if (!f->win){
		printf("error creating window");
	}
	f->sx = 2.0;
	f->rx = 0.5;
	f->fx = 1.0;
	complex_init(f);
	f-> m = mlx_new_image(f-> mlx, WIDTH, HEIGHT);
	f-> adr = mlx_get_data_addr(f-> m, &f-> bits_per_pixel, &f-> line_length, &f->endian);
	
	mlx_loop(f->mlx);
	// color_shift();
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q fractol");
}


int main(int argc, char **argv){
    t_fractol a;
	// void	*p;

    if (argc < 2)
        ft_error();

    // fractal_init(&a, argc, argv);
	fractal_init(&a, argv);
	printf("aaaaaaa\n");
	parse_args(&a, argv);
	ft_mlx_init(&a);

	// mlx = mlx_init();
	// mlx_put_image_to_window();


}