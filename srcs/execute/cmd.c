/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:00:09 by euiclee           #+#    #+#             */
/*   Updated: 2023/02/23 18:47:43 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	wrong_cmd(char *msg)
{
	perror(msg);
	g_exit = 127;
	return (1);
}

int	cmd_check(t_tokens *tokens, char **envp)
{
	int	i;
	int	j;
	int	buil;
	int	flag;

	i = 0;
	flag = 0;
	buil = 0;
	while (tokens[i].token)
	{
		j = 0;
		while (tokens[i].token[j])
		{
			if (cmd_path(tokens[i].token[j], envp))
				flag = 1;
			j++;
		}
		if (is_builtin(tokens[i]) == 1)
			buil = 1;
		i++;
	}
	if (flag == 1 || buil == 1)
		return (0);
	else
		return (wrong_cmd("minishell"));
}

void	free_lalala(char **path)
{
	int	i;

	i = -1;
	while (path[++i])
		free(path[i]);
	free(path);
}

int	cmd_path(char *check, char **env)
{
	int		i;
	char	*cmd;
	char	*cmd2;
	char	**path;

	path = find_path(env);
	i = 0;
	while (path != NULL && path[i] != NULL)
	{
		cmd = ft_strjoin(path[i], "/");
		cmd2 = ft_strjoin(cmd, check);
		if (access(cmd2, X_OK) == 0)
		{
			free(cmd);
			free(cmd2);
			break ;
		}
		free(cmd);
		free(cmd2);
		i++;
	}
	if (access(cmd2, X_OK) == 0)
		return (free_lalala(path), TRUE);
	return (free_lalala(path), FALSE);
}
