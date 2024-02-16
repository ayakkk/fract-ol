/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakasuj <anakasuj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:11:10 by anakasuj          #+#    #+#             */
/*   Updated: 2024/02/17 02:05:23 by anakasuj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	i = 0;
	j = ft_strlen((char *)s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (s1[j - 1] && ft_strchr(set, s1[j - 1]))
	{
		if (j - 1 < 1)
			break ;
		j--;
	}
	if (i > j)
		return (ft_strdup(""));
	ptr = (char *)malloc((sizeof(char) * j - i) + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1 + i, j - i + 1);
	return (ptr);
}
