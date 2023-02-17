/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:16:34 by euiclee           #+#    #+#             */
/*   Updated: 2023/02/17 19:43:15 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "execute.h"

// void	free_env(char **env)
// {
// 	int	env_num;

// 	env_num = -1;
// 	while (env[++env_num])
// 		free(env[env_num]);
// 	free(env);
// }

// char	**cp_env(char **origin_env)
// {
// 	char	**env;
// 	int		env_num;

// 	env_num = 0;
// 	while (origin_env[env_num])
// 		env_num++;
// 	env = malloc(sizeof(char *) * env_num);
// 	if (!env)
// 		return (NULL);
// 	env_num = -1;
// 	while (origin_env[++env_num])
// 		env[env_num] = ft_strdup(origin_env[env_num]);
// 	env[env_num] = NULL;
// 	return (env);
// }

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
	t_tokens	*tokens;

	while (ac || av)
	{
		setting_signal(SHELL);
		line = readline("\033[34;1mminishell:0.6\033[0;1m$\033[0m ");
		if (line == NULL)
			sigexit_handler();
		if (line[0] == '\0')
		{
			free(line);
			continue ;
		}
		pipe_num = parsing(line, &tokens, env);
		execute(tokens, env, pipe_num);
		add_history(line);
		free(line);
		line = NULL;
		free_all(tokens);
	}
	return (0);
}
