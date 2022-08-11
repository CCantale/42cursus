/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 23:00:49 by ccantale          #+#    #+#             */
/*   Updated: 2022/08/12 01:08:18 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/client.h"

void	recieved_sig(int signum)
{
	if (signum == SIGUSR1)
		write(1, "Message sent and succesfully recieved!\n", 39);
	else
	{
		write(1, "Quit procedure completed. Bye!\n", 31);
		exit(0);
	}	
}

/* if (signum == SIGUSR1), prints the success msg 
** if (signum == SIGUSR2), prints the quit msg 
*/

void	send_bits(int pid, char *msg)
{
	int	i;
	int	b;
	int	end;

	end = ft_strlen(msg);
	i = 0;
	while (i <= end)
	{
		b = 7;
		while (b >= 0)
		{
			if ((msg[i] >> b) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			--b;
			usleep(100);
		}
		++i;
	}
}

/* scrolls msg[] and starts a loop for each and
** every byte(char): first, shifts msg[i]'s bits
** to the right by 7 steps, in order to get to its 
** first bit. if it's a 1, SIGUSR1 is sent to the
** server, by kill(), using its pid. if the bit is
** a 0, SIGUSR2 is sent. then, msg[i]'s bits are
** shifted by 6 steps and the same happens, until
** 8 bits have been sent. since sigaction() doesn't
** organise the recieved signals in a queue, usleep()
** is called after every signal sent, to give the
** server enough to process it
*/

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "Only two arguments, please.\n", 28);
		return (0);
	}
	signal(SIGUSR1, recieved_sig);
	signal(SIGUSR2, recieved_sig);
	send_bits(ft_atoi(argv[1]), argv[2]);
	usleep(300);
	return (0);
}

/* only 2 arguments are allowed: the server's pid
** and the msg to send. signal() catches the
** answer of the server and ridirects it to 
** recieved_sig(), usleep() is called in order for
** the program to wait for the signal
*/
