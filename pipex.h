/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:02:40 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/06/12 17:43:01 by lbaumeis         ###   ########.fr       */
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
char	*find_path(char *path, char *cmd, char **envp, char **args);
char	*is_exec(char *cmd, char **paths, char **args);
int		exec_cmd(char *cmd, char **envp);

/*PIPEX_UTILS*/
void	close_fds(int fd_0, int fd_1, int file);
void	check(int ac, char **av);
void	free_double(char **str);
void	check_filein(char **av);
void	check_fileout(char **av);

/*PIPEX_UTILS2*/
void	handle_child_processes(int i, int *fd, char **av, char **envp);
void	create_processes(pid_t *pid, int *fd, char **av, char **envp);
int 	wait_for_processes(pid_t *pid);

#endif
