/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakasuj <anakasuj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:10:49 by anakasuj          #+#    #+#             */
/*   Updated: 2024/02/17 02:04:57 by anakasuj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	size;

	size = ft_strlen((char *)s);
	ptr = (char *)malloc(sizeof(char) * size + 1);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s, size);
	ptr[size] = '\0';
	return (ptr);
}

//The strdup() function returns a pointer to the duplicated string,
//or NULL if insufficient memory was available.

// #include<stdio.h>
// #include<string.h>

// int main()
// {
//     char source[] = "GeeksForGeeks";

//     // A copy of source is created dynamically
//     // and pointer to copy is returned.
//     char* target = strdup(source);

//     printf("%s \n ------- \n", target);

// 	char source2[] = "GeeksForGeeks";

//     // A copy of source is created dynamically
//     // and pointer to copy is returned.
//     char* target2 = ft_strdup(source2);

//     printf("%s\n", target2);
//     return (0);
// }