/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:09:09 by aceralin          #+#    #+#             */
/*   Updated: 2022/11/20 23:01:14 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#ifndef PATH
#define PATH PATH=/mnt/nfs/homes/aceralin/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:\
                                /usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin
#endif  

# include <sys/wait.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <time.h>
# include "./ft_printf/ft_printf.h"

/*structure*/
typedef struct s_pipex
{
	// pipe
	int	pipe_fd[2];
	//fd
	int	file1;
	int	file2;
	//pid
	int	pid_1;
	int_pid_2;

	// char	**cmd;???
	//cmd1 et cmd2
	char	**cmd1;
	char	**cmd2;
	//Path
	char	**paths;
	//env
	char	**env;
}				t_pipex;


/*Parsing*/

/*fonctions utiles*/

/*Main*/
void	ft_struct_init(t_pipex *pipex, char *argv[], char *envp[]);

/*Errors*/
void ft_exit (t_pipex *pipex);
void	ft_argc_error(t_pipex *pipex);

#endif