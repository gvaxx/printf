/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaptain <mcaptain@msk-school21.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 19:57:33 by mcaptain          #+#    #+#             */
/*   Updated: 2020/05/25 21:31:22 by mcaptain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	zero(t_fmt *modificators)
{
	modificators->flag = 0;
	modificators->flag_flag = 0;
	modificators->width = 0;
	modificators->width_flag = 0;
	modificators->accuracy = 0;
	modificators->accuracy_flag = 0;
	modificators->size = 0;
	modificators->size_flag = 0;
	modificators->type = 0;
	modificators->type_flag = 0;
	modificators->filler = ' ';
}

static char	*n_f(int type, va_list argptr)
{
	char *str;

	if (type == 'i' || type == 'd')
		return (ft_ltoa_base(va_arg(argptr, int), 10));
	if (type == 'X' || type == 'x' || type == 'p')
	{
		if (type == 'x' || type == 'p')
		{
			str = ft_ltoa_base(va_arg(argptr, unsigned long), 16);
			return (ft_tolower_str(str));
		}
		return (ft_ltoa_base(va_arg(argptr, unsigned int), 16));
	}
	if (type == 'o')
		return (ft_ltoa_base(va_arg(argptr, long long), 8));
	if (type == 'u')
		return (ft_ltoa_base(va_arg(argptr, unsigned), 10));
	return (0);
}

static int	choose_type(t_fmt modificators, va_list argptr)
{
	if (modificators.type == 'i' || modificators.type == 'd')
		return (i_handler(&modificators, n_f(modificators.type, argptr)));
	if (modificators.type == 'x')
		return (i_handler(&modificators, n_f(modificators.type, argptr)));
	if (modificators.type == 'X')
		return (i_handler(&modificators, n_f(modificators.type, argptr)));
	if (modificators.type == 'o')
		return (i_handler(&modificators, n_f(modificators.type, argptr)));
	if (modificators.type == 's')
		return (s_handler(&modificators, va_arg(argptr, char *)));
	if (modificators.type == 'c')
		return (c_handler(&modificators, va_arg(argptr, int)));
	if (modificators.type == 'p')
		return (p_handler(&modificators, n_f(modificators.type, argptr)));
	if (modificators.type == 'u')
		return (i_handler(&modificators, n_f(modificators.type, argptr)));
	return (0);
}

static int	manager(const char *format, int *i, va_list argptr)
{
	int		i2;
	t_fmt	modificators;

	i2 = *i;
	i2++;
	zero(&modificators);
	if (format[i2] == '%')
	{
		ft_putchar_fd('%', 1);
		*i = i2 + 1;
		return (1);
	}
	i2 = i2 + fill(&modificators, &format[i2], argptr);
	*i = i2 + 1;
	return (choose_type(modificators, argptr));
}

int			ft_printf(const char *format, ...)
{
	int		i;
	int		num;
	va_list argptr;

	num = 0;
	i = 0;
	va_start(argptr, format);
	while (format[i])
	{
		if (format[i] == '%')
			num += manager(format, &i, argptr);
		else
		{
			ft_putchar_fd(format[i++], 1);
			num++;
		}
	}
	va_end(argptr);
	return (num);
}
