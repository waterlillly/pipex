/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:00:02 by lbaumeis          #+#    #+#             */
/*   Updated: 2025/02/03 14:38:13 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static long	ft_nbrlen_long(long nbr)
{
	long	len;

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

static long	ft_times_ten_long(long len)
{
	long	tim;

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

static char	*ft_extra_long(void)
{
	char	*ret;

	ret = ft_strdup("-2147483648");
	if (!ret)
		return (NULL);
	return (ret);
}

static char	*ft_resultoa_long(long n, long len, long backup, char *result)
{
	long	i;

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
		result[i] = ((n / ft_times_ten_long(len)) % 10 + 48);
		i++;
		len--;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_itoa_long(long n)
{
	long	len;
	long	backup;
	char	*result;

	if (n == -2147483648)
		return (ft_extra_long());
	len = ft_nbrlen_long(n);
	backup = len;
	result = malloc(sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	return (ft_resultoa_long(n, len, backup, result));
}
