/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:24:20 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/06/10 11:58:42 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	child(char **av, int *fd, char **envp)
{
	int	filein;
	
	close(fd[0]);
	filein = open(av[1], O_RDONLY, 0644);
	if (filein == -1)
		return (err_log("Error: File1 failed\n"));
	dup2(fd[1], STDOUT_FILENO);
	dup2(filein, STDIN_FILENO);
	if (exec_cmd(av[2], envp) == -1)
		return (-1);
	close(fd[1]);
	return (0);
}

int parent(char **av, int *fd, char **envp)
{
	int	fileout;
	
	close(fd[1]);
	fileout = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fileout == -1)
		return (err_log("Error: File2 failed\n"));
	dup2(fd[0], STDIN_FILENO);
	dup2(fileout, STDOUT_FILENO);
	close(fd[0]);
	if (exec_cmd(av[3], envp) == -1)
		return (-1);
	return (0);
}

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	path = is_exec(cmd, paths);
	if (path)
		return (path);
    i = -1;
    while (paths[++i])
        free(paths[i]);
    free(paths);
    return (NULL);
}

char	*is_exec(char *cmd, char **paths)
{
    char	*executable;

	executable = NULL;
	while (*paths)
	{
		executable = ft_strjoin(paths[0], "/");
		executable = ft_strjoin(executable, cmd);
		if (access(executable, X_OK) == 0)
			return (executable);
		free(executable);
		paths++;
	}
	return (NULL);
}

int	exec_cmd(char *cmd, char **envp)
{
	char	*path;
	char	**args;

	path = find_path(cmd, envp);
	if (!path)
		return (-1);
	args = ft_split(cmd, ' ');
	if (execve(path, args, envp) == -1)
		return (-1);
	return (0);
}

//https://github.com/gabcollet/pipex/blob/master/srcs/utils.c