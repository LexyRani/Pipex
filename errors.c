/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:25:08 by aceralin          #+#    #+#             */
/*   Updated: 2022/11/21 13:21:04 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void ft_exit (t_pipex *pipex)
{
	free(pipex);
	exit(EXIT_FAILURE);
}
void	ft_argc_error(t_pipex *pipex)
{
	ft_printf("Missing or too many arguments\nEx: ./pipex [file1][cmd1][cmd2][file2]\n");
	free(pipex);
	exit(EXIT_FAILURE);
}

// A tester
void	ft_error(t_pipex *pipex, char *error)
{
	perror(error);
	free(pipex);
	exit(EXIT_FAILURE);
}