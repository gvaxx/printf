/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaptain <mcaptain@msk-school21.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 23:52:44 by mcaptain          #+#    #+#             */
/*   Updated: 2020/05/25 17:55:50 by mcaptain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	pointer_print(char *temp)
{
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(temp, 1);
}

int			p_handler(t_fmt *modificators, char *temp)
{
	int num;

	num = ft_strlen(temp) + 2;
	if (num < modificators->width)
	{
		if (modificators->flag != 2)
		{
			if (modificators->filler == '0')
				print_right_zero_p(modificators->width - num);
			else
				print_right_space_p(modificators->width - num);
			ft_putstr_fd(temp, 1);
		}
		else
		{
			pointer_print(temp);
			print_space(modificators->width - num);
		}
		free(temp);
		return (modificators->width);
	}
	pointer_print(temp);
	free(temp);
	return (num);
}

static int	null_s_hanlder(t_fmt *modificators, int num)
{
	char *temp;

	temp = ft_strdup("(null)");
	if (modificators->accuracy_flag)
		num = (num > modificators->accuracy ? modificators->accuracy : num);
	if (num < modificators->width)
	{
		if (modificators->flag != 2)
			print_space(modificators->width - num);
		write(1, temp, num);
		if (modificators->flag == 2)
			print_space(modificators->width - num);
		free(temp);
		return (modificators->width);
	}
	write(1, temp, num);
	free(temp);
	return (num);
}

int			s_handler(t_fmt *modificators, char *temp)
{
	int num;

	if (temp == NULL)
		return (null_s_hanlder(modificators, 6));
	num = ft_strlen(temp);
	if (modificators->accuracy_flag)
		num = (num > modificators->accuracy ? modificators->accuracy : num);
	if (num < modificators->width)
	{
		if (modificators->flag != 2)
			print_space(modificators->width - num);
		write(1, temp, num);
		if (modificators->flag == 2)
			print_space(modificators->width - num);
		return (modificators->width);
	}
	write(1, temp, num);
	return (num);
}

int			c_handler(t_fmt *modificators, char temp)
{
	if (1 < modificators->width)
	{
		if (modificators->flag != 2)
			print_space(modificators->width - 1);
		ft_putchar_fd(temp, 1);
		if (modificators->flag == 2)
			print_space(modificators->width - 1);
		return (modificators->width);
	}
	ft_putchar_fd(temp, 1);
	return (1);
}
