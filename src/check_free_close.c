/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_free_close.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 06:41:58 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/06/14 19:19:07 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	close_fds(t_pipex *p)
{
	if (p->fd[0] && p->fd[0] != -1)
		close(p->fd[0]);
	if (p->fd[1] && p->fd[1] != -1)
		close(p->fd[1]);
	if (p->filein && p->filein != STDIN_FILENO && p->filein != -1)
		close(p->filein);
	if (p->fileout && p->fileout != STDOUT_FILENO && p->fileout != -1)
		close(p->fileout);
}

void	err_free(t_pipex *p, int exit_status)
{
	close_fds(p);
	if (p->args)
		free_double(p->args);
	if (p->paths)
		free_double(p->paths);
	if (p->path)
		free(p->path);
	if (p->executable)
		free(p->executable);
	if (p->part)
		free(p->part);
	exit(exit_status);
}

void	free_double(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}

void	check_filein(char **av, t_pipex *p)
{
	p->filein = open(av[1], O_RDONLY);
	if (p->filein == -1)
	{
		perror(av[1]);
		err_free(p, 1);
	}
	if (access(av[1], F_OK) == -1)
	{
		perror(av[1]);
		err_free(p, 1);
	}
	close(p->filein);
}

void	check_fileout(char **av, t_pipex *p)
{
	p->fileout = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (p->fileout == -1)
	{
		perror(av[4]);
		err_free(p, 1);
	}
	if (access(av[4], W_OK) == -1)
	{
		perror(av[4]);
		err_free(p, 1);
	}
	close(p->fileout);
}
