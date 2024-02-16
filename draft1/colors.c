#include "fractol.h"

//set color if provided, 
//if not, default
void set_color(t_fractol *a){
	a->color = 0xD7E4FF;
}

void	my_mlx_pixel_put( t_fractol *a , int i, int j, int color)
{
	char	*dst;

	dst = a->adr + (i * a->line_length + j* (a->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


// check if character is a whitespace character
static int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r');
}

static int	skip_space_sign(char *str, int *is_neg)
{
	int	i;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*is_neg = -1;
		i++;
	}
	return (i);
}

// string to float
double	ft_atof(char *str)
{
	int		i;
	double	nb;
	int		is_neg;
	double	div;

	nb = 0;
	div = 0.1;
	is_neg = 1;
	i = skip_space_sign(str, &is_neg);
	while (str[i] && ft_isdigit(str[i]) && str[i] != '.')
	{
		nb = (nb * 10.0) + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		nb = nb + ((str[i] - '0') * div);
		div *= 0.1;
		i++;
	}
	if (str[i] && !ft_isdigit(str[i]))
		return (-1);
	return (nb * is_neg);
}