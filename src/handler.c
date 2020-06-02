/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaptain <mcaptain@msk-school21.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 12:07:15 by mcaptain          #+#    #+#             */
/*   Updated: 2020/05/25 16:59:51 by mcaptain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	i_print(t_fmt *modificators, char *temp, int num)
{
	if (modificators->flag != 2)
	{
		if (modificators->filler == '0' && modificators->accuracy_flag == 0)
		{
			if (*temp == '-')
				ft_putchar_fd(*temp++, 1);
			print_zero(modificators->width - num);
		}
		else
			print_space(modificators->width - num);
	}
	write(1, temp, num);
	if (modificators->flag == 2)
		print_space(modificators->width - num);
}

static void	zr_accry_hlp(char *temp, char *str, int zero)
{
	while (*temp)
	{
		if (*temp == '-')
			*str++ = *temp++;
		if (zero)
		{
			zero--;
			*str++ = '0';
		}
		else
			*str++ = *temp++;
	}
	*str = '\0';
}

static char	*zero_accuracy(char *temp, int num, t_fmt *modificators)
{
	int		zero;
	char	*str;

	*temp == '-' ? num-- : num;
	if (num < modificators->accuracy)
	{
		zero = modificators->accuracy - num;
		if (!(str = malloc((ft_strlen(temp) + zero) * sizeof(char))))
			return (0);
		zr_accry_hlp(temp, str, zero);
		free(temp);
		return (str);
	}
	return (temp);
}

int			i_handler(t_fmt *modificators, char *temp)
{
	int num;

	num = ft_strlen(temp);
	if (num == 1 && *temp == '0' && modificators->accuracy_flag
	&& modificators->accuracy == 0)
		num = 0;
	if (modificators->accuracy_flag && modificators->accuracy != 0)
	{
		temp = zero_accuracy(temp, num, modificators);
		num = ft_strlen(temp);
	}
	if (num < modificators->width)
	{
		i_print(modificators, temp, num);
		free(temp);
		return (modificators->width);
	}
	write(1, temp, num);
	free(temp);
	return (num);
}
