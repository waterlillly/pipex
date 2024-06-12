/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:47:39 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/06/12 16:11:14 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_fds(int fd_0, int fd_1, int file)
{
	if (fd_0 != -1)
		close(fd_0);
	if (fd_1 != -1)
		close(fd_1);
	if (file)
		close(file);
}

void	check(int ac, char **av)
{
	if (ac != 5 || !av)
		exit(EXIT_FAILURE);
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
