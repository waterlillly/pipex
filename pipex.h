/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:02:40 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/06/11 19:52:10 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <sys/wait.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>

/*PIPEX*/
int		child1(int *fd, char **av, char **envp);
int		child2(int *fd, char **av, char **envp);
char	*find_path(char *path, char *cmd, char **envp);
char	*is_exec(char *cmd, char **paths);
int		exec_cmd(char *cmd, char **envp);

/*PIPEX_UTILS*/
void	err_log(char *str);
void	check(int ac, char **av);
int		count_args(char **av);
void	free_double(char **str);

/*PIPEX_UTILS2*/
void	close_fds(int *fd);
void	handle_child_processes(int i, int *fd, char **av, char **envp);
void	create_processes(pid_t *pid, int *fd, char **av, char **envp);
void	wait_for_processes(pid_t *pid);

#endif
