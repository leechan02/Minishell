/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:50:52 by nakoo             #+#    #+#             */
/*   Updated: 2023/02/14 14:21:08by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	is_builtin(t_tokens *tokens, char **env, int idx)
{
	int	j;

	j = 0;
	while (tokens->token + idx != NULL)
	{
		if (ft_strcmp(tokens->token[j], "export") == 0)
			return (ft_export(tokens->token + idx, env));
		else if (ft_strcmp(tokens->token[j], "unset") == 0)
			return (ft_unset(tokens->token + idx, env));
		else if (ft_strcmp(tokens->token[j], "cd") == 0)
			return (ft_cd(tokens->token + idx, env));
		else if (ft_strcmp(tokens->token[j], "pwd") == 0)
			return (ft_pwd(env));
		else if (ft_strcmp(tokens->token[j], "env") == 0)
			return (ft_env(env));
		else if (ft_strcmp(tokens->token[j], "echo") == 0)
			return (ft_echo(tokens->token + idx));
		else if (ft_strcmp(tokens->token[j], "exit") == 0)
			ft_exit(tokens->token + idx);
		j++;
	}
	return (FALSE);
}

func
{
	dup2;
}

void	only_process(t_tokens *tokens, char **env)
{
	"echo hello > out"
	while (tokens->token[i])
		ft_strcmp(tokens->token[i], "echo");
	1. find command.
		if (builtin)
		>  << > >> 
		else if (access)
		else command not found
			fork()
			>
			exec()
		if (not builtin)
			wait_children(1);	
}

int	execute(t_tokens *tokens, char **env, int pipe_num)
{
	if (pipe_num == 0)
	 	only_process(tokens, env);
	else
	 	pipex(pipe_num + 1, tokens, env);
	return (0);
}