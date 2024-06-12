
#include "pipex.h"

void	handle_child_processes(int i, int *fd, char **av, char **envp)
{
	if (i == 0 && child1(fd, av, envp) == -1)
		exit(EXIT_FAILURE);
	if (i == 1 && child2(fd, av, envp) == -1)
		exit(EXIT_FAILURE);
}

void	create_processes(pid_t *pid, int *fd, char **av, char **envp)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		pid[i] = fork();
		if (pid[i] == -1)
			exit(EXIT_FAILURE);
		if (pid[i] == 0)
			handle_child_processes(i, fd, av, envp);
		i++;
	}
}

int	wait_for_processes(pid_t *pid)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	while (i < 2)
	{
		if (waitpid(pid[i], &status, 0) == -1)
			exit(EXIT_FAILURE);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
		i++;
	}
	return(status);
}

void	check_filein(char **av)
{
	int	filein;
	
	filein = open(av[1], O_RDONLY);
	if (filein == -1)
	{
		perror(av[1]);
		exit(EXIT_FAILURE);
	}
	if (access(av[1], R_OK) == -1)
	{
		close(filein);
		perror(av[1]);
		exit(EXIT_FAILURE);
	}
	close(filein);
}

void	check_fileout(char **av)
{
	int	fileout;
	
	fileout = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fileout == -1)
	{
		perror(av[4]);
		exit(EXIT_FAILURE);
	}
	if (access(av[4], W_OK) == -1)
	{
		close(fileout);
		perror(av[4]);
		exit(EXIT_FAILURE);
	}
	close(fileout);
}