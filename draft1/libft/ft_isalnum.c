/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakasuj <anakasuj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:09:47 by anakasuj          #+#    #+#             */
/*   Updated: 2023/05/30 15:09:49 by anakasuj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) != 0 || ft_isdigit(c) != 0)
		return (1);
	return (0);
}

// #include <ctype.h>
// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
//     char d1 = '3';
// 	char d2 = 'A';
// 	char d3 = '+';
//     printf("ft_isalnum = %d\n", ft_isalnum(d1));
// 	printf("ft_isalnum = %d\n", ft_isalnum(d2));
// 	printf("ft_isalnum = %d\n", ft_isalnum(d3));

//     return (0);
// }