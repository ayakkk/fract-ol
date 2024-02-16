/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakasuj <anakasuj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:10:11 by anakasuj          #+#    #+#             */
/*   Updated: 2023/05/30 19:28:23 by anakasuj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getlen_x(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
		return (11);
	if (n <= 0)
	{
		len += 1;
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	int		sign;
	char	*res;
	long	temp;

	sign = 1;
	if (n < 0)
		sign *= -1;
	len = getlen_x(n);
	res = (char *)malloc(sizeof(char) * (len) + 1);
	if (!res)
		return (NULL);
	res[len--] = 0;
	if (n < 0)
		temp = -(long)n;
	else
		temp = (long)n;
	while (len >= 0)
	{
		res[len--] = '0' + temp % 10;
		temp /= 10;
	}
	if (sign == -1)
		res[0] = '-';
	return (res);
}
