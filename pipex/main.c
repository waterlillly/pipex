/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 06:42:08 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/06/14 15:26:56 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_pipex	p;

	if (ac != 5)
		exit(EXIT_FAILURE);
	ft_bzero(&p, sizeof(p));
	if (pipe(p.fd) == -1)
		err_free(&p);
	create_processes(av, &p, envp);
	wait_for_processes(&p);
	err_free(&p);
	return (0);
}
