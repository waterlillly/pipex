/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:24:17 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/07/22 15:19:33 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static char	*ft_rest(int x, char *buf)
{
	char	*temp;
	int		y;

	if (!buf)
		return (NULL);
	y = 0;
	while (buf[x + y])
		y++;
	if (y == 0)
		return (free(buf), NULL);
	temp = malloc(sizeof(char) * (y + 1));
	if (!temp)
		return (free(buf), NULL);
	temp[y] = '\0';
	y = 0;
	while (buf[x + y])
	{
		temp[y] = buf[x + y];
		y++;
	}
	return (free(buf), temp);
}

static char	*ft_buf(char *buf, int *x)
{
	char	*line;
	int		j;

	if (!buf)
		return (NULL);
	*x = 0;
	while (buf[*x] && buf[*x] != '\n')
		(*x)++;
	if (buf[*x] == '\n')
		(*x)++;
	if (*x == 0)
		return (NULL);
	line = malloc(sizeof(char) * (*x + 1));
	if (!line)
		return (NULL);
	line[*x] = '\0';
	j = -1;
	while (++j < *x)
		line[j] = buf[j];
	return (line);
}

static char	*ft_next(char *buf, int fd)
{
	int		bytes;
	char	*temp;
	char	*new_buf;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (free(buf), NULL);
	while (ft_strchr(buf, '\n') == 0)
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes < 0)
			return (free(buf), free(temp), NULL);
		else if (bytes == 0)
			break ;
		temp[bytes] = '\0';
		new_buf = ft_strjoin(buf, temp);
		if (!new_buf)
			return (free(buf), free(temp), NULL);
		free(buf);
		buf = new_buf;
	}
	return (free(temp), buf);
}

char	*get_next_line(int fd)
{
	static char	*buf[1024];	
	char		*next;
	int			x;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (NULL);
	if (!buf[fd])
	{
		buf[fd] = ft_strdup("");
		if (!buf[fd])
			return (NULL);
	}
	buf[fd] = ft_next(buf[fd], fd);
	if (!buf[fd])
		return (NULL);
	next = ft_buf(buf[fd], &x);
	if (!next)
		return (free(buf[fd]), buf[fd] = NULL, NULL);
	buf[fd] = ft_rest(x, buf[fd]);
	return (next);
}

// #include <fcntl.h>

// int	main(void)
// {
// 	int	fd = open("fileA", O_RDONLY);
// 	int	fd1 = open("fileB", O_RDONLY);
// 	char	*str = get_next_line(fd);

// 	while (str)
// 	{
// 		printf("%s", str);
// 		free(str);
// 		str = NULL;
// 		str = get_next_line(fd1);
// 		printf("%s", str);
// 		free(str);
// 		str = NULL;
// 		str = get_next_line(fd);
// 	}
// 	free(str);
// 	return (0);
// }
