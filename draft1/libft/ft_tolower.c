/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakasuj <anakasuj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:11:14 by anakasuj          #+#    #+#             */
/*   Updated: 2024/02/17 02:05:30 by anakasuj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_tolower(int ch)
{
	if (ch >= 'A' && ch <= 'Z')
		return (ch + 32);
	return (ch);
}

// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>

// int main() {

// char s[] = "Code_in_C_@0123";
// for(unsigned long i=0;i<strlen(s);i++)
// 	s[i]=tolower(s[i]);
// printf("%s \n", s);

// char s2[] = "Code_in_C_@0123";
// for(unsigned long i=0;i<strlen(s2);i++)
// 	s2[i]=tolower(s2[i]);
// printf("%s", s2);

// return (0);
// }
