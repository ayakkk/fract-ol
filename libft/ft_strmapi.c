/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakasuj <anakasuj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:11:02 by anakasuj          #+#    #+#             */
/*   Updated: 2024/02/17 02:05:13 by anakasuj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	res = NULL;
	i = 0;
	if (s)
	{
		res = (char *)malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
		if (!res)
			return (NULL);
		while (s[i])
		{
			res[i] = f(i, s[i]);
			if (!res[i])
				return (NULL);
			i++;
		}
	}
	else
	{
		return (NULL);
	}
	res[i] = '\0';
	return (res);
}
