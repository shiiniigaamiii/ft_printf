/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmusay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:29:08 by marmusay          #+#    #+#             */
/*   Updated: 2023/02/28 20:46:52 by marmusay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	ft_checktype(va_list temp, char type)
{
	int	count;

	count = 0;
	if (type == 'c')
		count += ft_printchar(va_arg(temp, int));
	else if (type == 's')
		count += ft_putstr(va_arg(temp, char *));
/*	else if (type == 'p')
	{
		write (1, "0x", 2);
		count += ft_printhex(va_arg(temp, unsigned long), 'x') + 2;
	}*/
	else if (type == 'd' || type == 'i')
		count += ft_putnbr(va_arg(temp, int));
	else if (type == 'u')
		count += ft_putunsigned(va_arg(temp, unsigned int), 0);
	else if (type == 'x' || type == 'X' || type == 'p')
	{
		if(type == 'x' || type == 'X')
			count += ft_printhex(va_arg(temp, unsigned long long), type);
		else
		{
			write (1, "0x", 2);
			count += (ft_printhex(va_arg(temp, unsigned long long), 'x') + 2);
		}
	}
	else if (type == '%')
	{
		write(1, "%", 1);
		count += 1;
	}
	return (count);
}

int	ft_printf(const char *f, ...)
{
	int		count;
	int		i;
	va_list	temp;

	va_start(temp, f);
	i = 0;
	count = 0;
	while (f[i])
	{
		if (f[i] != '%')
			count += ft_printchar(f[i]);
		else if (f[i] == '%')
		{
			count += ft_checktype(temp, f[i + 1]);
			i++;
		}
		i++;
	}
	va_end(temp);
	return (count);
}

/*int main()
{
	ft_printf(" %x ", LONG_MIN);
}*/