/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:20:12 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/06/10 18:47:14 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	err_log(char *str)
{
	ft_putstr_fd(str, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

int	check(int ac, char **av)
{
	if (ac != 5 || !av)
		return (err_log("Error: Wrong number of arguments\n"), -1);
	return (0);
}

int	child(int *fd, char **av, char **envp)
{
	int	filein;

	filein = 0;
	close(fd[0]);
	filein = open(av[1], O_RDONLY, 0644);
	if (filein == -1 || access(av[1], R_OK))
		return (err_log("Error: Filein failed\n"), -1);
	dup2(fd[1], STDOUT_FILENO);
	if (fd[1] == -1)
		return (err_log("Error: Dup2 failed\n"), -1);
	close(fd[1]);
	close(filein);
	if (exec_cmd(av[2], envp))
		return (err_log("Error: Execve failed\n"), -1);
	return (0);
}

int child2(int *fd, char **av, char **envp)
{	
	int	fileout;

	fileout = 0;
	close(fd[1]);
	fileout = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (fileout == -1 || access(av[4], F_OK))
		return (err_log("Error: Fileout failed\n"), -1);
	dup2(fd[0], STDIN_FILENO);
	if (fd[0] == -1)
		return (err_log("Error: Dup2 failed\n"), -1);
	dup2(fileout, STDOUT_FILENO);
	close(fd[0]);
	close(fileout);
	if (exec_cmd(av[3], envp))
		return (err_log("Error: Execve failed\n"), -1);
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
				err_log("Error: Strjoin failed\n");
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

static void free_double(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
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
		return (err_log("Error: Split failed\n"), NULL);
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
		return (err_log("Error: Split failed\n"), -1);
	path = find_path(path, args[0], envp);
	if (!path)
		return (err_log("Error: No path found\n"), -1);
	if (execve(path, args, envp) == -1)
		return (err_log("Error: Execve failed\n"), -1);
	free_double(args);
	free(path);
	return (0);
}

int	count_args(char **av)
{
	int i;

	i = 0;
	while (av[i])
		i++;
	return (i - 3);
}

int main(int ac, char **av, char **envp)
{
	int 	fd[2];
	pid_t	pid[2];
	int 	c;
	int 	i;

	i = 0;
	if(check(ac, av))
	{
		ft_putstr_fd("\033[31mError: Bad arguments\n\e[0m", 2);
		ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
	}
	if (pipe(fd) == -1)
		return (err_log("Error: Pipe failed"), -1);
	c = count_args(av);
	while (i < c)
	{
		pid[i] = fork();
		if (pid[i] == -1)
			return (err_log("Error: Fork failed"), -1);
		if (pid[i] == 0)
		{
			if (i == 0 && child(fd, av, envp) == -1)
				return (err_log("Error: Child exec failed"), -1);
		//	if (i == 1 && child2(fd, av, envp) == -1)
			//	return (err_log("Error: Parent exec failed"), -1);
		}
		i++;
	}
	close(fd[0]);
	close(fd[1]);
	while (i > 0)
	{
		i--;
		waitpid(pid[i], NULL, 0);
	}
	return (0);
}
