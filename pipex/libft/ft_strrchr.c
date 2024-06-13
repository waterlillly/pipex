/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:41:03 by lbaumeis          #+#    #+#             */
/*   Updated: 2023/10/14 14:03:04 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*str;
	char	find;

	i = ft_strlen(s);
	str = (char *)s;
	find = (char)c;
	while (i > 0)
	{
		if (c == '\0')
			return (&str[i]);
		if (str[i] == find)
			return (&str[i]);
		else
			i--;
	}
	if (str[0] == find)
		return (&str[i]);
	return (NULL);
}
