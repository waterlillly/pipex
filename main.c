/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:40:28 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/05/26 21:57:07 by lbaumeis         ###   ########.fr       */
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
		child(av, fd, envp);
	else
	{
		waitpid(id, NULL, 0);
		parent(av, fd, envp);
	}
	return (0);
}
