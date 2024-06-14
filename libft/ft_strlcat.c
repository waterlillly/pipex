/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:40:09 by lbaumeis          #+#    #+#             */
/*   Updated: 2023/10/14 10:23:57 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	x;
	size_t	y;
	size_t	z;

	x = 0;
	y = ft_strlen(dst);
	z = ft_strlen(src);
	if (y >= size || size == 0)
		return (z + size);
	while (src[x] != '\0' && (x + y) < size - 1)
	{
		dst[y + x] = src[x];
		x++;
	}
	dst[y + x] = '\0';
	return (y + z);
}
