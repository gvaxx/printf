/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaptain <mcaptain@msk-school21.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 23:55:22 by mcaptain          #+#    #+#             */
/*   Updated: 2020/05/25 17:02:54 by mcaptain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_space(int num)
{
	while (num--)
		ft_putchar_fd(' ', 1);
}

void	print_zero(int num)
{
	while (num--)
		ft_putchar_fd('0', 1);
}

void	print_right_zero_p(int num)
{
	ft_putstr_fd("0x", 1);
	while (num--)
		ft_putchar_fd('0', 1);
}

void	print_right_space_p(int num)
{
	while (num--)
		ft_putchar_fd(' ', 1);
	ft_putstr_fd("0x", 1);
}
