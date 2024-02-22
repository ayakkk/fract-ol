#include "fractol.h"

void	init_color_storage(t_fractol *f) {
	f->color_storage[0] = 0xe6f547;
	f->color_storage[1] = 0x4362de;
	f->color_storage[2] = 0x76e895;
	f->color_storage[3] = 0x8fd6f2;
	f->color_storage[4] = 0xfca2c6;
}

void	my_mlx_pixel_put( t_fractol *a , int i, int j, int color)
{
	char	*dst;

	dst = a->adr + (i * a->line_length + j* (a->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
