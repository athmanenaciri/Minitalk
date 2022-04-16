/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaciri <anaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 05:48:50 by anaciri           #+#    #+#             */
/*   Updated: 2022/04/15 22:48:11 by anaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

int		ft_atoi(char *str, int *res);
void	ft_putchar(char c);
void	ft_putstr(char *str);

void	send_char(int pid, char c)
{
	int	shift;
	int	i;

	i = 7;
	while (i >= 0)
	{
		shift = 1 << (i);
		if (c & shift)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		i--;
	}
}

void	send_message(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_char(pid, str[i]);
		i++;
	}
	send_char(pid, str[i]);
}
#include <stdio.h>

void	sighandler(int sig)
{
	(void)sig;
	printf("message reseved succasfuly!!\n");
}

int	main(int ac, char **av)
{
	int	i;

	if (ac != 3)
		return (1);
	signal(SIGUSR1, sighandler);
	if (ft_atoi(av[1], &i) == 0)
	{
		ft_putstr("invalid argument");
		return (1);
	}
	else
	{
		if (kill(i, 0) == -1)
		{
			ft_putstr("Invalid PID\n");
			return (1);
		}
		else
		{
			if(i == 0)
			{
				ft_putstr("Invalid PID\n");
				return(1);
			}
			send_message(i, av[2]);
			return (0);
		}
	}
}
