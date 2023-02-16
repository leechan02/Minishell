/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:02:33 by nakoo             #+#    #+#             */
/*   Updated: 2023/02/16 19:05:30 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	sigexit_handler(void)
{
	write(1, "exit\n", 5);
	exit(128 + SIGTERM);
}

void	sigint_handler1(int sig)
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
	{
		write (1, "Quit :3\n", 8);
		/* have to sest errno */
	}
}

void	sigint_handler2(int sig)
{
	if (sig == SIGINT)
	{
		write (1, "\n", 1);
		/* have to set errno */
	}
}

void	setting_signal(int status)
{
	if (status == SHELL)
	{
		signal(SIGINT, sigint_handler1);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (status == PARENT_EXECVE)
	{
		signal(SIGINT, sigint_handler2);
		signal(SIGQUIT, sigint_handler1);
	}
	else if (status == CHILD_EXECVE)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
	}
	else if (status == PARENT_HEREDOC)
	{
		signal(SIGINT, sigint_handler2);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (status == CHILD_HEREDOC)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_IGN);
	}
}
