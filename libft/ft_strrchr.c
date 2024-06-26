/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakasuj <anakasuj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:11:08 by anakasuj          #+#    #+#             */
/*   Updated: 2024/02/17 02:05:20 by anakasuj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	char	*str;
	char	*last;

	ch = c;
	str = (char *)s;
	last = NULL;
	if (ch == '\0')
		return (&str[ft_strlen(str)]);
	while (*s)
	{
		if (*s == ch)
			last = (char *)s;
		s++;
	}
	return (last);
}
