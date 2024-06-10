/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:02:40 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/06/10 18:57:42 by lbaumeis         ###   ########.fr       */
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

/*PIPEX*/
int 		child(int *fd, char **av, char **envp);
int     	child2(int *fd, char **av, char **envp);
char		*find_path(char *path, char *cmd, char **envp);
char		*is_exec(char *cmd, char **paths);
int	    	exec_cmd(char *cmd, char **envp);

/*PIPEX_UTILS*/
void		err_log(char *str);
int			check(int ac, char **av);
int			count_args(char **av);
static void free_double(char **str);

//open, close, read, write, malloc, free, perror, stderror, dup, dup2, access, execve, exit, fork, pipe, wait, waitpid, unlink

#endif
