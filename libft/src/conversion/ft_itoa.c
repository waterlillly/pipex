/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:46:12 by lbaumeis          #+#    #+#             */
/*   Updated: 2025/02/03 14:38:13 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	ft_nbrlen(int nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
	{
		len++;
		nbr *= (-1);
	}
	while (nbr > 0)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}

static int	ft_times_ten(int len)
{
	int	tim;

	tim = 1;
	if (len == 1)
		return (1);
	while (len > 1)
	{
		tim *= 10;
		len--;
	}
	return (tim);
}

static char	*ft_extra(void)
{
	char	*ret;

	ret = ft_strdup("-2147483648");
	if (!ret)
		return (NULL);
	return (ret);
}

static char	*ft_resultoa(int n, int len, int backup, char *result)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= (-1);
		result[i] = '-';
		i++;
		len--;
	}
	while (i < backup)
	{
		result[i] = ((n / ft_times_ten(len)) % 10 + 48);
		i++;
		len--;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_itoa(int n)
{
	int		len;
	int		backup;
	char	*result;

	if (n == -2147483648)
		return (ft_extra());
	len = ft_nbrlen(n);
	backup = len;
	result = malloc(sizeof(char) * len + 1);
	if (!result)
		return (0);
	return (ft_resultoa(n, len, backup, result));
}
