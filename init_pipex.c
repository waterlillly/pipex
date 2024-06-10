/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 20:33:29 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/06/04 17:21:16 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    init_pipex(pipex *p, char **av, char **envp)
{
    p->fd[0] = 0;
    p->fd[1] = 0;
    p->file1 = av[1];
    p->file2 = av[4];
    p->cmd1 = av[2];
    p->cmd2 = av[3];
    p->envp = envp;
}