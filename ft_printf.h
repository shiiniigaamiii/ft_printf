/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmusay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:06:17 by marmusay          #+#    #+#             */
/*   Updated: 2023/03/01 11:51:00 by marmusay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int				ft_printf(const char *f, ...);
int				ft_checktype(va_list temp, char a);
int				ft_printchar(int c);
int				ft_putstr(char *ch);
int				ft_putnbr(int nb);
int				ft_putunsigned(unsigned int nb, int save);
int				ft_printptr(unsigned long a);
int				ft_printhex(unsigned long a, char format);
//for testing
int	print_hex(unsigned long long n, char i);
int    ft_print_hexu(unsigned long long int n, char format);

#endif
