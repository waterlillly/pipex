/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 06:41:43 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/06/14 15:11:42 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*is_exec(t_pipex *p)
{
	while (*p->paths)
	{
		p->executable = ft_strjoin(p->paths[0], "/");
		if (!p->executable)
			err_free(p);
		p->part = ft_strjoin(p->executable, p->cmd);
		if (!p->part)
			err_free(p);
		free(p->executable);
		if (access(p->part, X_OK) == 0)
			return (p->part);
		free(p->part);
		p->paths++;
	}
	return (NULL);
}

char	*find_path(t_pipex *p, char **envp)
{
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	p->paths = ft_split(envp[i] + 5, ':');
	if (!p->paths)
		return (NULL);
	p->path = is_exec(p);
	if (!p->path)
		return (NULL);
	return (p->path);
}

void	exec_cmd(char **av, int x, t_pipex *p, char **envp)
{
	p->args = ft_split(av[x], ' ');
	if (!p->args)
		err_free(p);
	p->cmd = p->args[0];
	p->path = find_path(p, envp);
	if (!p->path)
	{
		p->other = 1;
		err_free(p);
	}
	execve(p->path, p->args, envp);
	p->other = 2;
	err_free(p);
}
