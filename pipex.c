/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:07:00 by aceralin          #+#    #+#             */
/*   Updated: 2022/11/28 16:36:53 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_struct_init(t_pipex *pipex, char *argv[], char *envp[])
{
	pipex->file1 = open(argv[1], O_RDONLY);
	pipex->file2 = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0777);
	pipex->env = envp;
	pipex->cmd1 = NULL;
	pipex->cmd2 = NULL;
	pipex->paths = NULL;
}

int	ft_status(t_pipex *pipex)
{
	int	status;

	waitpid(pipex->pid1, &status, 0);
	waitpid(pipex->pid2, &status, 0);
	free(pipex);
	return (status);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	*pipex;

	pipex = (t_pipex *)malloc(sizeof(t_pipex));
	if (!pipex)
		ft_exit(pipex);
	if (argc != 5)
		ft_argc_error(pipex);
	if (pipe(pipex->pipe_fd) == -1)
		ft_error(pipex, "pipe");
	ft_struct_init(pipex, argv, envp);
	pipex->pid1 = fork();
	if (pipex->pid1 == -1)
		ft_error(pipex, "fork");
	if (pipex->pid1 == 0)
		ft_child1_process(pipex, argv);
	pipex->pid2 = fork();
	if (pipex->pid2 == -1)
		ft_error(pipex, "fork");
	if (pipex->pid2 == 0)
		ft_child2_process(pipex, argv);
	ft_pipes_close(pipex);
	ft_close_fds(pipex);
	return (ft_status(pipex));
}
