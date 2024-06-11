/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:24:20 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/06/11 19:12:01 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	child1(int *fd, char **av, char **envp)
{
	int	filein;

	filein = 0;
	close(fd[0]);
	filein = open(av[1], O_RDONLY, 0644);
	if (filein == -1 || access(av[1], R_OK))
		return (close_fds(fd),
			err_log("\033[91mError: opening filein failed\n\e[0m"), -1);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		return (close_fds(fd),
			err_log("\033[91mError: dup2 failed\n\e[0m"), -1);
	if (dup2(filein, STDIN_FILENO) == -1)
		return (close_fds(fd),
			err_log("\033[91mError: dup2 failed\n\e[0m"), -1);
	close(fd[1]);
	close(filein);
	if (exec_cmd(av[2], envp))
		return (err_log("\033[91mError: execve failed\n\e[0m"), -1);
	return (0);
}

int	child2(int *fd, char **av, char **envp)
{
	int	fileout;

	fileout = 0;
	close(fd[1]);
	fileout = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (fileout == -1 || access(av[4], F_OK))
		return (close_fds(fd),
			err_log("\033[91mError: opening fileout failed\n\e[0m"), -1);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		return (close_fds(fd),
			err_log("\033[91mError: dup2 failed\n\e[0m"), -1);
	if (dup2(fileout, STDOUT_FILENO) == -1)
		return (close_fds(fd),
			err_log("\033[91mError: dup2 failed\n\e[0m"), -1);
	close(fileout);
	close(fd[0]);
	if (exec_cmd(av[3], envp))
		return (err_log("\033[91mError: execve failed\n\e[0m"), -1);
	return (0);
}

char	*is_exec(char *cmd, char **paths)
{
	char	*executable;
	char	*part;

	executable = NULL;
	while (*paths)
	{
		executable = ft_strjoin(paths[0], "/");
		if (executable)
		{
			part = ft_strjoin(executable, cmd);
			if (!part)
			{
				err_log("\033[91mError: ft_strjoin failed\n\e[0m");
				free(executable);
				return (NULL);
			}
			free(executable);
			if (access(part, X_OK) == 0)
				return (part);
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
		return (err_log("\033[91mError: split failed\n\e[0m"), NULL);
	path = is_exec(cmd, paths);
	i = 0;
	free_double(paths);
	return (path);
}

int	exec_cmd(char *cmd, char **envp)
{
	char	**args;
	char	*path;

	path = NULL;
	args = ft_split(cmd, ' ');
	if (!args)
		return (err_log("\033[91mError: split failed\n\e[0m"), -1);
	path = find_path(path, args[0], envp);
	if (!path)
		return (err_log("\033[91mError: no path found\n\e[0m"), -1);
	execve(path, args, envp);
	free_double(args);
	free(path);
	return (1);
}
