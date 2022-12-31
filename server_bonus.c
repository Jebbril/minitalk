/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:43:09 by orakib            #+#    #+#             */
/*   Updated: 2022/12/31 17:01:53 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_handle(int sig, siginfo_t *info, void *context)
{
	static int	bit;
	static int	i;
	static int	cpid;

	(void)info;
	(void)context;
	if (cpid != info->si_pid)
	{
		bit = 0;
		i = 0;
	}
	cpid = info->si_pid;
	if (sig == SIGUSR1)
		i = i | (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
		kill (info->si_pid, SIGUSR1);
	}
}

int	main(void)
{
	struct sigaction	act;

	ft_printf("Server's PID is : %d\n", getpid());
	act.sa_sigaction = &ft_handle;
	while (1)
	{
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
		pause();
	}
}
