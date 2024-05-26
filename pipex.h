/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:02:40 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/05/26 21:56:55 by lbaumeis         ###   ########.fr       */
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

int 	child(char **av, int *fd, char **envp);
int     parent(char **av, int *fd, char **envp);
char	*find_path(char *cmd, char **envp);
char	*is_exec(char *cmd, char **paths);
int	    exec_cmd(char *cmd, char **envp);
int     err_log(int x);

//open, close, read, write, malloc, free, perror, stderror, dup, dup2, access, execve, exit, fork, pipe, wait, waitpid, unlink

#endif