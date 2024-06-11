/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:57:31 by lbaumeis          #+#    #+#             */
/*   Updated: 2023/10/14 10:25:52 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	x;
	char			*z;
	char			*str;

	x = 0;
	str = (char *)s;
	z = (char *)malloc(sizeof(char) * ((ft_strlen(s) + 1)));
	if (!z)
		return (NULL);
	while (str[x] != '\0')
	{
		z[x] = f(x, str[x]);
		x++;
	}
	z[x] = '\0';
	return (z);
}
