/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:16:34 by euiclee           #+#    #+#             */
/*   Updated: 2023/02/16 16:45:10 euiclee          ###   ########.fr       */
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
	// shell_env = cp_env(env);
	while (ac)
	{
		line = readline("\033[34;1mminishell:0.3\033[0;1m$\033[0m ");
		if (line[0] == '\0')
			continue ;
		/* ctrl + D 입력 시 실행될 함수 */
		// if (line == NULL)
		// 	sigexit_handler();
		// line = "<infile cat <<end | cat <<end";
		pipe_num = parsing(line, &tokens, env);
		if (execute(tokens, env, pipe_num) == 0)
			printf("succes\n");
		// break ;
		add_history(line);
		free(line);
		line = NULL;
	}
	// free_env(shell_env);
	// system("leaks --list minishell");
	return (0);
}
