/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaptain <mcaptain@msk-school21.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 15:04:54 by mcaptain          #+#    #+#             */
/*   Updated: 2020/05/25 16:57:01 by mcaptain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static const char	*flag(t_fmt *mdfs, const char *str)
{
	if (*str == '-')
		mdfs->flag = 2;
	else if (*str == '0' && mdfs->flag != 2)
		mdfs->flag = 1;
	mdfs->flag_flag = 1;
	return (str + 1);
}

static const char	*digit(t_fmt *mdfs, const char *str, int n)
{
	if (n)
		mdfs->accuracy = ft_atoi(str);
	else
		mdfs->width = ft_atoi(str);
	while (ft_isdigit(*str))
		str++;
	return (str);
}

static const char	*width(t_fmt *mdfs, const char *str, va_list argptr)
{
	if (*str == '*')
	{
		str++;
		mdfs->width = va_arg(argptr, int);
	}
	else
		str = digit(mdfs, str, 0);
	mdfs->width_flag = 1;
	return (str);
}

static const char	*accuracy(t_fmt *mdfs, const char *str, va_list argptr)
{
	if (*(str + 1) == '*')
	{
		str = str + 2;
		mdfs->accuracy = va_arg(argptr, unsigned);
	}
	else
		str = digit(mdfs, str + 1, 1);
	mdfs->accuracy_flag = 1;
	return (str);
}

int					fill(t_fmt *mdfs, const char *format, va_list argptr)
{
	const char *str;

	str = format;
	while (*str == '-' || *str == '0')
		str = flag(mdfs, str);
	if (mdfs->flag == 1)
		mdfs->filler = '0';
	if (ft_isdigit(*str) || *str == '*')
		str = width(mdfs, str, argptr);
	if (*str == '.')
		str = accuracy(mdfs, str, argptr);
	if (mdfs->accuracy < 0)
		mdfs->accuracy_flag = 0;
	if (mdfs->width < 0)
	{
		mdfs->flag = 2;
		mdfs->width = -mdfs->width;
	}
	mdfs->type = *str;
	return (str - format);
}
