/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_free_close.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 06:41:58 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/06/13 11:28:16 by lbaumeis         ###   ########.fr       */
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
/*
void	check(int ac, char **av)
{
	if (ac != 5)
		exit(EXIT_FAILURE);
	if (access(av[1], R_OK) == -1)
	{
		perror(av[1]);
		exit(EXIT_FAILURE);
	}
	if (access(av[4], W_OK) == -1)
	{
		perror(av[4]);
		exit(EXIT_FAILURE);
	}
}
*/
void	check(int ac, char **av)
{
	if (ac != 5 || !av)
		exit(EXIT_FAILURE);
}

void	check_filein(char **av)
{
	int	filein;
	
	filein = open(av[1], O_RDONLY);
	if (filein == -1)
	{
		perror(av[1]);
		exit(EXIT_FAILURE);
	}
	if (access(av[1], F_OK) == -1)
	{
		close(filein);
		perror(av[1]);
		exit(EXIT_FAILURE);
	}
	close(filein);
}

void	check_fileout(char **av)
{
	int	fileout;
	
	fileout = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fileout == -1)
	{
		perror(av[4]);
		exit(EXIT_FAILURE);
	}
	if (access(av[4], W_OK) == -1)
	{
		close(fileout);
		perror(av[4]);
		exit(EXIT_FAILURE);
	}
	close(fileout);
}
