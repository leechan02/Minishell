/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:02:33 by nakoo             #+#    #+#             */
/*   Updated: 2023/02/15 13:06:39 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	sigexit_handler(void)
{
	write(1, "exit\n", 5);
	exit(128 + SIGTERM);
}

void	signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		write(STDOUT_FILENO, "\n", 1);
		if (rl_on_new_line() == -1)
			exit(1);
		rl_replace_line("", 1);
		rl_redisplay();
	}
	else if (sig == SIGQUIT)
		signal(SIGQUIT, SIG_IGN);
}

void	sigquit_handler(void)
{

}
