/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:09:09 by aceralin          #+#    #+#             */
/*   Updated: 2022/11/21 18:36:17 by aceralin         ###   ########.fr       */
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

typedef struct s_pipex
{
	int	pipefd[2];
	//fd
	int	file1;
	int	file2;
	
	int	pid1;
	int	pid2;
	char	**cmd;
	char	**cmd1;
	char	**cmd2;
	//Path
	char	**paths;
	//env
	char	**env;
}				t_pipex;

/*Main*/
void	ft_struct_init(t_pipex *pipex, char *argv[], char *envp[]);
void	ft_childs(t_pipex *pipex, char *argv[]);

/*childs_process*/
void	ft_process_child(t_pipex *pipex,char *argv[]);
void	ft_child1_process(t_pipex *pipex, char *argv[]);
void	ft_child2_process(t_pipex *pipex, char *argv[]);

/* utiles*/
char	**ft_split(char const *s, char c);
char	*ft_strnstr(const char *big, const char *little, size_t len);

/*Command_Path*/

int		ft_cmd_is_pathname(t_pipex *pipex);
void	ft_check_cmd(t_pipex *pipex, int index);
void	*ft_check_PATH(t_pipex *pipex, int index);

/*Parsing*/

/*Errors*/
void	ft_exit (t_pipex *pipex);
void	ft_argc_error(t_pipex *pipex);

#endif