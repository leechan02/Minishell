/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 09:43:46 by euiclee           #+#    #+#             */
/*   Updated: 2023/02/21 15:42:47 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	file_delete(char **file_name)
{
	int	i;

	i = 0;
	while (file_name[i])
	{
		unlink(file_name[i]);
		i++;
	}
	i = 0;
	while (file_name[i])
	{
		free(file_name[i]);
		i++;
	}
	free(file_name);
}

void	pipex(int token_nb, t_tokens *tokens, char **env, int flag)
{
	t_pipe	p;

	p.cmd = -1;
	p.old_fd[0] = STDIN_FILENO;
	p.file_name = find_here_doc(tokens, &flag);
	while (++p.cmd < token_nb && g_exit != 130 && flag != 1)
	{
		pipe(p.new_fd);
		setting_signal(CHILD_EXECVE);
		p.pid = fork();
		if (p.pid == 0)
		{
			close(p.new_fd[0]);
			dup2(p.old_fd[0], STDIN_FILENO);
			find_redir(&tokens[p.cmd], p.new_fd[1], token_nb, p.cmd);
			exec(tokens[p.cmd].token, env);
		}
		if (p.old_fd[0] != 0)
			close(p.old_fd[0]);
		close(p.new_fd[1]);
		ft_memcpy(p.old_fd, p.new_fd, sizeof(int) * 2);
	}
	if (flag != 1)
		wait_children(token_nb);
	file_delete(p.file_name);
}
