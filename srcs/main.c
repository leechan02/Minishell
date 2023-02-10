/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:16:34 by euiclee           #+#    #+#             */
/*   Updated: 2023/02/10 18:41:38 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

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
	char		*line;
	char		**shell_env;
	t_tokens	*tokens;

	(void)av;
	shell_env = cp_env(env);
	while (ac)
	{
		// line = readline("\033[34;1mminishell:0.1\033[0;1m$\033[0m ");
		line = "echo '$USER' '| $US' | \"ER\" >'>'file";
		// line = "echo \" \' \" \'";
		parsing(line, &tokens, shell_env);
		// add_history(line);
		break ;
		// free(line);
		// line = NULL;
	}
	free_env(shell_env);
	// system("leaks --list minishell");
	return (0);
}
