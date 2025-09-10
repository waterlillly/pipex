/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_bool.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:55:27 by lbaumeis          #+#    #+#             */
/*   Updated: 2025/02/03 14:38:12 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

bool	ft_strcmp_bool(const char *s1, const char *s2)
{
	size_t	x;

	x = 0;
	if (!s1 || !s2)
		return (false);
	if (ft_strlen(s1) != ft_strlen(s2))
		return (false);
	while (s1[x] && s2[x] && s1[x] == s2[x])
		x++;
	if (x == ft_strlen(s1))
		return (true);
	return (false);
}
