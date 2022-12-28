/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-ca <fdiaz-ca@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:02:12 by fdiaz-ca          #+#    #+#             */
/*   Updated: 2022/12/22 15:31:13 by fdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

/* It reads from keyboard until line is equal to "limitador" (argv[2]). It   */
/* sets up a temporary file to save lines.                                   */
static void	ft_heredoc(t_pipex *px, char **argv)
{
	int		fd;
	char	*str;
	char	*limit;

	px->is_here = 1;
	fd = open("tmp.here", O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (fd < 0)
		ft_error(px, "Can't open file: ", "tmp.here");
	limit = ft_strjoin(argv[2], "\n");
	str = get_next_line(0);
	while (str && ft_strncmp(limit, str, ft_strlen(limit)))
	{
		write(fd, str, ft_strlen(str));
		free(str);
		str = get_next_line(0);
	}
	close(fd);
	free(str);
	free(limit);
	px->fd_in = open("tmp.here", O_RDONLY);
	if (px->fd_in < 0)
		ft_error(px, "Can't open file: ", "tmp.here");
}

/* It sets up fds depending on command index: first, last or rest of them    */
static void	ft_set_fds(t_pipex *px)
{
	if (px->index == 0)
	{
		dup2(px->fd_in, STDIN_FILENO);
		dup2(px->fd_pipe[1], STDOUT_FILENO);
	}
	else if (px->index == px->n_cmds - 1)
	{
		dup2(px->fd_pipe[2 * px->index - 2], STDIN_FILENO);
		dup2(px->fd_out, STDOUT_FILENO);
	}
	else
	{
		dup2(px->fd_pipe[2 * px->index - 2], STDIN_FILENO);
		dup2(px->fd_pipe[2 * px->index + 1], STDOUT_FILENO);
	}
}

/* Extracts every path from environment, and tests each one of them. It      */
/* returns the valid one and clear the rest                                  */
static char	*ft_get_path(char *cmd, char **envp)
{
	char	**full_path;
	char	*path;
	int		i;

	while (*envp && ft_strncmp("PATH", *envp, 4) != 0)
		envp += 1;
	if (!*envp)
		return (NULL);
	*envp += 5;
	full_path = ft_split(*envp, ':');
	i = 0;
	while (full_path[i])
	{
		path = ft_strjoin(ft_strjoin(full_path[i], "/"), cmd);
		if (access(path, 0) == 0)
		{
			ft_free_grid(full_path);
			return (path);
		}
		free(path);
		i++;
	}
	ft_free_grid(full_path);
	return (NULL);
}

/* Initializes px structure and gives it back. Checks for enough arguments,  */
/* prepares fd_in depending if we are in a here_doc case or not.             */
t_pipex	ft_init_pipex(int argc, char **argv)
{
	t_pipex	px;

	px.fd_pipe = NULL;
	px.cmd_arg = NULL;
	px.path = NULL;
	px.n_cmds = 0;
	px.is_here = 0;
	if (argc < 5 || (argc < 6 && !ft_strncmp(argv[1], "here_doc", 9)))
		ft_error(&px, "Not enough number of arguments", NULL);
	if (!ft_strncmp(argv[1], "here_doc", 9))
		ft_heredoc(&px, argv);
	else
	{
		px.fd_in = open(argv[1], O_RDONLY);
		if (px.fd_in < 0)
			ft_error(&px, "Can't open file : ", argv[1]);
	}
	px.n_cmds = argc - 3 - px.is_here;
	px.fd_out = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (px.fd_out < 0)
		ft_error(&px, "Can't open file : ", argv[argc - 1]);
	px.fd_pipe = (int *)malloc(sizeof(int) * (2 * (px.n_cmds -1)));
	if (!px.fd_pipe)
		ft_error(&px, "Can't alloc memmory for : ", "fd_pipe");
	return (px);
}

/* It opens a parallel proccess, set fds necesaries, after that closes pipes */
/* and extracts command and path from passed arguments and environment       */
/* pointer. It checks if path is already in command declaration              */
/* (e.g.: /usr/bin/ls)). If there is no error, It executes command in path   */
void	ft_child(t_pipex *px, char **argv, char **envp)
{
	px->pid = fork();
	if (px->pid < 0)
		ft_error(px, "Can't open fork\n", NULL);
	if (px->pid == 0)
	{
		ft_set_fds(px);
		ft_close_pipes(px);
		px->cmd_arg = ft_split(argv[px->index + 2 + px->is_here], ' ');
		if (px->cmd_arg[0][0] == '/' && access(px->cmd_arg[0], 0) == 0)
			px->path = px->cmd_arg[0];
		else
			px->path = ft_get_path(px->cmd_arg[0], envp);
		if (execve(px->path, px->cmd_arg, envp) == -1)
			ft_error(px, "Not such command found: ", px->cmd_arg[0]);
	}
}
