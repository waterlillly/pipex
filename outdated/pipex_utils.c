#include "pipex.h"

void	close_fds(int fd_0, int fd_1, int file)
{
	if (fd_0 != -1)
		close(fd_0);
	if (fd_1 != -1)
		close(fd_1);
	if (file)
		close(file);
}

void	check(int ac, char **av)
{
	if (ac != 5 || !av)
		exit(EXIT_FAILURE);
}

void	free_double(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}