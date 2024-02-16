/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakasuj <anakasuj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:09:57 by anakasuj          #+#    #+#             */
/*   Updated: 2023/05/30 15:09:58 by anakasuj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c == 2147483647 || c == -2147483648)
		return (0);
	else if (c > 127 || c < 0)
		return (0);
	return (1);
}

// The isascii() function tests for an ASCII character, which is any
//character between 0 and octal 0177 inclusive.

// #include <ctype.h>
// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
//     char d = '+';
// 	printf("isdigit = %d\n", isdigit(d));
//     printf("ft_isdigit = %d\n", ft_isdigit(d));

//     return (0);
// }
