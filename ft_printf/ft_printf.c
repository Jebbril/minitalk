/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:38:57 by orakib            #+#    #+#             */
/*   Updated: 2022/11/08 11:52:05 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_write(va_list ptr, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_putchar_fd(va_arg(ptr, int), 1);
	else if (format == 'd' || format == 'i')
		len += ft_putnbr_fd(va_arg(ptr, int), 1);
	else if (format == 's')
		len += ft_putstr_fd(va_arg(ptr, char *), 1);
	else if (format == '%')
		len += ft_putchar_fd('%', 1);
	else if (format == 'u')
		len += ft_putunbr_fd(va_arg(ptr, unsigned int), 1);
	else if (format == 'x')
		len += ft_puthex_fd(va_arg(ptr, long), 1);
	else if (format == 'X')
		len += ft_puthexu_fd(va_arg(ptr, long), 1);
	else if (format == 'p')
	{
		write (1, "0x", 2);
		len += 2;
		len += ft_putadr_fd(va_arg(ptr, uintptr_t), 1);
	}
	return (len);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		len;
	va_list	ptr;

	i = 0;
	len = 0;
	va_start(ptr, s);
	while (s[i])
	{
		if (s[i] == '%')
			len += ft_write(ptr, s[++i]);
		else
			len += ft_putchar_fd(s[i], 1);
		i++;
	}
	va_end(ptr);
	return (len);
}
