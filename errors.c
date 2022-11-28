/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:25:08 by aceralin          #+#    #+#             */
/*   Updated: 2022/11/28 14:34:19 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*retirer les fonctions inutiles*/
void	ft_exit(t_pipex *pipex)
{
	free(pipex);
	exit(EXIT_FAILURE);
}

void	ft_argc_error(t_pipex *pipex)
{
	write (2, "Invalid arg number\nEx:./pipex [file1][cmd1][cmd2][file2]\n", 58);
	free(pipex);
	exit(EXIT_FAILURE);
}

void	ft_env_error(t_pipex *pipex)
{
	write(2, "Missing Env\n", 13);
	free(pipex);
	exit(EXIT_FAILURE);
}

void	ft_path_error(t_pipex *pipex)
{
	write(2, "Missing PATH\n", 14);
	free(pipex);
	exit(EXIT_FAILURE);
}

void	ft_cmd_error(char *cmd, t_pipex *pipex)
{
	write(2, "command not found: ", 20);
	write(2, cmd, ft_strlen(cmd));
	write(2, "\n", 1);
	if (pipex->cmd2 && cmd == pipex->cmd2[0])
		ft_free(pipex->cmd2);
	if (pipex->cmd1 && cmd == pipex->cmd1[0])
		ft_free(pipex->cmd1);
	free(pipex);
	exit(EXIT_FAILURE);
}
