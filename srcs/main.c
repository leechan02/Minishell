/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:16:34 by euiclee           #+#    #+#             */
/*   Updated: 2023/02/03 18:20:58by euiclee          ###   ########.fr       */
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
	env_num = -1;
	while (origin_env[++env_num])
		env[env_num] = ft_strdup(origin_env[env_num]);
	return (env);
}

int	main(int ac, char **av, char **env)
{
	char	*line;
	char	**shell_env;
	char	***token;

	(void)av;
	shell_env = cp_env(env);
	int	i = -1;
	line = "ls -a -l | wc -l";
	token = parsing(line);
	while (token[++i])
		printf("token : %d", i);
	// while (ac)
	// {
	// 	line = readline(BLUE"minishell-0.1$ "RESET);
	// 	add_history(line);
	// 	free(line);
	// 	line = NULL;
	// }
	return (0);
}
