/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 06:42:08 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/06/13 11:30:39 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	pid_t	pid[2];

	check(ac, av);
	if (pipe(fd) == -1)
		exit(EXIT_FAILURE);
	create_processes(pid, fd, av, envp);
	close_fds(fd[0], fd[1], 0);
	return (wait_for_processes(pid));
}
