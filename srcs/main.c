/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:16:34 by euiclee           #+#    #+#             */
/*   Updated: 2023/02/04 23:37:47 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**cp_env(char **origin_env)
{
	/*요놈들 free 필요할 것 같음*/
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
	char	***token;
	int		i;

	(void)av;
	shell_env = cp_env(env);
	while (ac)
	{
		line = readline(BLUE"minishell-0.1$ "RESET);
		i = -1;
		token = parsing(line);
		while (token[++i])
			;
		printf("token : %d\n", i);
		add_history(line);
		free(line);
		line = NULL;
	}
	return (0);
}
