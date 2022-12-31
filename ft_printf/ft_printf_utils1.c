/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:38:59 by orakib            #+#    #+#             */
/*   Updated: 2022/11/07 17:48:51 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return (write(fd, "(null)", 6));
	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
	return (i);
}

int	ft_putnbr_fd(int n, int fd)
{
	int	i;

	i = 0;
	if (n == -2147483647 -1)
	{
		i += ft_putchar_fd('-', fd);
		i += ft_putchar_fd('2', fd);
		i += ft_putnbr_fd(147483648, fd);
	}
	else if (n < 0)
	{
		n *= -1;
		i += write(fd, "-", sizeof(char));
		i += ft_putnbr_fd(n, fd);
	}
	else if (n < 10)
	{
		i += ft_putchar_fd(n + '0', fd);
	}
	else if (n >= 10)
	{
		i += ft_putnbr_fd(n / 10, fd);
		i += ft_putnbr_fd(n % 10, fd);
	}
	return (i);
}

int	ft_puthex_fd(unsigned int n, int fd)
{
	char	*x;
	int		i;

	i = 0;
	x = "0123456789abcdef";
	if (n >= 16)
	{
		i += ft_puthex_fd(n / 16, fd);
		i += ft_puthex_fd(n % 16, fd);
	}
	else if (n < 16)
	{
		i += ft_putchar_fd(*(x + n), fd);
	}
	return (i);
}

int	ft_puthexu_fd(unsigned int n, int fd)
{
	char	*x;
	int		i;

	i = 0;
	x = "0123456789ABCDEF";
	if (n >= 16)
	{
		i += ft_puthexu_fd(n / 16, fd);
		i += ft_puthexu_fd(n % 16, fd);
	}
	else if (n < 16)
	{
		i += ft_putchar_fd(*(x + n), fd);
	}
	return (i);
}
