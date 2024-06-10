/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:47:39 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/06/07 14:41:29 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	err_log(char *str)
{
	ft_putstr_fd(str, STDERR_FILENO);
	exit(1);
}

void	check_ac(int ac)
{
	if (ac != 5)
		err_log("Error: Wrong number of arguments\n");
}

void	free_exec(char *executable)
{
	free(executable);
	executable = NULL;
}

void	reset_pipe(int *pipe_fd[2])
{
	close((*pipe_fd)[0]);
	close((*pipe_fd)[1]);
	pipe((*pipe_fd));
}

/*
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