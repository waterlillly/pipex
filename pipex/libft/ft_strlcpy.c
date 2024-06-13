/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:40:17 by lbaumeis          #+#    #+#             */
/*   Updated: 2023/10/14 10:23:42 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	s;

	srclen = ft_strlen(src);
	s = 0;
	if (size == 0)
		return (srclen);
	while (src[s] != '\0' && s < size - 1)
	{
		dst[s] = src[s];
		s++;
	}
	dst[s] = '\0';
	return (srclen);
}
