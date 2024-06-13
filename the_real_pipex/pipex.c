/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 06:41:43 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/06/13 12:16:05 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*is_exec(char *cmd, char **paths)
{
	char	*executable;
	char	*part;

	executable = NULL;
	part = NULL;
	while (*paths)
	{
		executable = ft_strjoin(paths[0], "/");
		if (!executable)
			return (NULL);
		else//if (executable)
		{
			part = ft_strjoin(executable, cmd);
			free(executable);
			if (!part)
				return (NULL);
			if (access(part, X_OK) == 0)
				return (part);
			free(part);
		}
		paths++;
	}
	return (NULL);
}

char	*find_path(char *path, char **args, char **envp)
{
	char	**paths;
	int		i;

	i = 0;
	paths = NULL;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	if (!paths)
		return (NULL);//exit(EXIT_FAILURE);
	path = is_exec(args[0], paths);
	free_double(paths);
	if (!path)
		return (NULL);
	return (path);
}

void	exec_cmd(char **av, int x, char **envp)
{
	char	**args;
	char	*path;

	path = NULL;
	args = ft_split(av[x], ' ');
	if (!args)
		exit(EXIT_FAILURE);
	path = find_path(path, args, envp);
	if (!path)
	{
		free_double(args);
		ft_putstr_fd("\033[91mError: Command not found\n\e[0m", 2);
		exit(127);
	}
	execve(path, args, envp);
	free_double(args);
	free(path);
	perror("execve");
	exit(EXIT_FAILURE);
}
