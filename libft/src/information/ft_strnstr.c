/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:40:47 by lbaumeis          #+#    #+#             */
/*   Updated: 2025/02/03 14:38:13 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	x;
	size_t	y;

	if (len == 0)
		return (NULL);
	if (little[0] == '\0')
		return ((char *)big);
	x = 0;
	while (big[x] && x < len)
	{
		y = 0;
		while (big[x + y] && big[x + y] == little[y] && (x + y) < len)
			y++;
		if (!little[y])
			return ((char *)&big[x]);
		x++;
	}
	return (NULL);
}
