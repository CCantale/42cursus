/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 16:54:45 by ccantale          #+#    #+#             */
/*   Updated: 2022/08/12 01:09:43 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/server.h"

void	quit(int client_pid)
{
	ft_printf("Good night!\n\n");
	kill(client_pid, SIGUSR2);
	exit(0);
}

/* in case c == '@', the program quits and sends a SIGUSR2 to the 
** client. that's a personal addition to the project. I liked the 
** idea of being able to end the process in a cleaner way than 
** ctrl + C
*/

void	handler(int signum, siginfo_t *info, void *ptr)
{
	static unsigned int	c;
	static int			i;

	(void)ptr;
	if (signum == SIGUSR1)
		c |= 1;
	else if (signum == SIGUSR2)
		c |= 0;
	++i;
	if (i == 8)
	{
		if (c == '\0')
		{
			kill(info->si_pid, SIGUSR1);
			write(1, "\n\n", 2);
		}
		else if (c == '@')
			quit(info->si_pid);
		else
			write(1, &c, 1);
		i = 0;
		c = 0;
		return ;
	}
	c <<= 1;
}

/* makes the last of c's bits a 0 or a 1, depending on the signal
** recieved. then ++i. if i == 8, prints c, unless it's the end of
** the string (c == 0). in that case, sends a SIGUSR1 back to the
** client (bonus part of the project). if i < 8, it means that the
** byte hasn't been completely sent yet, so all of c's bits are 
** shifted by one step, so that it's ready to recieve the next bit.
** ptr is cast to void so that the compiler doesn't complain
*/

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	ft_putnbr_fd((int)getpid(), 1);
	write(1, "\n\n", 2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}

/* creates a sigaction structure, then prints the pid of this process.
** then calls sigaction() in order to redirect the two signals SIGUSR1
** and SIGUSR2 to handler(). finally, enters an infinite loop, waiting
** for signals
*/
