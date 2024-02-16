/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakasuj <anakasuj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:10:32 by anakasuj          #+#    #+#             */
/*   Updated: 2023/05/30 19:07:51 by anakasuj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*b1;
	char	*b2;

	b1 = (char *)dst;
	b2 = (char *)src;
	if (!dst && !src)
		return (dst);
	if (src < dst)
		while (len--)
			b1[len] = b2[len];
	else
	{
		while (len--)
		{
			*b1 = *b2;
			b1++;
			b2++;
		}
	}
	return (dst);
}
