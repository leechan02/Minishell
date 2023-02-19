/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 08:47:47 by euiclee           #+#    #+#             */
/*   Updated: 2023/02/18 16:30:51 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	env_qut_check(char *str)
{
	int	first;
	int	qut;
	int	db_qut;

	first = 0;
	qut = 0;
	db_qut = 0;
	while (*str != '\0')
	{
		if (*str == '\'')
		{
			first++;
			qut = first;
		}
		else if (*str == '\"')
		{
			first++;
			db_qut = first;
		}
		else if (*str == '$' && ((db_qut > qut && qut != 0)
				|| (db_qut == 0 && qut == 1)))
			return (FALSE);
		str++;
	}
	return (TRUE);
}

void	check_quote_num(char *str, int *qut, int *db_qut)
{
	while (*str)
	{
		if (*str == '\'')
			(*qut)++;
		else if (*str == '\"')
			(*db_qut)++;
		str++;
	}
}

char	*rm_quote(char *str, char c)
{
	char	*ret;
	char	*temp;
	int		len;
	int		i;

	temp = str;
	len = ft_strlen(str);
	ret = ft_calloc(len - 1, sizeof(char));
	i = 0;
	while (*str)
	{
		if (*str != c)
			ret[i++] = *str;
		str++;
	}
	free(temp);
	return (ret);
}

void	check_quote(t_tokens *tokens)
{
	int	i;
	int	j;
	int	qut;
	int	db_qut;

	i = 0;
	while (tokens->token[i])
	{
		qut = 0;
		db_qut = 0;
		check_quote_num(tokens->token[i], &qut, &db_qut);
		j = 0;
		while (tokens->token[i][j] != '\0'
			&& tokens->token[i][j] != '\'' && tokens->token[i][j] != '\"')
			j++;
		if (tokens->token[i][j] == '\'' && qut % 2 == 0)
			tokens->token[i] = rm_quote(tokens->token[i], '\'');
		else if (tokens->token[i][j] == '\"' && db_qut % 2 == 0)
			tokens->token[i] = rm_quote(tokens->token[i], '\"');
		i++;
	}
}
