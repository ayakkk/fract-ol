/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakasuj <anakasuj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:10:35 by anakasuj          #+#    #+#             */
/*   Updated: 2024/02/17 02:04:25 by anakasuj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memset(void *buf, int ch, size_t len)
{
	unsigned char	*b;

	b = buf;
	while (len > 0)
	{
		*b = (unsigned char)ch;
		b++;
		len--;
	}
	return (buf);
}

// #include        <stdio.h>
// #include        <string.h>

// int main(void)
// {
//         char str[] = "0123456789";
// 		char str2[] = "0123456789";

//         char * str3 = NULL;
//         char * str4 = NULL;

//         // memset(str3, '*', 5);
//         // printf("%s\n",str3);

// 		ft_memset(str4, '*', 5);
//         printf("%s\n",str4);

//         return (0);
// }