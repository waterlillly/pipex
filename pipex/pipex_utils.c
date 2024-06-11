/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:47:39 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/06/11 12:56:47 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	err_log(char *str)
{
	ft_putstr_fd(str, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	check(int ac, char **av)
{
	if (ac != 5 || !av)
	{
		ft_putstr_fd("\033[90mEx:./pipex <file1> <cmd1> <cmd2> <file2>\n\e[0m",
			STDERR_FILENO);
		err_log("\033[91mError: Bad arguments\n\e[0m");
	}
}

int	count_args(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i - 3);
}

void	free_double(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	init_pipex(t_pipex *p, pid_t *pid, int *fd)
{
	p->fd = fd;
	p->pid = pid;
}
