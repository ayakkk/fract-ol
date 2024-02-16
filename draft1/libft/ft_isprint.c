/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakasuj <anakasuj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:10:05 by anakasuj          #+#    #+#             */
/*   Updated: 2024/02/17 02:03:18 by anakasuj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// int ft_isprint(int c){
// 	while (c > 255)
// 		c -= 255;
// 	if ( c >=  0 && c <= 31)
// 		return (0);
// 	else if ( c == 127)
// 		return (0);
// 	return (1);
// }

#include "../include/libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

//  int ft_isprint(int c){
// 		if (ft_isalnum(c) || ft_isalpha(c))
// 			return (1);
// 	if (c > 31 && 126 < c)
// 		return (1);
// 	return (0);
// }

// #include <ctype.h>
// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
//     char d1 = '3';
// 	char d2 = 'A';
// 	char d3 = '\n';
//     printf("ft_isprint = %d\n", ft_isprint(d1));
// 	printf("ft_isprint = %d\n", ft_isprint(d2));
// 	printf("ft_isprint = %d\n", ft_isprint(d3));

//     return (0);
// }