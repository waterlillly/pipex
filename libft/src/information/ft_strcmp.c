/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:28:17 by lbaumeis          #+#    #+#             */
/*   Updated: 2025/02/03 14:38:13 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	x;

	x = 0;
	while (s1[x] && s2[x] && s1[x] == s2[x])
		x++;
	return ((unsigned char)s1[x] - (unsigned char)s2[x]);
}

/*
int main() {
	const char *str1 = "Hellooo";
	const char *str2 = "Hello";
	const char *str3 = "World";
	const char *str4 = "Hell Wor";

	printf("Comparing '%s' and '%s': %d\n", str1, str2, ft_strcmp(str1, str2));
	printf("Checking '%s' and '%s': %d\n", str1, str2, strcmp(str1, str2));
	printf("Comparing '%s' and '%s': %d\n", str1, str3, ft_strcmp(str1, str3));
	printf("Checking '%s' and '%s': %d\n", str1, str3, strcmp(str1, str3));
	printf("Comparing '%s' and '%s': %d\n", str1, str4, ft_strcmp(str1, str4));
	printf("Checking '%s' and '%s': %d\n", str1, str4, strcmp(str1, str4));

	return 0;
}
*/