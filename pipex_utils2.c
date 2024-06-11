/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:38:51 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/06/11 14:49:15 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_fds(int *fd)
{
	close(fd[0]);
	close(fd[1]);
}

void	handle_child_processes(int i, int *fd, char **av, char **envp)
{
	if (i == 0 && child1(fd, av, envp) == -1)
		err_log("\033[91mError: child1 failed\n\e[0m");
	if (i == 1 && child2(fd, av, envp) == -1)
		err_log("\033[91mError: child2 failed\n\e[0m");
}

void	create_processes(pid_t *pid, int *fd, char **av, char **envp)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		pid[i] = fork();
		if (pid[i] == -1)
			err_log("\033[91mError: fork failed\n\e[0m");
		if (pid[i] == 0)
			handle_child_processes(i, fd, av, envp);
		i++;
	}
}

void	wait_for_processes(pid_t *pid)
{
	int	i;

	i = 1;
	while (i >= 0)
	{
		waitpid(pid[i], NULL, 0);
		i--;
	}
}
