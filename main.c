#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	pid_t	pid[2];

	check(ac, av);
	check_filein(av);
	check_fileout(av);
	if (pipe(fd) == -1)
		exit(EXIT_FAILURE);
	create_processes(pid, fd, av, envp);
	close_fds(fd[0], fd[1], 0);
	return (wait_for_processes(pid));
}