/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:40:28 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/05/27 07:32:39 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int ac, char **av, char **envp)
{
	int 	fd[2];
	pid_t	id;

	if (ac != 5)
		return (err_log(1));
	if (pipe(fd) == -1)
		return (err_log(2));
	id = fork();
	if (id == 0)
	{
		if (child(av, fd, envp) == -1)
			return (err_log(5));
	}
	waitpid(id, NULL, 0);
	if (parent(av, fd, envp) == -1)
		return (err_log(6));
	return (0);
}
