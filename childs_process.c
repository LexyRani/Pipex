/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:59:09 by aceralin          #+#    #+#             */
/*   Updated: 2022/11/26 17:36:35 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}
void	ft_child1_process(t_pipex *pipex, char *argv[])
{
	char *path;
	
	if (dup2(pipex->pipe_fd[1], 1) == -1)
		ft_error(pipex, "child1_process 1");
	close(pipex->pipe_fd[0]);
	if (dup2(pipex->file1, 0) == -1)
		ft_error(pipex, "child1_process 2");
	pipex->cmd1 = ft_split(argv[2],' ');
	path = ft_check_PATH(pipex, 1);
	//write(2, "banana\n",7);
	execve(path, pipex->cmd1, pipex->env);
	perror("pipex");
	//ft_error(pipex, strerror(errno)); // verifier si erreur
	ft_free(pipex->cmd1);
	free(path);
	//else
		/*error*/
}

void	ft_child2_process(t_pipex *pipex, char *argv[])
{
	//printf("\n\n process2\n\n");
	if (dup2(pipex->pipe_fd[0], 0) == -1)
		ft_error(pipex, "child2 1"); 
	close(pipex->pipe_fd[1]);
	if (dup2(pipex->file2, 1) == -1)
		ft_error(pipex, "child2 2");
	pipex->cmd2 = ft_split(argv[3],' ');
	if (pipex->cmd2[0] && ft_check_PATH(pipex, 2))
	{
		if(execve(ft_check_PATH(pipex, 2) , pipex-> cmd2, pipex-> env) == -1)
			ft_error(pipex, "child2 3");
		ft_free(pipex->cmd2);
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