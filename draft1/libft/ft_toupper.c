/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakasuj <anakasuj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:11:16 by anakasuj          #+#    #+#             */
/*   Updated: 2024/02/17 02:05:40 by anakasuj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_toupper(int ch)
{
	if (ch >= 'a' && ch <= 'z')
		return (ch - 32);
	return (ch);
}

// #include <ctype.h>
// #include <stdio.h>

// int main()
// {
//     char ch;

//     ch = 'g';
//     printf("%c in uppercase is represented as  %c \n",
//            ch, toupper(ch));

//     char ch2;

//     ch2 = 'g';
//     printf("%c in uppercase is represented as  %c",
//            ch2, toupper(ch2));

//     return (0);
// }