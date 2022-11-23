/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:03:18 by aceralin          #+#    #+#             */
/*   Updated: 2022/11/23 22:13:19 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    ft_close_fds(t_pipex *pipex)
{
    close(pipex->file1);
    close(pipex->file2);
}

void    ft_close_pipes(t_pipex *pipex)
{
    close(pipex->pipe_fd[0]);
    close(pipex->pipe_fd[1]);
}