/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-ca <fdiaz-ca@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 18:08:21 by fdiaz-ca          #+#    #+#             */
/*   Updated: 2022/12/09 17:08:53 by fdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		fd[2];
	int		fd_file;
	char	*path;
	char	**cmd_arg;
}				t_pipex;

int		ft_error(t_pipex *pipex, char *err_msg, char *with_this);
void	ft_free_pipex(t_pipex *pipex);
void	ft_free_grid(char **str);

#endif