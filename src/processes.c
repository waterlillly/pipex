/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 06:41:51 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/06/14 18:37:39 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	child1(char **av, t_pipex *p, char **envp)
{
	check_filein(av, p);
	p->filein = open(av[1], O_RDONLY);
	if (p->filein == -1)
		err_free(p, 1);
	if (dup2(p->fd[1], STDOUT_FILENO) == -1)
		err_free(p, 1);
	if (dup2(p->filein, STDIN_FILENO) == -1)
		err_free(p, 1);
	close_fds(p);
	exec_cmd(av, 2, p, envp);
}

void	child2(char **av, t_pipex *p, char **envp)
{
	check_fileout(av, p);
	p->fileout = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (p->fileout == -1)
		err_free(p, 1);
	if (dup2(p->fd[0], STDIN_FILENO) == -1)
		err_free(p, 1);
	if (dup2(p->fileout, STDOUT_FILENO) == -1)
		err_free(p, 1);
	close_fds(p);
	exec_cmd(av, 3, p, envp);
}

void	handle_child_processes(int i, char **av, t_pipex *p, char **envp)
{
	if (i == 0)
		child1(av, p, envp);
	if (i == 1)
		child2(av, p, envp);
}

void	create_processes(char **av, t_pipex *p, char **envp)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		p->pid[i] = fork();
		if (p->pid[i] == -1)
			err_free(p, 1);
		if (p->pid[i] == 0)
			handle_child_processes(i, av, p, envp);
		i++;
	}
}

int	wait_for_processes(t_pipex *p)
{
	int	i;

	i = 0;
	close_fds(p);
	while (i < 2)
	{
		if (waitpid(p->pid[i], &p->status, 0) == -1)
			err_free(p, 1);
		if (WIFEXITED(p->status))
			p->status = WEXITSTATUS(p->status);
		i++;
	}
	return (p->status);
}
