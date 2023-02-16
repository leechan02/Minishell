/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:16:34 by euiclee           #+#    #+#             */
/*   Updated: 2023/02/16 18:07:36 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "execute.h"

void	free_env(char **env)
{
	int	env_num;

	env_num = -1;
	while (env[++env_num])
		free(env[env_num]);
	free(env);
}

char	**cp_env(char **origin_env)
{
	char	**env;
	int		env_num;

	env_num = 0;
	while (origin_env[env_num])
		env_num++;
	env = malloc(sizeof(char *) * env_num);
	if (!env)
		return (NULL);
	env_num = -1;
	while (origin_env[++env_num])
		env[env_num] = ft_strdup(origin_env[env_num]);
	env[env_num] = NULL;
	return (env);
}

int	main(int ac, char **av, char **env)
{
	int			pipe_num;
	char		*line;
	char		**shell_env;
	t_tokens	*tokens;

	(void)av;
	while (ac)
	{
		setting_signal(SHELL);
		line = readline("\033[34;1mminishell:0.5\033[0;1m$\033[0m ");
		if (line == NULL)
			sigexit_handler();
		if (line[0] == '\0')
			continue ;
		pipe_num = parsing(line, &tokens, env);
		execute(tokens, env, pipe_num);
		add_history(line);
		free(line);
		line = NULL;
	}
	return (0);
}
