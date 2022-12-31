/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 11:22:23 by orakib            #+#    #+#             */
/*   Updated: 2022/11/07 13:28:57 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putadr_fd(uintptr_t n, int fd)
{
	int		i;
	char	*x;

	i = 0;
	x = "0123456789abcdef";
	if (n >= 16)
	{
		i += ft_putadr_fd(n / 16, fd);
		i += ft_putadr_fd(n % 16, fd);
	}
	else if (n < 16)
	{
		ft_putchar_fd(*(x + n), fd);
		i++;
	}
	return (i);
}

int	ft_putunbr_fd(unsigned int n, int fd)
{
	int	i;

	i = 0;
	if (n < 10)
	{
		i += ft_putchar_fd(n + '0', fd);
	}
	else if (n >= 10)
	{
		i += ft_putunbr_fd(n / 10, fd);
		i += ft_putunbr_fd(n % 10, fd);
	}
	return (i);
}
