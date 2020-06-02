/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaptain <mcaptain@msk-school21.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 01:53:39 by mcaptain          #+#    #+#             */
/*   Updated: 2020/05/25 16:02:26 by mcaptain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	toint(int sign, const char *s)
{
	long	num;
	long	max;

	num = 0;
	while (*s <= '9' && *s >= '0')
	{
		max = num;
		num = 10 * num + (*s - 48);
		if (num / 10 != max)
		{
			if (sign == 1)
				return (-1);
			return (0);
		}
		s++;
	}
	return (int)(num * sign);
}

int			ft_atoi(const char *nptr)
{
	const char	*s;
	int			sign;

	s = nptr;
	sign = 1;
	while (*s == ' ' || *s == '\t' || *s == '\n' || *s == '\f'
	|| *s == '\v' || *s == '\r')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	return (toint(sign, s));
}
