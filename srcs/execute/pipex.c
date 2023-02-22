/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 09:43:46 by euiclee           #+#    #+#             */
/*   Updated: 2023/02/22 19:08:03 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	file_delete(char **file_name)
{
	int	i;

	i = 0;
	if (file_name == NULL)
		return ;
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

static void	init_structure(t_pipe *p, t_tokens *tokens, int *flag)
{
	p->cmd = -1;
	p->old_fd[0] = STDIN_FILENO;
	p->file_name = find_here_doc(tokens, flag);
}

void	pipex(int token_nb, t_tokens *tokens, char **env, int flag)
{
	t_pipe	p;

	init_structure(&p, tokens, &flag);
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
			if (is_builtin(tokens[p.cmd]) == TRUE)
				exit(!exec_builtin(&tokens[p.cmd], env));
			else
				exec(tokens[p.cmd].token, env);
		}
		if (p.old_fd[0] != 0)
			close(p.old_fd[0]);
		close(p.new_fd[1]);
		ft_memcpy(p.old_fd, p.new_fd, sizeof(int) * 2);
	}
	if (flag != 1)
		return (wait_children(token_nb), file_delete(p.file_name));
}
