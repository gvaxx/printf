/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaptain <mcaptain@msk-school21.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 18:03:39 by mcaptain          #+#    #+#             */
/*   Updated: 2020/05/25 16:04:11 by mcaptain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_num_len(long long n, int base)
{
	int i;

	i = 1;
	if (n < 0)
		i++;
	while (n / base)
	{
		i++;
		n = n / base;
	}
	return (i);
}

static char	*sixteen(long long n, int base)
{
	size_t			len;
	char			*number;
	unsigned long	i;
	int				c;

	i = n;
	len = ft_num_len(i, base);
	number = malloc(sizeof(char) * (len + 1));
	if (!number)
		return (0);
	number[len--] = '\0';
	if (n == 0)
		number[0] = '0';
	else
		number[0] = '-';
	while (i != 0)
	{
		c = i % base;
		if (c > 9)
			c += 7;
		number[len--] = c + 48;
		i = i / base;
	}
	return (number);
}

char		*ft_ltoa_base(long long n, int base)
{
	size_t		len;
	char		*number;
	int			c;

	if (base == 16)
		return (sixteen(n, base));
	len = ft_num_len(n, base);
	if (!(number = malloc(sizeof(char) * (len + 1))))
		return (0);
	number[len--] = '\0';
	if (n == 0)
		number[0] = '0';
	else
		number[0] = '-';
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		c = n % base;
		c > 9 ? c += 7 : c;
		number[len--] = c + 48;
		n = n / base;
	}
	return (number);
}
