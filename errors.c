/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:25:08 by aceralin          #+#    #+#             */
/*   Updated: 2022/11/23 20:14:59 by aceralin         ###   ########.fr       */
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

void	ft_error_env(t_pipex *pipex)
{
	ft_printf("Missing Env\n");
	free(pipex);
	exit(EXIT_FAILURE);
}

void	ft_error_path(t_pipex *pipex)
{
	ft_printf("Missing Path");
	free(pipex);
	exit(EXIT_FAILURE);
}
void	ft_error_cmd(char **cmd,t_pipex *pipex) /*simplifier*/
{
	write(2, cmd[0], ft_strlen(cmd[0]));
	write(2, ":Command not found\n", 20);
	if((ft_strnstr(*cmd, "/", ft_strlen(*cmd))))
	{
		free(pipex);
		exit(EXIT_FAILURE);
	}
	ft_free(cmd);
	free(pipex);
	exit(EXIT_FAILURE);
}