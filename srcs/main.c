/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:16:34 by euiclee           #+#    #+#             */
/*   Updated: 2023/02/05 21:59:10 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**cp_env(char **origin_env)
{
	//cp_env need free
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
	char	*line;
	char	**shell_env;
	char	***tokens;

	(void)av;
	shell_env = cp_env(env);
	while (ac)
	{
		line = readline(BLUE"minishell-0.1$ "RESET); //$ sign doesn't need color.
		//If we want to add getcwd than we can change. Just need check can readline accept variable.
		parsing(line, tokens);
		add_history(line);
		free(line);
		line = NULL;
	}
	return (0);
}
