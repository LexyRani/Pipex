/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:59:09 by aceralin          #+#    #+#             */
/*   Updated: 2022/11/28 17:11:39 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(t_pipex *pipex, char *error)
{
	perror(error);
	free(pipex);
	exit(EXIT_FAILURE);
}

void	ft_child1_process(t_pipex *pipex, char *argv[])
{
	char	*path1;

	if (pipex->file1 == -1)
		ft_error(pipex, argv[1]);
	if (dup2(pipex->pipe_fd[1], 1) == -1)
		ft_error(pipex, "[1] dup2");
	close(pipex->pipe_fd[0]);
	if (dup2(pipex->file1, 0) == -1)
		ft_error(pipex, "[1] dup2");
	pipex->cmd1 = ft_split(argv[2], ' ');
	path1 = ft_check_path(pipex, 1);
	execve(path1, pipex->cmd1, pipex->env);
	perror(path1);
	if (pipex->cmd1 && path1 != pipex->cmd1[0])
		free(path1);
	ft_free(pipex->cmd1);
	free(pipex);
	exit(EXIT_FAILURE);
}

void	ft_child2_process(t_pipex *pipex, char *argv[])
{
	char	*path2;

	if (pipex->file2 == -1)
		ft_error(pipex, argv[4]);
	if (dup2(pipex->pipe_fd[0], 0) == -1)
		ft_error(pipex, "[2] dup2");
	close(pipex->pipe_fd[1]);
	if (dup2(pipex->file2, 1) == -1)
		ft_error(pipex, "[2] dup2");
	pipex->cmd2 = ft_split(argv[3], ' ');
	path2 = ft_check_path(pipex, 2);
	execve(path2, pipex->cmd2, pipex->env);
	perror(path2);
	if (pipex->cmd2 && path2 != pipex->cmd2[0])
		free(path2);
	ft_free(pipex->cmd2);
	free(pipex);
	exit(EXIT_FAILURE);
}

void	ft_process_child(t_pipex *pipex, char *argv[])
{
	if (pipex->pid1)
		ft_child1_process(pipex, argv);
	if (pipex->pid2)
		ft_child2_process(pipex, argv);
}
