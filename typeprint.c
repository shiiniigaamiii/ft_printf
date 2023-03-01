/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeprint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmusay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:03:03 by marmusay          #+#    #+#             */
/*   Updated: 2023/02/28 18:35:42 by marmusay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *ch)
{
	int	i;

	i = 0;
	if (ch)
	{
		while (ch[i])
		{
			write(1, &ch[i], 1);
			i++;
		}
	}
	else
	{
		write(1, "(null)", 6);
		return (6);
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	int		save;
	char	c;

	save = 0;
	if (nb == -2147483648)
		return (save += ft_putstr("-2147483648"));
	else if (nb < 0)
	{
		save += ft_printchar('-');
		save += ft_putnbr(-nb);
	}
	else if (nb < 10)
	{
		c = nb + '0';
		save += ft_printchar(c);
	}
	else if (nb > 9)
	{
		save += ft_putnbr(nb / 10);
		c = (nb % 10) + '0';
		save += ft_printchar(c);
	}
	return (save);
}

int	ft_putunsigned(unsigned int nb, int save)
{
	char	c;

	if (nb < 10)
	{
		c = nb + '0';
		save += ft_printchar(c);
	}
	else if (nb > 9)
	{
		save += ft_putunsigned(nb / 10, save);
		c = (nb % 10) + '0';
		save += ft_printchar(c);
	}
	return (save);
}

int	ft_printhex(unsigned long a, char format)
{
	int		save;
	char	*b;
	int		i;
	char	f[16];

	b = "0123456789abcdef";
	i = 0;
	save = 0;
	if (a == 0)
		return (ft_printchar('0'));
	while (a != 0)
	{
		f[i++] = b[a % 16];
		a /= 16;
	}
	save = i;
	while (save--)
	{
		if (format == 'X' && (f[save] >= 'a' && f[save] <= 'z'))
			f[save] -= 32;
		write (1, &f[save], 1);
	}
	return (i);
}

/*int	ft_printptr(unsigned long a)
{
	int		save;
	char	*b;
	int		i;
	char	f[20];

	b = "0123456789abcdef";
	i = 0;
	if (a == 0)
		return (ft_printchar('0'));
	while (a != 0)
	{
		f[i++] = b[a % 16];
		a /= 16;
	}
	save = i;
	write(1, "0x", 2);
	while (save--)
		write (1, &f[save], 1);
	return (i + 2);
}*/
