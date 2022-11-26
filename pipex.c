/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:07:00 by aceralin          #+#    #+#             */
/*   Updated: 2022/11/27 00:17:01 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


void	ft_struct_init(t_pipex *pipex, char *argv[], char *envp[])
{
	if((pipex->file1 = open(argv[1], O_RDONLY)) == -1)
		ft_error(pipex, "pipex");
	if((pipex->file2 = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0777)) == -1)
		ft_error(pipex, "pipex"); 	
	pipex->env = envp;
	pipex->cmd1 = NULL;
	pipex->cmd2 = NULL;
	pipex->paths = NULL; 
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex *pipex;
	
	pipex =(t_pipex *)malloc(sizeof(t_pipex));
	if(!pipex)
		ft_exit(pipex);
	if (argc != 5)
		ft_argc_error(pipex);
	if (pipe(pipex->pipe_fd) == -1)
		ft_error(pipex, strerror(errno)); 
	ft_struct_init(pipex, argv, envp);
	pipex->pid1 = fork();
	if(pipex->pid1 == 0)
		ft_child1_process(pipex, argv);
	pipex->pid2 = fork();
	if(pipex->pid2 == 0)
		ft_child2_process(pipex,argv);
	ft_pipes_close(pipex);
	ft_close_fds(pipex);
	waitpid(pipex->pid1, NULL, 0);
	waitpid(pipex->pid2, NULL, 0);
	free(pipex);
	return(0);
}
