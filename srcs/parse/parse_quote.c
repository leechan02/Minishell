/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 08:47:47 by euiclee           #+#    #+#             */
/*   Updated: 2023/02/26 20:29:29 by euiclee          ###   ########.fr       */
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

int	check_quote_num(char *str)
{
	int	is_qut;
	int	is_db;
	int	rm_qut;
	int	i;

	i = 0;
	is_db = 0;
	is_qut = 0;
	rm_qut = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			is_qut++;
		else if (str[i] == '\"')
			is_db++;
		if ((str[i] == '\'' && is_qut != 0
			&& is_qut % 2 == 0 && is_db % 2 == 0)
			|| (str[i] == '\"' && is_db != 0
			&& is_db % 2 == 0 && is_qut % 2 == 0))
			rm_qut += 2;
		i++;
	}
	return (rm_qut);
}

char	*rm_quote(char *str, int len)
{
	char	*ret;
	char	*temp;
	char	*loca;
	int		i;

	temp = str;
	ret = ft_calloc(len + 1, sizeof(char));
	i = 0;
	while (*str != '\0')
	{
		while (*str != '\'' && *str != '\"')
			ret[i++] = *str++;
		if (*str == '\'')
			loca = ft_strchr(++str, '\'');
		else if (*str == '\"')
			loca = ft_strchr(++str, '\"');
		if (*str != '\0' && loca && *str != *loca)
		{
			while (str && loca && *str != *loca)
				ret[i++] = *str++;
			str++;
		}
		else if (*str != '\0')
			str++;
	}
	return (free(temp), ret);
}

void	check_quote(t_tokens *tokens)
{
	int	i;
	int	len;
	int	ret_len;

	i = 0;
	while (tokens->token[i])
	{
		len = check_quote_num(tokens->token[i]);
		ret_len = ft_strlen(tokens->token[i]) - len;
		if (len)
			tokens->token[i] = rm_quote(tokens->token[i], ret_len);
		i++;
	}
}
