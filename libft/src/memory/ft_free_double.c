/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 17:00:57 by lbaumeis          #+#    #+#             */
/*   Updated: 2025/02/03 14:38:12 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_free_double(char **smth)
{
	int	x;

	x = 0;
	while (smth && smth[x])
	{
		free(smth[x]);
		x++;
	}
	if (smth)
		free(smth);
}
