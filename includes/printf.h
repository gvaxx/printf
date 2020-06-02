/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaptain <mcaptain@msk-school21.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 10:34:27 by mcaptain          #+#    #+#             */
/*   Updated: 2020/05/25 17:02:02 by mcaptain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef	struct	s_format
{
	int		flag;
	int		flag_flag;
	int		width;
	int		width_flag;
	int		accuracy;
	int		accuracy_flag;
	int		size;
	int		size_flag;
	char	type;
	char	type_flag;
	char	filler;
}				t_fmt;

int				i_handler(t_fmt *modificators, char *temp);
int				p_handler(t_fmt *modificators, char *temp);
int				s_handler(t_fmt *modificators, char *temp);
int				c_handler(t_fmt *modificators, char temp);
int				ft_printf(const char *format, ...);
void			print_space(int num);
void			print_zero(int num);
void			print_right_zero_p(int num);
void			print_right_space_p(int num);
int				fill(t_fmt *modificators, const char *format, va_list argptr);
char			*ft_itoa(int n);
char			*ft_strdup(const char *s);
size_t			ft_strlen(const char *s);
char			*ft_ltoa_base(long long n, int base);
char			*ft_tolower_str(char *str);
int				ft_tolower(int c);
int				ft_isdigit(int c);
int				ft_atoi(const char *nptr);
void			ft_putstr_fd(char *s, int fd);
void			ft_putchar_fd(char c, int fd);

#endif
