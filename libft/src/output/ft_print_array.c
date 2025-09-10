/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 19:40:16 by lbaumeis          #+#    #+#             */
/*   Updated: 2025/02/03 14:38:13 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_print_array(char **arr)
{
	int	x;

	x = -1;
	while (arr[++x])
		ft_putendl_fd(arr[x], 1);
}

// void	ft_print_array(char **arr)
// {
// 	int	x;

// 	x = 0;
// 	while (arr[x])
// 	{
// 		printf("|%s|\n", arr[x]);
// 		x++;
// 	}
// }