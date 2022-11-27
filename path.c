/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:25:32 by aceralin          #+#    #+#             */
/*   Updated: 2022/11/27 13:32:57 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_found_cmdpath(t_pipex *pipex)
{
	int	i;

	i = 0;
	if (!pipex->env[0])
		ft_env_error(pipex);
	else
	{
		while (!ft_strnstr(pipex->env[i], "PATH", 4))
			i++;
	}
	if (ft_strnstr(pipex->env[i], "PATH", 4) == NULL)
		ft_path_error(pipex);
	pipex->paths = ft_split(pipex->env[i] + 5, ':');
}

int	ft_cmd_is_pathname(t_pipex *pipex)
{
	if (ft_strnstr(pipex->cmd, "/", (ft_strlen(pipex->cmd))))
	{
		if (access(pipex->cmd, F_OK) == 0)
			return (1);
	//	else
	//		ft_cmd_error(&pipex->cmd, pipex);
	}
	return (0);
}

void	ft_check_cmd(t_pipex *pipex, int index)
{
	if (index == 1)
		pipex->cmd = pipex->cmd1[0];
	else
		pipex->cmd = pipex->cmd2[0];
}

char	*ft_check_path(t_pipex *pipex, int index)
{
	int		i;
	char	*path;
	char	*add_slash;

	ft_check_cmd(pipex, index);
	if (ft_cmd_is_pathname(pipex))
		return (pipex->cmd);
	ft_found_cmdpath(pipex);
	i = -1;
	while (pipex->paths[++i])
	{
		add_slash = ft_strjoin(pipex->paths[i], "/");
		path = ft_strjoin(add_slash, pipex->cmd);
		free(add_slash);
		if (access(path, F_OK | X_OK) == 0) // message au cas ou il n y a pas d access
		{
			ft_free(pipex->paths);
			return (path);
		}
		free(path);
	}
	ft_free(pipex->paths);
	ft_cmd_error(pipex->cmd, pipex);
	return (0);
}
