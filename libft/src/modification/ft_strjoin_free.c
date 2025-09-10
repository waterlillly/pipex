/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:53:09 by lbaumeis          #+#    #+#             */
/*   Updated: 2025/02/03 14:38:13 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

// not norminette compliant
// to_free: 'a' = free strA, 'b' = free strB, 'c' = free both, any other = free none

char	*ft_strjoin_free(char *strA, char *strB, const char to_free)
{
	int		i;
	int		j;
	char	*new;

	if (!strA && !strB)
		return (NULL);
	if (!strA)
	{
		new = ft_strdup(strB);
		if (to_free == 'b' || to_free == 'c')
			free(strB);
		return (new);
	}
	if (!strB)
	{
		new = ft_strdup(strA);
		if (to_free == 'a' || to_free == 'c')
			free(strA);
		return (new);
	}
	new = malloc(sizeof(char) * (ft_strlen(strA) + ft_strlen(strB) + 1));
	if (!new)
	{
		if (to_free == 'a' || to_free == 'c')
			free(strA);
		if (to_free == 'b' || to_free == 'c')
			free(strB);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (strA[i])
	{
		new[i] = strA[i];
		i++;
	}
	while (strB[j])
		new[i++] = strB[j++];
	new[i] = '\0';
	if (to_free == 'a' || to_free == 'c')
		free(strA);
	if (to_free == 'b' || to_free == 'c')
		free(strB);
	return (new);
}
