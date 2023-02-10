/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:21:34 by euiclee           #+#    #+#             */
/*   Updated: 2023/02/10 19:42:27 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	cnt_tokens(char *token)
{
	int	num;
	int	qut;
	int	db_qut;

	num = 0;
	qut = 0;
	db_qut = 0;
	while (*token != '\0')
	{
		if (*token == '\'')
			qut = ~qut;
		else if (*token == '\"')
			db_qut = ~db_qut;
		if (*token != ' ' && (*(token + 1) == ' ' || *(token + 1) == '\0'))
			if (qut == 0 && db_qut == 0)
				num++;
		token++;
	}
	return (num);
}

char	**split_token(char *token)
{
	char	**ret;
	int		words;
	int		qut;
	int		db_qut;
	int		idx;

	idx = 0;
	qut = 0;
	db_qut = 0;
	words = cnt_tokens(token);
	ret = ft_calloc(words + 1, sizeof(char *));
	while (words)
	{
		if (*token == '\'')
			qut = ~qut;
		else if (*token == '\"')
			db_qut = ~db_qut;
		while (*token == ' ')
			token++;
		ret[idx] = ft_substr(token, 0, until_space(token));
		idx++;
	}
	return (ret);
}