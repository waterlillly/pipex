/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:38:51 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/06/11 12:39:16 by lbaumeis         ###   ########.fr       */
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

void	create_processes(t_pipex *p, int *i, char **av, char **envp)
{
	while (*i < 2)
	{
		p->pid[*i] = fork();
		if (p->pid[*i] == -1)
			err_log("\033[91mError: fork failed\n\e[0m");
		if (p->pid[*i] == 0)
			handle_child_processes(*i, p->fd, av, envp);
		(*i)++;
	}
}

void	wait_for_processes(int i, pid_t *pid)
{
	while (i > 0)
	{
		i--;
		waitpid(pid[i], NULL, 0);
	}
}
