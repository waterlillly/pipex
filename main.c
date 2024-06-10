/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:40:28 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/06/10 19:00:45 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int ac, char **av, char **envp)
{
	int 	fd[2];
	pid_t	pid[2];
	//int 	c;
	int 	i;

	i = 0;
	if(check(ac, av))
	{
		ft_putstr_fd("\033[31mError: Bad arguments\n\e[0m", 2);
		ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
	}
	if (pipe(fd) == -1)
		return (err_log("Error: Pipe failed"), -1);
	//c = count_args(av);
	while (i < 2)
	{
		pid[i] = fork();
		if (pid[i] == -1)
			return (err_log("Error: Fork failed"), -1);
		if (pid[i] == 0)
		{
			if (i == 0 && child(fd, av, envp) == -1)
				return (err_log("Error: Child exec failed"), -1);
			if (i == 1 && child2(fd, av, envp) == -1)
				return (err_log("Error: Parent exec failed"), -1);
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

