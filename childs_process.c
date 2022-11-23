/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:59:09 by aceralin          #+#    #+#             */
/*   Updated: 2022/11/23 21:48:15 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child1_process(t_pipex *pipex, char *argv[])
{
	if (dup2(pipex->pipe_fd[1], 1) == -1)
		ft_error(pipex, strerror(errno)); 
	close(pipex->pipe_fd[0]);
	if (dup2(pipex->file1, 0) == -1)
		ft_error(pipex, strerror(errno));
	pipex->cmd1 = ft_split(argv[2],' ');
	if (pipex->cmd1[0] && ft_check_PATH(pipex, 1))
	{
		if(execve(ft_check_PATH(pipex, 1) , pipex-> cmd1, pipex-> env) == -1)
			ft_error(pipex, strerror(errno)); // verifier si erreur
		ft_free (pipex ->cmd1);
	}
	//else
		/*error*/
}

void	ft_child2_process(t_pipex *pipex, char *argv[])
{
	if (dup2(pipex->pipe_fd[0], 0) == -1)
		ft_error(pipex, strerror(errno)); 
	close(pipex->pipe_fd[1]);
	if (dup2(pipex->file1, 1) == -1)
		ft_error(pipex, strerror(errno));
	pipex->cmd1 = ft_split(argv[3],' ');
	if (pipex->cmd1[0] && ft_check_PATH(pipex, 2))
	{
		if(execve(ft_check_PATH(pipex, 2) , pipex-> cmd1, pipex-> env) == -1)
			ft_error(pipex, strerror(errno));
		// free cmd2	
	}
	//else
		/*error*/
}

void	ft_process_child(t_pipex *pipex,char *argv[])
{
	if (pipex->pid1)
		ft_child1_process(pipex, argv);
	if (pipex->pid2)
		ft_child2_process(pipex, argv);
}