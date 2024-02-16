/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakasuj <anakasuj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:16:29 by anakasuj          #+#    #+#             */
/*   Updated: 2024/02/17 02:04:53 by anakasuj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	word_count(char const *s, char c)
{
	int	count;
	int	in_substring;

	count = 0;
	in_substring = 0;
	while (*s != '\0')
	{
		if (*s == c)
			in_substring = 0;
		else if (in_substring == 0)
		{
			in_substring = 1;
			count++;
		}
		s++;
	}
	return (count);
}

char	*get_word(const char *str, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && str[i] != c)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

void	free_split(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**tab;
	int		i;

	i = 0;
	words = word_count(s, c);
	tab = (char **)malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	while (words--)
	{
		while (*s == c && *s)
		s++;
		tab[i] = get_word(s, c);
		if (tab[i] == NULL)
		{
			free_split(tab);
			return (NULL);
		}
		s += ft_strlen(tab[i++]);
	}
	tab[i] = NULL;
	return (tab);
}
