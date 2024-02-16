/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakasuj <anakasuj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:11:06 by anakasuj          #+#    #+#             */
/*   Updated: 2024/02/17 02:05:18 by anakasuj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*ptr;
	size_t	n_len;

	ptr = (char *)haystack;
	n_len = ft_strlen((char *)needle);
	if (!*needle)
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	while (*ptr && len >= n_len)
	{
		if (ft_strncmp(ptr, needle, n_len) == 0)
			return (ptr);
		ptr++;
		len--;
	}
	return (NULL);
}
