/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 06:41:29 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/06/13 19:14:49 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <sys/wait.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>

typedef struct s_pipex
{
	pid_t	pid[2];
	int		fd[2];
	int		filein;
	int		fileout;
	int		status;
	int		other;
	char	**args;
	char	**paths;
	char	*path;
	char	*executable;
	char	*part;
	char	*cmd;
}			t_pipex;

/*PIPEX*/
char	*find_path(t_pipex *p, char **envp);
char	*is_exec(t_pipex *p);
void	exec_cmd(char **av, int x, t_pipex *p, char **envp);

/*CHECK_FREE_CLOSE*/
void	close_fds(t_pipex *p);
void	err_free(t_pipex *p);
void	free_double(char **str);
void	check_filein(char **av, t_pipex *p);
void	check_fileout(char **av, t_pipex *p);

/*PROCESSES*/
void	child1(char **av, t_pipex *p, char **envp);
void	child2(char **av, t_pipex *p, char **envp);
void	handle_child_processes(int i, char **av, t_pipex *p, char **envp);
void	create_processes(char **av, t_pipex *p, char **envp);
int		wait_for_processes(t_pipex *p);

#endif
