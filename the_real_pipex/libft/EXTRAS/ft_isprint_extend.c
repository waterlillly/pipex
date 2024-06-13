/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:48:32 by lbaumeis          #+#    #+#             */
/*   Updated: 2023/09/06 16:58:21 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint_extend(int n)
{
	if (n >= 32 && n <= 126)
		return (1);
	else if (n >= 128 && <= 255)
		return (1);
	else
		return (0);
}
/*
int	main(void)
{
	ft_isprint(55);
	ft_isprint(127);
	return (0);
}
*/
