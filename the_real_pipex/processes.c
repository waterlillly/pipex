/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 06:41:51 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/06/13 12:21:16 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1(int *fd, char **av, char **envp)
{
	int	filein;

	check_filein(av);
	filein = open(av[1], O_RDONLY);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
	{
		close_fds(fd[0], fd[1], filein);
		exit(EXIT_FAILURE);
	}
	if (dup2(filein, STDIN_FILENO) == -1)
	{
		close_fds(fd[0], fd[1], filein);
		exit(EXIT_FAILURE);
	}
	close_fds(fd[0], fd[1], filein);
	exec_cmd(av, 2, envp);
	exit(EXIT_FAILURE);
}

void	child2(int *fd, char **av, char **envp)
{
	int	fileout;

	check_fileout(av);
	fileout = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (dup2(fd[0], STDIN_FILENO) == -1)
	{
		close_fds(fd[0], fd[1], fileout);
		exit(EXIT_FAILURE);
	}
	if (dup2(fileout, STDOUT_FILENO) == -1)
	{
		close_fds(fd[0], fd[1], fileout);
		exit(EXIT_FAILURE);
	}
	close_fds(fd[0], fd[1], fileout);
	exec_cmd(av, 3, envp);
	exit(EXIT_FAILURE);
}

void	handle_child_processes(int i, int *fd, char **av, char **envp)
{
	if (i == 0)
		child1(fd, av, envp);
	if (i == 1)
		child2(fd, av, envp);
}

void	create_processes(pid_t *pid, int *fd, char **av, char **envp)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		pid[i] = fork();
		if (pid[i] == -1)
			exit(EXIT_FAILURE);
		if (pid[i] == 0)
			handle_child_processes(i, fd, av, envp);
		i++;
	}
}

int	wait_for_processes(pid_t *pid)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	while (i < 2)
	{
		if (waitpid(pid[i], &status, 0) == -1)
			exit(EXIT_FAILURE);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
		i++;
	}
	return(status);
}
