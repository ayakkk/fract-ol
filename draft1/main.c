#include "fractol.h"

static int ft_strcmp(const char *s1, const char *s2){
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}

static char * ignore_case(char * s1){
	size_t i = 0;
	while(i < ft_strlen(s1) ){
		if (s1[i] >= 'a' && s1[i] <= 'z'){
			s1[i] -= 32;
		}
		i++;
	}
	return s1;
}

static void classify_set(t_fractol *a, char **argv){
	char * str = ignore_case(argv[1]);

	if (ft_strcmp(str, "JULIA") == 0){
		a-> set = JULIA;
		return ;
	}
	else if (ft_strcmp(str, "MANDELBROT") == 0){
		a-> set = MANDELBROT;
		return ;
	}
	ft_error();

}


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

	a-> ratio = 1;

	a->color = 0;
    a->adr = NULL;
    a->bits_per_pixel = 0;

    a->line_length = 0;
    classify_set(a, argv);
}


void	ft_mlx_init(t_fractol *f)
{
	printf("in func ft mlx init\n");
	f->mlx = mlx_init();
	if (!f->mlx){
		printf("mlx connection error");
		exit(1);
	}
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Fractol");
	if (!f->win){
		printf("window creation error");
	}
	complex_init(f);
	f-> m = mlx_new_image(f-> mlx, WIDTH, HEIGHT);
	f-> adr = mlx_get_data_addr(f-> m, &f-> bits_per_pixel, &f-> line_length, &f->endian);
}



__attribute__((destructor))
static void destructor() {
    system("leaks -q fractol");
}


int main(int argc, char **argv){
    t_fractol a;

    if (argc < 2)
        ft_error();
	fractal_init(&a, argv);
	classify_set(&a, argv);
	ft_mlx_init(&a);
	rerender(&a);

	mlx_hook(a.win, 2, 1L<<0, key_press, &a);
	mlx_hook(a.win, 4, 1L<<2, mouse_press, &a);
	mlx_hook(a.win, 17, 1L<<2, x_button, &a);
	mlx_expose_hook(a.win, rerender, &a);

	mlx_loop(a.mlx);
	return 0;
}