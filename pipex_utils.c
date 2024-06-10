/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:47:39 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/06/10 18:54:28 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	err_log(char *str)
{
	ft_putstr_fd(str, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

int	check(int ac, char **av)
{
	if (ac != 5 || !av)
		return (err_log("Error: Wrong number of arguments\n"), -1);
	return (0);
}

int	count_args(char **av)
{
	int i;

	i = 0;
	while (av[i])
		i++;
	return (i - 3);
}

static void free_double(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

/*
void	reset_pipe(int *pipe_fd[2])
{
	close((*pipe_fd)[0]);
	close((*pipe_fd)[1]);
	pipe((*pipe_fd));
}

int unlink_file()
{
	char *file;

	file = "example.txt";
	if (unlink("example.txt") == 0)
		ft_printf("File successfully deleted");
	else
		ft_printf("Error deleting file");
	return (0);
}
*/