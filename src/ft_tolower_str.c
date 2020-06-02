/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaptain <mcaptain@msk-school21.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 01:52:05 by mcaptain          #+#    #+#             */
/*   Updated: 2020/05/25 16:06:00 by mcaptain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_tolower_str(char *str)
{
	char *s;

	s = str;
	while (*s)
	{
		*s = ft_tolower(*s);
		s++;
	}
	return (str);
}
