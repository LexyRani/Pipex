/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:25:32 by aceralin          #+#    #+#             */
/*   Updated: 2022/11/21 18:38:27 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_cmd_is_pathname(t_pipex *pipex)
{
	if (ft_strnstr(pipex->cmd, "/",ft_strlen(pipex->cmd)))
	{
		if (access(pipex->cmd,F_OK)== 0)
			return(1);
		else
		/*error*/ {}
	}
	return (0);
}

void	ft_check_cmd(t_pipex *pipex, int index)
{
	if (index == 1)
		pipex->cmd = pipex-> cmd1[0];
	else
		pipex->cmd = pipex-> cmd2[0];
		
}

void	*ft_check_PATH(t_pipex *pipex, int index)
{
	ft_check_cmd(pipex, index);
	if(ft_cmd_is_pathname(pipex));
		return(pipex->cmd);
	ft_found_cmd(pipex);
	/*ok*/ //check quel commande c est et la stocker dans une variable cmd
	/*ok*/ // si cmd=pathname on verifie les acces? access(cmd, F_OK) verrif errno?
	/*ok*/ // si ok? on renvoie direct la commande  a faire excecuter par execve
	// sinon si cmd != de Pathname, on va chercher ou la cmd se trouve

}
