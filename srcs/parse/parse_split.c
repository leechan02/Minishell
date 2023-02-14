/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:21:34 by euiclee           #+#    #+#             */
/*   Updated: 2023/02/13 19:06:56by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	cnt_tokens(char *tok)
{
	int	num;
	int	qut;
	int	db_qut;

	num = 0;
	qut = 0;
	db_qut = 0;
	while (*tok != '\0')
	{
		if (*tok == '\'')
			qut++;
		else if (*tok == '\"')
			db_qut++;
		if ((*tok != ' ' && (*(tok + 1) == ' ' || *(tok + 1) == '\0'))
			|| (*tok == '<' && *(tok + 1) == '<')
			|| (*tok == '>' && *(tok + 1) == '>') || *tok == '<' || *tok == '>'
			|| ((*tok == '\'' || *tok == '\"') && (qut != 0 || db_qut != 0)))
			if (qut % 2 == 0 && db_qut % 2 == 0)
				num++;
		if ((*tok == '<' && *(tok + 1) == '<')
			|| (*tok == '>' && *(tok + 1) == '>'))
			tok++;
		tok++;
	}
	return (num);
}

int	is_redirection(char **token, int qut, int db_qut, int *len)
{
	if (**token == '<' && qut == 0 && db_qut == 0)
	{
		if (*(*token + 1) == '<')
		{
			(*len)++;
			(*token)++;
			return (TRUE);
		}
		return (TRUE);
	}
	else if (**token == '>' && qut == 0 && db_qut == 0)
	{
		if (*(*token + 1) == '>')
		{
			(*len)++;
			(*token)++;
			return (TRUE);
		}
		return (TRUE);
	}
	return (FALSE);
}

int	is_spaquot(char **token, int qut, int db_qut)
{
	if (**token == '\"' && ((qut != 0 && qut % 2 == 0)
			|| (db_qut != 0 && db_qut % 2 == 0)))
		return (TRUE);
	else if (**token == '\'' && ((qut != 0 && qut % 2 == 0)
			|| (db_qut != 0 && db_qut % 2 == 0)))
		return (TRUE);
	else if ((**token == ' ' && qut % 2 == 0 && db_qut % 2 == 0))
		return (TRUE);
	return (FALSE);
}

int	until_sep(char **token)
{
	int	len;
	int	qut;
	int	db_qut;

	len = 0;
	qut = 0;
	db_qut = 0;
	while (**token != '\0')
	{
		len++;
		if (**token == '\'')
			qut++;
		else if (**token == '\"')
			db_qut++;
		if (is_spaquot(token, qut, db_qut)
			|| is_redirection(token, qut, db_qut, &len))
		{
			(*token)++;
			break ;
		}
		(*token)++;
	}
	return (len);
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
	while (idx < words)
	{
		while (*token == ' ')
			token++;
		ret[idx] = ft_substr(token, 0, until_sep(&token));
		idx++;
	}
	return (ret);
}