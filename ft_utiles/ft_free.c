/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:31:43 by aceralin          #+#    #+#             */
/*   Updated: 2022/11/23 17:46:44 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

void	ft_free(char **tab)
{
	int i;
	int size;

	i = 0;
	size = 0;
	while(tab[size])
		i++;
	while((i<size))
	{
		free(tab[i++]);
	}
	free(tab);
}