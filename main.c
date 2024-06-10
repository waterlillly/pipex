/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:40:28 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/06/10 23:05:04 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void close_fds(int *fd)
{
    close(fd[0]);
    close(fd[1]);
}

void handle_child_processes(int i, int *fd, char **av, char **envp)
{
    if (i == 0 && child1(fd, av, envp) == -1)
        err_log("\033[91mError: child1 failed\n\e[0m");
    if (i == 1 && child2(fd, av, envp) == -1)
        err_log("\033[91mError: child2 failed\n\e[0m");
}

void create_processes(t_pipex *p, int *i, char **av, char **envp)
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

void wait_for_processes(int i, pid_t *pid)
{
    while (i > 0)
    {
        i--;
        waitpid(pid[i], NULL, 0);
    }
}

void init_pipex(t_pipex *p, pid_t *pid, int *fd)
{
    p->pid = pid;
    p->fd = fd;
}

int main(int ac, char **av, char **envp)
{
    int 	fd[2];
    pid_t	pid[2];
    int 	i;
    t_pipex *p;

    i = 0;
	p = NULL;
    check(ac, av);
    if (pipe(fd) == -1)
        return (err_log("\033[91mError: pipe failed\n\e[0m"), -1);
    init_pipex(p, pid, fd);
    create_processes(p, &i, av, envp);
    close_fds(fd);
    wait_for_processes(i, pid);
    return (0);
}
/*
int main(int ac, char **av, char **envp)
{
	int 	fd[2];
	pid_t	pid[2];
	int 	i;

	i = 0;
	check(ac, av);
	if (pipe(fd) == -1)
		return (err_log("\033[91mError: pipe failed\n\e[0m"), -1);
	while (i < 2)
	{
		pid[i] = fork();
		if (pid[i] == -1)
			return (err_log("\033[91mError: fork failed\n\e[0m"), -1);
		if (pid[i] == 0)
		{
			if (i == 0 && child1(fd, av, envp) == -1)
				return (err_log("\033[91mError: child1 failed\n\e[0m"), -1);
			if (i == 1 && child2(fd, av, envp) == -1)
				return (err_log("\033[91mError: child2 failed\n\e[0m"), -1);
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
*/