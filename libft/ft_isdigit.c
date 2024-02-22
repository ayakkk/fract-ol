/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakasuj <anakasuj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:10:01 by anakasuj          #+#    #+#             */
/*   Updated: 2024/02/17 02:03:10 by anakasuj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

// #include <ctype.h>
// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
//     char d = '+';
//     printf("ft_isdigit = %d\n", ft_isdigit(d));

//     return (0);
// }