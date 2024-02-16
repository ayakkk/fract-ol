/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakasuj <anakasuj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:09:53 by anakasuj          #+#    #+#             */
/*   Updated: 2023/05/30 15:09:54 by anakasuj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c <= 122 && c >= 97))
		return (1);
	return (0);
}

// #include <ctype.h>
// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
//     char str[] = "12abc12";
//     //char str[] = "1";

//     int alphabet = 0, number = 0, i;
//     for (i = 0; str[i] != '\0'; i++)
//     {
//         if (isalpha(str[i]) != 0)
//             alphabet++;
//     }

//     for (i = 0; str[i] != '\0'; i++)
//     {
//         if (ft_isalpha(str[i]) != 0)
//             number++;
//     }

//     printf("isalpha = %d, "
//            "ft_isalpha = %d\n",
//            alphabet, number);

//     return (0);
// }