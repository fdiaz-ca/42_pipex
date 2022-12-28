/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-ca <fdiaz-ca@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:37:08 by fdiaz-ca          #+#    #+#             */
/*   Updated: 2022/12/09 16:34:32 by fdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* Receives a grid of chars and frees it                                      */
void	ft_free_grid(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i += 1;
	}
	free(str);
}

/* It frees px structure, closing pipes, and freeing path and cmd_arg,       */
/* if they were allocated.                                                   */
void	ft_free_pipex(t_pipex *pipex)
{
	if (pipex->path)
		free(pipex->path);
	if (pipex->cmd_arg)
		ft_free_grid(pipex->cmd_arg);
	close(pipex->fd[0]);
	close(pipex->fd[1]);
	close(pipex->fd_file);
}

/* If received, It prints an error message, and the cause of it. Then It     */
/* frees px structure, and exits with failure value                          */
int	ft_error(t_pipex *pipex, char *err_msg, char *with_this)
{
	write(2, "Error:\n", 7);
	if (err_msg)
		write(2, err_msg, ft_strlen(err_msg));
	if (with_this)
		write(2, with_this, ft_strlen(with_this));
	write(2, "\n", 1);
	ft_free_pipex(pipex);
	exit(EXIT_FAILURE);
}
