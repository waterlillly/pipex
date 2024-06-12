/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:24:20 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/06/12 18:26:45 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	child1(int *fd, char **av, char **envp)
{
	int	filein;

	close(fd[0]);
	filein = open(av[1], O_RDONLY);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
	{
		close_fds(-1, fd[1], filein);
		exit(EXIT_FAILURE);
	}
	if (dup2(filein, STDIN_FILENO) == -1)
	{
		close_fds(-1, fd[1], filein);
		exit(EXIT_FAILURE);
	}
	close(fd[1]);
	close(filein);
	if (exec_cmd(av[2], envp))
	{
		perror(av[2]);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_FAILURE);
}

int	child2(int *fd, char **av, char **envp)
{
	int	fileout;

	close(fd[1]);
	fileout = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (dup2(fd[0], STDIN_FILENO) == -1)
	{
		close_fds(fd[0], -1, fileout);
		exit(EXIT_FAILURE);
	}
	if (dup2(fileout, STDOUT_FILENO) == -1)
	{
		close_fds(fd[0], -1, fileout);
		exit(EXIT_FAILURE);
	}
	close(fileout);
	close(fd[0]);
	if (exec_cmd(av[3], envp))
	{
		perror(av[3]);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_FAILURE);
}

char	*is_exec(char *cmd, char **paths)
{
	char	*executable;
	char	*part;

	executable = NULL;
	part = NULL;
	if(access(cmd, X_OK) == 0)
		return(cmd);
	while (*paths)
	{
		executable = ft_strjoin(paths[0], "/"); // protect 
		if (executable)
		{
			part = ft_strjoin(executable, cmd);
			free(executable);
			if (!part)
				exit(EXIT_FAILURE); //free args
			if (access(part, X_OK) == 0)
				return (part);
			free(part);
		}
		paths++;
	}
	return (NULL);
}

char	*find_path(char *path, char *cmd, char **envp)
{
	char	**paths;
	int		i;

	i = 0;
	paths = NULL;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	if (!paths)
		exit(EXIT_FAILURE); //free args
	path = is_exec(cmd, paths);
	free_double(paths);
	if (!path)
	{
		ft_putstr_fd("\033[91mError: Command not found\n\e[0m", 2);
		return (NULL);
	}
	return (path);
}

int	exec_cmd(char *cmd, char **envp)
{
	char	**args;
	char	*path;

	path = NULL;
	args = ft_split(cmd, ' ');
	if (!args)
		exit(EXIT_FAILURE);
	path = find_path(path, args[0], envp);
	if (!path)
	{
		free_double(args);
		exit(127);
	}
	execve(path, args, envp);
	free_double(args);
	free(path);
	return (0);
}
