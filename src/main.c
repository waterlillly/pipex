/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 06:42:08 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/06/14 19:21:59 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_pipex	p;
	int		exit_status;

	if (ac != 5)
		exit(EXIT_FAILURE);
	ft_bzero(&p, sizeof(p));
	if (pipe(p.fd) == -1)
		err_free(&p, 1);
	create_processes(av, &p, envp);
	exit_status = wait_for_processes(&p);
	return (err_free(&p, exit_status), 0);
}
