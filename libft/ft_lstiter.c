/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakasuj <anakasuj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 14:56:26 by anakasuj          #+#    #+#             */
/*   Updated: 2024/02/17 02:03:38 by anakasuj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*next;

	while (lst)
	{
		next = lst->next;
		f(lst->content);
		lst = next;
	}
}
