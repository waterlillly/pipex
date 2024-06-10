/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randoms.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 20:33:29 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/06/10 22:37:38 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
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

pipex	*check_and_init(int ac, pipex *p, char **av)
{
	if (ac != 5)
		return (err_log("Error: Wrong number of arguments\n"), NULL);
	p->filein = open(av[1], O_RDONLY, 0777);
	if (p->filein == -1 || access(av[1], R_OK))
		return (err_log("Error: Filein failed\n"), NULL);
	p->fileout = open(av[4], O_RDWR | O_CREAT | O_APPEND, 0777);
	if (p->fileout == -1 || access(av[4], F_OK))
		return (err_log("Error: Fileout failed\n"), NULL);
	p->cmd1 = av[2];
	p->cmd2 = av[3];
	p->path = NULL;
	return (p);
}
*/