/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:40:28 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/06/11 13:03:10 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	pid_t	pid[2];
	int		i;
	t_pipex	*p;

	i = 0;
	p = NULL;
	p = (t_pipex *)malloc(sizeof(t_pipex));
	if (!p)
		return (err_log("\033[91mError: malloc failed\n\e[0m"), -1);
	check(ac, av);
	if (pipe(fd) == -1)
		return (err_log("\033[91mError: pipe failed\n\e[0m"), -1);
	init_pipex(p, pid, fd);
	create_processes(p, &i, av, envp);
	close_fds(fd);
	wait_for_processes(i, pid);
	return (0);
}
