

#include "fractol.h"
#include <stdbool.h>

static bool	_is_error(const char *str)
{
	int		dot_count;
	size_t	i;

	if (ft_strlen((char *)str) == 1 && !ft_isdigit(str[0]))
		return (true);
	if (str[0] != '\0' && str[1] != '\0'
		&& !ft_isdigit(str[0]) && str[0] != '+' && str[0] != '-'
		&& !ft_isdigit(str[1]))
		return (true);
	dot_count = 0;
	i = 1;
	while (str[i] != '\0')
	{
		if (str[i] == '.')
			dot_count++;
		if (dot_count > 1)
			return (true);
		if (!ft_isdigit(str[i]) && str[i] != '.')
			return (true);
		i++;
	}
	return (false);
}

static bool	_is_max_num(
	const char *str,
	const double max_num)
{
	double	num;
	double	digit;
	size_t	i;

	num = 0.0;
	i = 0;
	while (str[i] != '\0'
		&& (str[i] == '+' || str[i] == '-'))
		i++;
	while (str[i] != '\0' && str[i] != '.')
	{
		digit = str[i] - '0';
		num = num * 10 + digit;
		if (num > max_num)
			return (true);
		i++;
	}
	return (false);
}

static double	_set_conversion_num(
	char c,
	double *conversion_num,
	double *fraction,
	bool *is_comma)
{
	int		digit;

	if (c == '.')
		*is_comma = true;
	else
	{
		digit = c - '0';
		if (*is_comma)
		{
			*conversion_num += digit * *fraction;
			*fraction /= 10;
		}
		else
			*conversion_num = *conversion_num * 10 + digit;
	}
	return (*conversion_num);
}

static double	_convert(const char *str, const bool is_positive)
{
	double	conversion_num;
	double	fraction;
	bool	is_comma;
	size_t	i;

	conversion_num = 0;
	fraction = 0.1;
	is_comma = false;
	i = 0;
	while (str[i] != '\0'
		&& (str[i] == '+' || str[i] == '-'))
		i++;
	while (str[i] != '\0')
	{
		_set_conversion_num(str[i], &conversion_num, &fraction, &is_comma);
		i++;
	}
	if (!is_positive)
		conversion_num *= -1;
	return (conversion_num);
}

double	ft_atof(const char *str)
{
	bool	is_positive;

	if (str == NULL
		|| _is_error(str))
		return (0);
	is_positive = true;
	if (str[0] == '-')
		is_positive = false;
	if (_is_max_num(str, 1000))
		return (0);
	return (_convert(str, is_positive));
}

// #include <stdio.h>
// int main()
// {
// 	printf("a = %lf\n", ft_atof("0.1"));
// 	printf("b = %lf\n", ft_atof("0.003451"));
// 	printf("c = %lf\n", ft_atof("-0.34561"));
// 	printf("c = %lf\n", ft_atof("-0.345afa1"));
// 	printf("c = %lf\n", ft_atof("-130.34561"));
// 	printf("c = %lf\n", ft_atof("-af0.34561"));
// }