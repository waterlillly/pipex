/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:40:47 by lbaumeis          #+#    #+#             */
/*   Updated: 2023/10/14 10:29:53 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*b;
	char	*l;
	size_t	x;
	size_t	y;

	b = (char *)big;
	l = (char *)little;
	if (l[0] == '\0')
		return (b);
	if (len == 0)
		return (0);
	x = 0;
	while (b[x] && x < len)
	{
		y = 0;
		while (b[x + y] && b[x + y] == l[y] && (x + y) < len)
		{
			if (l[y + 1] == '\0')
				return (&b[x]);
			y++;
		}
		x++;
	}
	return (NULL);
}
