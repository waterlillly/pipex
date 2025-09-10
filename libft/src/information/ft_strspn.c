/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:29:19 by lbaumeis          #+#    #+#             */
/*   Updated: 2025/02/03 14:38:13 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	i;
	size_t	j;
	int		found;

	i = -1;
	while (s[++i])
	{
		j = -1;
		found = 0;
		while (accept[++j])
		{
			if (s[i] == accept[j])
			{
				found = 1;
				break ;
			}
		}
		if (!found)
			break ;
	}
	return (i);
}

/*
int main() {
	const char *str = "abcde12345";
	const char *accept = "abcde";

	size_t result = ft_strspn(str, accept);
	size_t expected = strspn(str, accept);
	printf("Length of initial segment matching '%s': %zu (expected: %zu)\n", accept, result, expected);

	return 0;
}
*/