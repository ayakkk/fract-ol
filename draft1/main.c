#include "fractol.h"
#include "mlx.h"

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
	get_complex_layout(f);
	// color_shift(f);
}

void parse_args(){
	classify_set();
	julia_init();
}

void ft_error(){
	write(1, "error\n", 6);
	exit(1);
}

int ignore_case(){

}

static void classify_set(t_fractol *a, char **argv){
    if (ignore_case(argv[1], "mandelbrot", 'm', '1'))
		a->set = MANDELBROT;
	else if (ignore_case(argv[1], "julia", 'j', '2'))
		a->set = JULIA;
	else
		ft_error(1);
}

static void fractal_init(t_fractol *a, int argc, char **argv){
    a->mlx = NULL;
	a->win = NULL;
	a->img = NULL;
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
	// a->palette = NULL;
	// a->color_pattern = -1;
	// a->color = 0;
    classify_set(&a, argv);
    init_set();
    get_color(); //need colors
}


__attribute__((destructor))
static void destructor() {
    system("leaks -q a.out");
}


int main(int argc, char **argv){
    t_fractol a;
	// void	*mlx;

    if (argc < 2)
        ft_error(1);

    fractal_init(&a, argc, argv);
	parse_args();
	ft_mlx_init();


	// mlx = mlx_init();
	// mlx_put_image_to_window();


}