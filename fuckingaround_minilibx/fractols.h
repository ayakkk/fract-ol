#IFNDEF FRACTOLS_H
#DEFINE FRACTOLS_H

# ifndef FRACTOL_SIZE
#  define FRACTOL_SIZE 42
# endif

#include <math.h>
#include <mlx.h>
#include "libft/libft.h"
#include <stdio.h>
#include <stddef.h>

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}			t_vars;

typedef struct s_fractal
{
    void *mlx;           // Pointer to the mlx instance
    void *window;        // Pointer to the window
    void *image;         // Pointer to the image
    int *data;           // Pointer to image data
    int bpp;             // Bits per pixel
    int size_line;       // Size of each image line in bytes
    int endian;          // Endianness
    int x;               // Current x-coordinate during fractal calculation
    int y;               // Current y-coordinate during fractal calculation
    // Add any other members you need for your fractal here
} t_fractal;


#ENDIF