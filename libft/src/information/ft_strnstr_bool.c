/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_bool.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:31:22 by lbaumeis          #+#    #+#             */
/*   Updated: 2025/02/03 14:38:12 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

bool	ft_strnstr_bool(const char *big, const char *lil, int start, int len)
{
	int	x;

	if (!big || len == 0 || lil[0] == '\0')
		return (false);
	x = -1;
	while (big[start] && lil[++x] && x < len && big[start] == lil[x])
		start++;
	if (x == len && big[start - 1] == lil[x - 1] && lil[x] == '\0')
		return (true);
	return (false);
}
