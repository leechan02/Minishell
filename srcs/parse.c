/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:18:22 by euiclee           #+#    #+#             */
/*   Updated: 2023/02/13 10:14:15by euiclee          ###   ########.fr       */
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
	while (line[len] != '\0')
	{
		if (line[len] == '\'')
			qut = ~qut;
		else if (line[len] == '\"')
			db_qut = ~db_qut;
		if (line[len] == '|' && qut == 0 && db_qut == 0)
			break ;
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
	*tokens = ft_calloc(tokens_n + 1, sizeof(t_tokens));
	idx = 0;
	while (*line)
	{
		token_len = until_pipe(line);
		token = ft_substr(line, 0, token_len);
		tokens[idx]->token = split_token(token);
		tokens[idx]->redir = ft_calloc(cnt_tokens(token), sizeof(int));
		is_redir(tokens, idx, cnt_tokens(token));
		check_env(tokens[idx], env);
		for (int i = 0; tokens[idx]->token[i]; i++)
			printf("tokens : %s\n", tokens[idx]->token[i]);
		idx++;
		line += token_len;
		if (*line == '|')
			line++;
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