/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:40:01 by lbaumeis          #+#    #+#             */
/*   Updated: 2025/02/03 14:38:13 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	int		x;
	char	*new;

	if (!s)
		return (NULL);
	x = 0;
	len = ft_strlen(s);
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	while (s[x])
	{
		new[x] = s[x];
		x++;
	}
	new[x] = '\0';
	return (new);
}
