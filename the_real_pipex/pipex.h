/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 06:41:29 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/06/13 11:52:27 by lbaumeis         ###   ########.fr       */
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

/*PIPEX*/
char	*find_path(char *path, char **args, char **envp);
char	*is_exec(char *cmd, char **paths);
void	exec_cmd(char **av, int x, char **envp);

/*CHECK_FREE_CLOSE*/
void	close_fds(int fd_0, int fd_1, int file);
void	check(int ac, char **av);
void	free_double(char **str);
void	check_filein(char **av);
void	check_fileout(char **av);

/*PROCESSES*/
void	child1(int *fd, char **av, char **envp);
void	child2(int *fd, char **av, char **envp);
void	handle_child_processes(int i, int *fd, char **av, char **envp);
void	create_processes(pid_t *pid, int *fd, char **av, char **envp);
int 	wait_for_processes(pid_t *pid);

#endif
