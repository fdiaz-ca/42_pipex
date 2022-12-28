/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-ca <fdiaz-ca@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:12:17 by fdiaz-ca          #+#    #+#             */
/*   Updated: 2022/12/22 15:31:49 by fdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
/* Closes all pipes in px structure                                          */
void	ft_close_pipes(t_pipex *px)
{
	int	i;

	i = 0;
	while (i < (2 * (px->n_cmds - 1)))
	{
		close(px->fd_pipe[i]);
		i++;
	}
	if (px->pid != 0)
		free(px->fd_pipe);
	close(px->fd_in);
	close(px->fd_out);
}

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

/* It frees px structure, closing pipes, deleting tmp.here if we are in      */
/* here_doc case, and freeing path and cmd_arg, if they were allocated.      */
static void	ft_free_pipex(t_pipex *px)
{
	if (px->path)
		free(px->path);
	if (px->cmd_arg)
		ft_free_grid(px->cmd_arg);
	if (px->fd_pipe)
		ft_close_pipes(px);
	if (px->is_here)
		unlink("tmp.here");
}

/* If received, It prints an error message, and the cause of it. Then It     */
/* frees px structure, and exits with failure value                          */
void	ft_error(t_pipex *px, char *err_msg, char *with_this)
{
	write(2, "Error:\n", 7);
	if (err_msg)
		write(2, err_msg, ft_strlen(err_msg));
	if (with_this)
		write(2, with_this, ft_strlen(with_this));
	write(2, "\n", 1);
	ft_free_pipex(px);
	exit(EXIT_FAILURE);
}

/* This program copies the behaviour of pipe " | ". First initializes px     */
/* attending if we are in here_doc case and/or multiples commands case. It   */
/* calls ft_child as many times as commands are. Frees px structure at end   */
int	main(int argc, char **argv, char **envp)
{
	t_pipex	px;
	int		i;

	px = ft_init_pipex(argc, argv);
	px.index = 0;
	i = 0;
	while (i < px.n_cmds - 1)
	{
		if (pipe(px.fd_pipe + (2 * i)) < 0)
			ft_error(&px, "Can't init pipe\n", NULL);
		i++;
	}
	while (px.index < px.n_cmds)
	{
		ft_child(&px, argv, envp);
		px.index += 1;
	}
	ft_free_pipex(&px);
	waitpid(px.pid, NULL, 0);
	return (0);
}
