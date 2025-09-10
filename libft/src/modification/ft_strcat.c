/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:05:04 by lbaumeis          #+#    #+#             */
/*   Updated: 2025/02/03 14:38:12 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strcat(char *dst, char *src)
{
	int		len_a;
	int		len_b;
	char	*tmp;

	if (!src || !dst)
		return (NULL);
	len_a = ft_strlen(dst);
	len_b = ft_strlen(src);
	tmp = dst;
	dst = ft_calloc(len_a + len_b + 1, 1);
	if (!dst)
		return (NULL);
	if (tmp)
		ft_strlcat(dst, tmp, len_a + 1);
	ft_strlcat(dst, src, len_b + len_a + 1);
	free(tmp);
	return (dst);
}
