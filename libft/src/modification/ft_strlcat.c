/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:40:09 by lbaumeis          #+#    #+#             */
/*   Updated: 2025/02/03 14:38:13 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	x;
	size_t	y;
	size_t	z;

	x = 0;
	if (!dst)
		return (0);
	y = ft_strlen(dst);
	z = ft_strlen(src);
	if (y >= size || size == 0)
		return (z + size);
	while (src[x] && (x + y) < (size - 1))
	{
		dst[y + x] = src[x];
		x++;
	}
	dst[y + x] = '\0';
	return (y + z);
}
