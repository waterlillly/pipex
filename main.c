/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:40:28 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/06/11 18:11:55 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	pid_t	pid[2];

	check(ac, av);
	if (pipe(fd) == -1)
		return (err_log("\033[91mError: pipe failed\n\e[0m"), -1);
	create_processes(pid, fd, av, envp);
	close_fds(fd);
	wait_for_processes(pid);
	return (0);
}
