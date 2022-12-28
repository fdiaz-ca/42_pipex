/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-ca <fdiaz-ca@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:16:05 by fdiaz-ca          #+#    #+#             */
/*   Updated: 2022/12/09 17:07:36 by fdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

/* Prepares fds for first command. Extracts command and path from arguments, */
/* and close fds. It checks if path is already in command declaration        */
/* (e.g.: /usr/bin/ls)). If there is no error, It executes command in path   */
static void	ft_child_one(t_pipex *pipex, char **argv, char **envp)
{
	close(pipex->fd[0]);
	pipex->fd_file = open(argv[1], O_RDONLY);
	if (pipex->fd_file < 0)
		ft_error(pipex, "Can't open file: ", argv[1]);
	dup2(pipex->fd_file, STDIN_FILENO);
	close(pipex->fd_file);
	dup2(pipex->fd[1], STDOUT_FILENO);
	close(pipex->fd[1]);
	pipex->cmd_arg = ft_split(argv[2], ' ');
	if (pipex->cmd_arg[0][0] == '/' && access(pipex->cmd_arg[0], 0) == 0)
		pipex->path = pipex->cmd_arg[0];
	else
		pipex->path = ft_get_path(pipex->cmd_arg[0], envp);
	if (execve(pipex->path, pipex->cmd_arg, envp) == -1)
		ft_error(pipex, "Not such command found: ", pipex->cmd_arg[0]);
}

/* Prepares fds for second command. Extracts command and path from arguments, */
/* and close fds. It checks if path is already in command declaration        */
/* (e.g.: /usr/bin/ls)). If there is no error, It executes command in path   */
static void	ft_child_two(t_pipex *pipex, char **argv, char **envp)
{
	close(pipex->fd[1]);
	pipex->fd_file = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (pipex->fd_file < 0)
		ft_error(pipex, "Can't open file: ", argv[4]);
	dup2(pipex->fd_file, STDOUT_FILENO);
	close(pipex->fd_file);
	dup2(pipex->fd[0], STDIN_FILENO);
	close(pipex->fd[0]);
	pipex->cmd_arg = ft_split(argv[3], ' ');
	if (pipex->cmd_arg[0][0] == '/' && access(pipex->cmd_arg[0], 0) == 0)
		pipex->path = pipex->cmd_arg[0];
	else
		pipex->path = ft_get_path(pipex->cmd_arg[0], envp);
	if (execve(pipex->path, pipex->cmd_arg, envp) == -1)
		ft_error(pipex, "Not such command found: ", pipex->cmd_arg[0]);
}

/* This program copies the behaviour of pipe " | ". First initializes px     */
/* pointers to null. It checks for argument error. Initializes pipe and fork,*/
/* and calls children, one for each commands. Frees px structure at end      */
int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	pipex.cmd_arg = NULL;
	pipex.path = NULL;
	if (argc != 5)
		ft_error(&pipex, "Wrong number of arguments", NULL);
	if (pipe(pipex.fd) < 0)
		ft_error(&pipex, "Can't open pipe", NULL);
	pipex.pid1 = fork();
	if (pipex.pid1 < 0)
		ft_error(&pipex, "Can't open first fork", NULL);
	if (pipex.pid1 == 0)
		ft_child_one(&pipex, argv, envp);
	pipex.pid2 = fork();
	if (pipex.pid2 < 0)
		ft_error(&pipex, "Can't open second fork", NULL);
	if (pipex.pid2 == 0)
		ft_child_two(&pipex, argv, envp);
	ft_free_pipex(&pipex);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	return (0);
}
