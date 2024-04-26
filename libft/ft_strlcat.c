/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakasuj <anakasuj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:10:55 by anakasuj          #+#    #+#             */
/*   Updated: 2024/02/17 02:05:05 by anakasuj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

// size_t	ft_strlen(char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i] != '\0')
// 		i++;
// 	return (i);
// }

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	n;
	size_t	d_len;
	size_t	s_len;

	if (size == 0)
		return (ft_strlen((char *)src));
	d_len = ft_strlen(dst);
	s_len = ft_strlen((char *)src);
	if (size <= d_len)
		return (size + s_len);
	n = size - d_len - 1;
	i = 0;
	while (i < n)
	{
		if (src[i] == '\0')
			break ;
		dst[d_len + i] = src[i];
		i++;
	}
	dst[d_len + i] = '\0';
	return (s_len + d_len);
}

//The strlcat() function appends the NUL-terminated string
//src to the end of dst. It will append at most size − strlen(dst) − 1 bytes,
//NUL-terminating the result.

// #include <stdio.h>
// #include <string.h>

// int main()
// {
//     // char first[] = "This is ";
//     // char last[] = "a potentially long string";
//     // int r;
//     // int size = 16;
//     // char buffer[size];

//     // strcpy(buffer,first);
//     // r = strlcat(buffer,last,size);

//     // puts(buffer);
//     // printf("Value returned: %d\n",r);
//     // if( r > size )
//     //     puts("String truncated");
//     // else
//     //     puts("String was fully copied");

//     // printf("\n --- \n");

//     // char first2[] = "This is ";
//     // char last2[] = "a potentially long string";
//     // int r2;
//     //  int size2 = 16;
//     // char buffer2[size2];

//     // strcpy(buffer2,first2);
//     // r2 = ft_strlcat(buffer2,last2,size2);

//     // puts(buffer2);
//     // printf("Value returned: %d\n",r2);

// 	// if( r2 > size2 )
//     //     puts("String truncated");
//     // else
//     //     puts("String was fully copied");

// 	char b[0xF] = "nyan !";

// 	int x = strlcat(((void *)0), b, 0);
// 	int y = ft_strlcat(((void *)0), b, 0);

// 	printf("%i %i ", x, y);

//     return(0);
// }