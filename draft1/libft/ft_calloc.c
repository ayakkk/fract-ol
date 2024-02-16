/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakasuj <anakasuj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:51:40 by anakasuj          #+#    #+#             */
/*   Updated: 2023/05/30 18:53:18 by anakasuj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	nsize;
	void	*ptr;

	if (count == 0 && size == 0)
	{
		count = size;
		size = 1;
	}
	nsize = 0;
	if (size && count > SIZE_MAX / size)
	{
		return (NULL);
	}
	nsize = count * size;
	ptr = malloc(nsize);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, nsize);
	return (ptr);
}
