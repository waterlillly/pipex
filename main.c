/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:40:28 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/06/12 17:43:10 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	pid_t	pid[2];

	check(ac, av);
	check_filein(av);
	check_fileout(av);
	if (pipe(fd) == -1)
		exit(EXIT_FAILURE);
	create_processes(pid, fd, av, envp);
	close_fds(fd[0], fd[1], 0);
	return (wait_for_processes(pid));
}
