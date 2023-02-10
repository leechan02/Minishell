/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:18:22 by euiclee           #+#    #+#             */
/*   Updated: 2023/02/10 14:24:30 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	get_pipe(char *line)
{
	int	qut;
	int	db_qut;
	int	pipe_num;

	qut = 0;
	db_qut = 0;
	pipe_num = 0;
	while (*line)
	{
		if (*line == '\'')
			qut = ~qut;
		else if (*line == '\"')
			db_qut = ~db_qut;
		if (*line == '|' && qut == 0 && db_qut == 0)
			pipe_num++;
		line++;
	}
	if (qut != 0 || db_qut != 0)
		pipe_num = -1;
	return (pipe_num);
}

int	until_pipe(char *line)
{
	int	len;
	int	qut;
	int	db_qut;

	len = 0;
	qut = 0;
	db_qut = 0;
	while (line[len] != '|' && line[len] != '\0')
	{
		if (line[len] == '\'')
			qut = ~qut;
		else if (line[len] == '\"')
			db_qut = ~db_qut;
		len++;
	}
	return (len);
}

void	parsing(char *line, t_tokens **tokens, char **env)
{
	char	*token;
	int		tokens_n;
	int		token_len;
	int		idx;

	tokens_n = get_pipe(line) + 1;
	if (tokens_n == 0)
		return (perror("What the f**k!!"));
	*tokens = ft_calloc(tokens_n + 1, sizeof(t_tokens));
	idx = 0;
	while (*line)
	{
		token_len = until_pipe(line);
		printf("token len = %d\n", token_len);
		token = ft_substr(line++, 0, token_len);
		printf("token : %s\n", token);
		// *tokens[idx++]->token = check_env(token, env);
		line += token_len;
		free(token);
	}
	// printf("tokens : %d\n", idx);
	// for (int k = 0; *tokens[k]->token; k++)
	// {
	// 	printf("token[%d] : ", k);
	// 	// for (int j = 0; tokens[k][j]; j++)
	// 		printf("%s ", *tokens[k]->token);
	// 	printf("\n");
	// }
}
