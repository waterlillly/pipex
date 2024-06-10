/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:40:28 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/06/09 20:10:48 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int ac, char **av, char **envp)
{
	int 	fd[2];
	pid_t	pid;

	if (check_ac(ac))
	{
		if (pipe(fd) == -1)
			return (err_log("Error: Pipe failed"));
		pid = fork();
		if (pid == 0)
		{
			if (child(av, fd, envp) == -1)
				return (err_log("Error: Child exec failed"));
		}
		else
		{
			waitpid(pid, NULL, 0);
			if (parent(av, fd, envp) == -1)
				return (err_log("Error: Parent exec failed"));
		}
	}
	else
	{
		ft_putstr_fd("\033[31mError: Bad arguments\n\e[0m", 2);
		ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
	}
	return (0);
}
