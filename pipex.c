/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:07:00 by aceralin          #+#    #+#             */
/*   Updated: 2022/11/21 15:57:02 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void ft_childs(t_pipex *pipex, char *argv[])
{
	if((pipex->pid1) == -1)
		ft_error(pipex->pid1, strerror(errno));
	if(pipex->pid1 == 0)
		ft_process_child(pipex, argv);
	if((pipex->pid2) == -1)
		ft_error(pipex->pid1, strerror(errno));
	if((pipex->pid1) == 0)
		ft_process_child(pipex, argv);
}

void	ft_struct_init(t_pipex *pipex, char *argv[], char *envp[])
{
	pipex->file1 = open(argv[1], O_RDONLY);
	pipex->file2 = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644); // verifier les droits
	pipex->env = envp;
	pipex->cmd1 = NULL;
	pipex->cmd2 = NULL;
	pipex->pid1 = NULL;//verif
	pipex->pid2 = NULL;//verif
	pipex->paths = NULL; //verif
}

int	main(int argc, char *argv[], char envp[])
{
	t_pipex *pipex;
	
	pipex =(t_pipex *)malloc(sizeof(t_pipex));
	if(!pipex)
		ft_exit(pipex);
	if (argc != 5)
		ft_argc_error(pipex);
	if (pipe(pipex -> pipefd[2]) == -1)
		ft_error(pipex, strerror(errno)); // a tester verifier si il faut specifier le pipefd ou juste etcrire le nom de la structure
	ft_struct_init(pipex, argv, envp);
	pipex->pid1 = fork();
	ft_childs(pipex, argv);
	pipex->pid2 = fork();
	ft_childs(pipex,argv);
	
}
