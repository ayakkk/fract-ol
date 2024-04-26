/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakasuj <anakasuj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:10:47 by anakasuj          #+#    #+#             */
/*   Updated: 2024/02/17 02:04:56 by anakasuj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	char	ch;
	char	*str;

	ch = c;
	str = (char *)s;
	if (ch == '\0')
		return (&str[ft_strlen(str)]);
	while (*s)
	{
		if (*s == ch)
			return ((char *)(s));
		s++;
	}
	return (NULL);
}

//This returns a pointer to the first occurrence of the
//character c in the string str, or NULL if the character is not found.

// #include <string.h>

// int main(void)

// {
//     char test[20] = "abcdefghijk";
// 	char test2[20] = "abcdefghijk";

//     char *p;
// 	char *p2;

// 	p = strchr(test,0);
// 	p2 = ft_strchr(test2,0);
//     printf("検索文字が見つかった場所から表示: %s\n",p);
// 	printf("検索文字が見つかった場所から表示: %s\n",p2);

//     return (0);

// }
