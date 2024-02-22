/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakasuj <anakasuj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:09:42 by anakasuj          #+#    #+#             */
/*   Updated: 2024/02/17 02:01:59 by anakasuj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_bzero(void *a, size_t len)
{
	ft_memset(a, 0, len);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
//     char str[50] = "GeeksForGeeks is for programming geeks.";
//     char str2[50] = "GeeksForGeeks is for programming geeks.";
//     printf("\nBefore memset(): %s\n", str);

//     // Fill 8 characters starting from str[13] with '.'
//     //memset(str + 13, '.', 8*sizeof(char));
//     //ft_memset(str2 + 13, '.', 8*sizeof(char));

//     bzero(str + 13, 8*sizeof(char) );
//     ft_bzero(str2 + 13, 8*sizeof(char));

//     printf("After bzero():  %s \n", str);
//     printf("After ft_bzero():  %s", str2);
//     return (0);
// }
