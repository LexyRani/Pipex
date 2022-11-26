/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:07:00 by aceralin          #+#    #+#             */
/*   Updated: 2022/11/26 17:35:23 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*void ft_childs(t_pipex *pipex, char *argv[])
{
	if((pipex->pid1) == -1)
		ft_error(pipex, strerror(errno));
	if(pipex->pid1 == 0)
		ft_process_child(pipex, argv);
	if((pipex->pid2) == -1)
		ft_error(pipex, strerror(errno));
	if((pipex->pid1) == 0)
		ft_process_child(pipex, argv);
}*/

void	ft_struct_init(t_pipex *pipex, char *argv[], char *envp[])
{
	pipex->file1 = open(argv[1], O_RDONLY);
	pipex->file2 = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0777); // verifier les droits
	pipex->env = envp;
	// pipex->pid1 =-2;
	// pipex->pid2 =-2;
	pipex->cmd1 = NULL;
	pipex->cmd2 = NULL;
	pipex->paths = NULL; 
	/* if(pipex-> file1 == -1)
		//erreur
	if(pipex-> file1 == -1)	
		//erreur*/
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
	//printf("\n\n ici\n\n");
	pipex->pid1 = fork();
	if(pipex->pid1 == 0)
		ft_child1_process(pipex, argv);
	//printf("\n\n la \n\n");
	 //sleep(2000);
	pipex->pid2 = fork();
	if(pipex->pid2 == 0)
		ft_child2_process(pipex,argv);
	//printf("\n\n ici :)) \n\n");
	ft_pipes_close(pipex);
	ft_close_fds(pipex);
	waitpid(pipex->pid1, NULL, 0);
	waitpid(pipex->pid2, NULL, 0);
	free(pipex);
	return(0);
}
