/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakasuj <anakasuj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:11:04 by anakasuj          #+#    #+#             */
/*   Updated: 2023/05/30 15:11:05 by anakasuj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		else if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
		n--;
	}
	return (0);
}

// if Return value < 0 then it indicates str1 is less than str2.
// if Return value > 0 then it indicates str2 is less than str1.
// if Return value = 0 then it indicates str1 is equal to str2.

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
    char str[] = "ABC";
    printf("ABC: ABD   = %d\n", strncmp(str, "ABD", 2));
    printf("ABC: ABC   = %d\n", strncmp(str, "ABC", 2));
    printf("ABC: AAA   = %d\n", strncmp(str, "AAA", 2));
    printf("ABC: ABCD  = %d\n", strncmp(str, "ABCD", 2));
    printf("ABC: AB    = %d\n", strncmp(str, "AB", 2));
    printf("ABC: B     = %d\n", strncmp(str, "B", 2));
    printf("ABC: A     = %d\n", strncmp(str, "A", 2));

	printf("\n -------- \n");

	char str2[] = "ABC";
    printf("ABC: ABD   = %d\n", strncmp(str2, "ABD", 2));
    printf("ABC: ABC   = %d\n", strncmp(str2, "ABC", 2));
    printf("ABC: AAA   = %d\n", strncmp(str2, "AAA", 2));
    printf("ABC: ABCD  = %d\n", strncmp(str2, "ABCD", 2));
    printf("ABC: AB    = %d\n", strncmp(str2, "AB", 2));
    printf("ABC: B     = %d\n", strncmp(str2, "B", 2));
    printf("ABC: A     = %d\n", strncmp(str2, "A", 2));


    return (0);
} */