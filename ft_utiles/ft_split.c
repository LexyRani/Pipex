/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:58:12 by aceralin          #+#    #+#             */
/*   Updated: 2022/11/23 17:48:05 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_count_strs(const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s[i] != c && s[i] != '\0')
		i++;
	while (s[j] != '\0')
	{
		if (s[j] == c && s[j + 1] != c && s[j + 1] != '\0')
		{
			i++;
		}
		j++;
	}
	return (i);
}

static char	*word_extraction(const char *str, char c)
{
	int		i;
	char	*word;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (0);
	i = 0;
	while (str[i] && str[i] != c)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	**ft_split_free( char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static char	**ft_create_tab(char const *s, char c, int words)
{
	char	**tab;
	int		i;
	int		j;

	tab = (char **) malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			s++;
		if (s[i] && s[i] != c)
		{
			tab[j++] = word_extraction(s + i, c);
			if (tab[j - 1] == 0)
				return (ft_split_free(tab));
			i++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	tab[j] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	int		words;

	if (!s)
		return (0);
	words = ft_count_strs(s, c);
	return (ft_create_tab(s, c, words));
}
