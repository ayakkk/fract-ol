/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakasuj <anakasuj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:10:30 by anakasuj          #+#    #+#             */
/*   Updated: 2023/05/30 15:10:31 by anakasuj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *buf1, const void *buf2, size_t n)
{
	char			*b1;
	char			*b2;
	unsigned long	i;

	b1 = (char *)buf2;
	b2 = (char *)buf1;
	i = 0;
	if (buf1 == NULL && buf2 == NULL)
		return (NULL);
	while (n > i)
	{
		b2[i] = b1[i];
		i++;
	}
	return ((char *)buf1);
}

// #include <stdio.h>
// int main ()
// {
//   char str1[] = "Geeks";
//   char str2[] = "Quiz";

//   puts("str1 before memcpy ");
//   puts(str1);

//   /* Copies contents of str2 to str1 */
//   memcpy(str1, str2, sizeof(str2));

//   puts("\nstr1 after memcpy ");
//   puts(str1);

//   puts("\n");

//   //
//   char str3[] = "Geeks";
//   char str4[] = "Quiz";

//   puts("str3 before ft_memcpy ");
//   puts(str3);

//   ft_memcpy(str3, str4, sizeof(str4));

//   puts("\nstr3 after ft_memcpy ");
//   puts(str3);

//   return (0);
// }