/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:39:22 by lbaumeis          #+#    #+#             */
/*   Updated: 2023/10/14 10:03:29 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_revmem(void *dest, const void *src, size_t n)
{
	int			i;
	const char	*csrc;
	char		*cdest;

	i = (int)n - 1;
	csrc = (const char *)src;
	cdest = (char *)dest;
	while (i >= 0)
	{
		cdest[i] = csrc[i];
		i--;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (!dest && !src && n != 0)
		return (NULL);
	if (src > dest)
		ft_memcpy(dest, src, n);
	else
		ft_revmem(dest, src, n);
	return (dest);
}
