/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-ca <fdiaz-ca@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:12:44 by fdiaz-ca          #+#    #+#             */
/*   Updated: 2022/12/22 15:30:26 by fdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "libft.h"
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct s_pipex
{
	pid_t	pid;
	int		n_cmds;
	int		index;
	int		*fd_pipe;
	int		fd_in;
	int		fd_out;
	int		is_here;
	char	*path;
	char	**cmd_arg;
}				t_pipex;

void	ft_error(t_pipex *px, char *err_msg, char *with_this);
void	ft_free_grid(char **str);
void	ft_close_pipes(t_pipex *px);
t_pipex	ft_init_pipex(int argc, char **argv);
void	ft_child(t_pipex *px, char **argv, char **envp);

#endif