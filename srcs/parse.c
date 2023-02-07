/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:18:22 by euiclee           #+#    #+#             */
/*   Updated: 2023/02/07 09:40:57 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	get_pipe(char *line)
{
	int	i;
	int	pipe_num;

	i = 0;
	pipe_num = 0;
	while (line[i])
	{
		if (line[i] == '|')
			pipe_num++;
		i++;
	}
	return (pipe_num);
}

int	until_pipe(char *line, int i)
{
	int	len;

	len = 0;
	while (line[i] && line[i] != '|')
	{
		len++;
		i++;
	}
	return (len);
}

void	parsing(char *line, char ***tokens, char **env)
{
	char	*token;
	int		token_num;
	int		idx;
	int		i;
	int		token_len;

	token_num = get_pipe(line) + 1;
	tokens = malloc(sizeof(char **) * (token_num + 1));
	i = 0;
	idx = 0;
	while (token_num > 0)
	{
		token_len = until_pipe(line, i);
		token = ft_substr(line, i, token_len);
		tokens[idx] = check_env(token, env);
		i += token_len + 1;
		idx++;
		token_num--;
		free(token);
	}
	printf("tokens : %d\n", idx);
	tokens[idx] = NULL;
	for (int k = 0; tokens[k]; k++)
	{
		printf("token[%d] : ", k);
		for (int j = 0; tokens[k][j]; j++)
			printf("%s ", tokens[k][j]);
		printf("\n");
	}
}
