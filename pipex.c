/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:07:00 by aceralin          #+#    #+#             */
/*   Updated: 2022/11/20 22:44:23 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
void	ft_struct_init(t_pipex *pipex, char *argv[], char *envp[])
{
	pipex->file1 = open(argv[1], O_RDONLY);
	pipex->file2 = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644); // verifier les droits
	pipex->env = envp;
	pipex->cmd1 = NULL;
	pipex->cmd2 = NULL;
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
	ft_struct_init(pipex, argv, envp);
	
}