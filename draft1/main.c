#include "fractol.h"

void print_fractol(t_fractol *frac) {
  printf("mlx: %p, win: %p, m: %p, buf: %p, set: %d, min_r: %f, max_r: %f, min_i: %f, max_i: %f, kr: %f, ki: %f, sx: %f, rx: %f, fx: %f\n",
         frac->mlx, frac->win, frac->m, frac->buf, frac->set, frac->min_r, frac->max_r, frac->min_i, frac->max_i, frac->kr, frac->ki, frac->sx, frac->rx, frac->fx);
  printf("color: %d, adr: %p, bits_per_pixel: %d, endian: %d, line_length: %d\n",
         frac->color, frac->adr, frac->bits_per_pixel, frac->endian, frac->line_length);
}


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
	printf("comparing %s \n", argv[1]);
	char * str = ignore_case(argv[1]);
	printf("str: %s \n", str);

	if (ft_strcmp(str, "JULIA") == 0){
		a-> set = JULIA;
		return ;
	}
	else if (ft_strcmp(str, "MANDELBROT") == 0){
		a-> set = MANDELBROT;
		return ;
	}
	printf("end of classify_set\n");
	// printf("a-> set %i \n", a-> set);
	ft_error();
	// exit(1);

}


void parse_args(t_fractol *a, char **argv){
	printf("in func parse_args\n");
	classify_set(a, argv);
	// julia_init();
}

void ft_error(){
	write(1, "error\n", 6);
	exit(1);
}


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

	a-> ratio = 1;

	a->color = 0;
    a->adr = NULL;
    a->bits_per_pixel = 0;

	a-> color_storage = NULL;
    // a->endian = 1073217536;
    a->line_length = 0;
	printf("fractal_init done\n");
    classify_set(a, argv);
    init_set();
    // set_color(a); //need colors
}


void	ft_mlx_init(t_fractol *f)
{
	printf("in func ft mlx init\n");
	f->mlx = mlx_init();
	if (!f->mlx){
		printf("error connecting to mlx");
		exit(1);
	}
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Fractol");
	if (!f->win){
		printf("error creating window");
	}
	complex_init(f);
	f-> m = mlx_new_image(f-> mlx, WIDTH, HEIGHT);
	f-> adr = mlx_get_data_addr(f-> m, &f-> bits_per_pixel, &f-> line_length, &f->endian);
	printf("gagagagaga\n");
	
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
	parse_args(&a, argv); //or julia init
	ft_mlx_init(&a);
	// printf("aaaaaaa\n");
	rerender(&a);
	// mlx = mlx_init();
	// mlx_put_image_to_window();

	mlx_hook(a.win, 2, 1L<<0, key_press, &a);
	mlx_hook(a.win, 4, 1L<<2, mouse_press, &a);
	mlx_hook(a.win, 17, 1L<<2, x_button, &a);
	mlx_expose_hook(a.win, rerender, &a);

	mlx_loop(a.mlx);
	return 0;
}