/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:47:39 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/06/02 17:54:17 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int err_log(int x)
{
	if (x == 1)
		perror("Error: Wrong number of arguments");
	if (x == 2)
		perror("Error: Pipe failed");
	if (x == 3)
		perror("Error: File1 failed");
	if (x == 4)
		perror("Error: File2 failed");
	if (x == 5)
		perror("Error: Child exec failed");
	if (x == 6)
		perror("Error: Parent exec failed");
	return (0);
}

void	free_exec(char *executable)
{
	free(executable);
	executable = NULL;
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