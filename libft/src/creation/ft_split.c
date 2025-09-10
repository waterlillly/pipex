/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:17:03 by lbaumeis          #+#    #+#             */
/*   Updated: 2025/02/03 14:38:13 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	ft_countstrs(char const *s, char c)
{
	int	counter;

	counter = 0;
	if (!s)
		return (0);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			counter++;
		while (*s && *s != c)
			s++;
	}
	return (counter);
}

static int	ft_place(char const *s, char c, int last_pos)
{
	while (s[last_pos] != '\0' && s[last_pos] != c)
		last_pos++;
	return (last_pos);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		x;
	int		amount;
	int		last_pos;

	last_pos = 0;
	if (!s)
		return (NULL);
	amount = ft_countstrs(s, c);
	result = malloc((amount + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	x = -1;
	while (++x < amount)
	{
		while (s && s[last_pos] && s[last_pos] == c)
			last_pos++;
		result[x] = ft_substr(s, last_pos, ft_place(s, c, last_pos) - last_pos);
		if (!result[x])
			return (ft_free_double(result), NULL);
		last_pos = ft_place(s, c, last_pos + 1);
	}
	result[x] = NULL;
	return (result);
}

/*
int main() {
	char *str = "      abc 652318        9eqvjrn32ubvg89897  v89v   |  ";
	char c = ' ';
	char **split = ft_split(str, c);
	if (!split)
		write(2, "WRONG\n", 6);
	else
		ft_print_array(split);
	ft_free_double(split);
	return 0;
}
*/