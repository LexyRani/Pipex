/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utiles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:01:41 by aceralin          #+#    #+#             */
/*   Updated: 2022/11/27 00:16:02 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free(char **tab)
{
	int i;

	i = 0;
	while(tab[i])
	{
		free(tab[i++]);
	}
	free(tab);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		len;
	int		j;

	if (s1 && s2)
	{
		i = 0;
		len = ft_strlen(s1) + ft_strlen(s2);
		str = malloc(sizeof(char) * (len + 1));
		if (!str)
			return (NULL);
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
		j = 0;
		while (s2[j])
			str[i++] = s2[j++];
		str[i] = '\0';
		return (str);
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	if (!big || !little)
		return (0);
	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < len && little[j] != '\0')
			j++;
		if (little[j] == '\0')
			return ((char *) big + i);
		i++;
	}
	return (0);
}
