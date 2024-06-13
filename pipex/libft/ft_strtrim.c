/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:16:47 by lbaumeis          #+#    #+#             */
/*   Updated: 2023/10/14 10:34:58 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	len;
	char	*new;

	i = 0;
	len = ft_strlen(s1) - 1;
	while (s1 && ft_strchr(set, s1[i]))
		i++;
	if (!(ft_strchr(set, s1[i])))
		start = i;
	while (s1 && ft_strrchr(set, s1[len]))
		len--;
	if (!(ft_strrchr(set, s1[len])))
	{
		new = ft_substr(s1, start, (len - i + 1));
		if (!new)
			return (NULL);
		return (new);
	}
	return (NULL);
}
