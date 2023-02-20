/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:16:34 by euiclee           #+#    #+#             */
/*   Updated: 2023/02/20 19:57:20 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "execute.h"

void	free_env(char **env)
{
	int	env_num;

	env_num = 0;
	while (env[env_num] != NULL)
	{
		free(env[env_num]);
		env[env_num] = NULL;
		env_num++;
	}
	free(env);
}

char	**cp_env(char **origin_env)
{
	char	**env;
	int		i;

	env = (char **)malloc(sizeof(char *) * 255);
	if (env == NULL)
		exit(1);
	i = 0;
	while (origin_env[i] != NULL)
	{
		env[i] = ft_strdup(origin_env[i]);
		i++;
	}
	env[i] = NULL;
	return (env);
}

void	free_all(t_tokens *tokens)
{
	int	i;
	int	j;

	i = 0;
	while (tokens[i].token)
	{
		j = 0;
		while (tokens[i].token[j] != NULL)
		{
			free(tokens[i].token[j]);
			j++;
		}
		free(tokens[i].redir);
		free(tokens[i].token);
		i++;
	}
	free(tokens);
}

int	main(int ac, char **av, char **env)
{
	int			pipe_num;
	char		*line;
	char		**dup_env;
	t_tokens	*tokens;

	g_exit = 0;
	dup_env = cp_env(env);
	while (ac || av)
	{
		setting_signal(SHELL);
		line = readline("\033[34;1mminishell:0.8\033[0;1m$\033[0m ");
		if (line == NULL)
			sigexit_handler();
		if (line[0] == '\0')
		{
			free(line);
			continue ;
		}
		pipe_num = parsing(line, &tokens, dup_env);
		execute(tokens, dup_env, pipe_num);
		add_history(line);
		free(line);
		line = NULL;
		free_all(tokens);
	}
	return (free_env(dup_env), 0);
}
