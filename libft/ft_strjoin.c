/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 04:09:55 by lbaumeis          #+#    #+#             */
/*   Updated: 2023/10/14 10:19:45 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total;
	size_t	i;
	size_t	j;
	char	*strnew;

	i = 0;
	j = 0;
	total = ft_strlen(s1) + ft_strlen(s2) + 1;
	strnew = (char *)malloc(sizeof(char) * total);
	if (!strnew)
		return (NULL);
	while (s1[i] != '\0')
	{
		strnew[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		strnew[i] = s2[j];
		j++;
		i++;
	}
	strnew[i] = '\0';
	return (strnew);
}
