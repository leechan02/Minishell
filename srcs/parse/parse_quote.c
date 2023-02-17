/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 08:47:47 by euiclee           #+#    #+#             */
/*   Updated: 2023/02/17 19:42:13 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

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
	int		i;
	int		qut;
	int		db_qut;

	i = 0;
	qut = 0;
	db_qut = 0;
	while (tokens->token[i])
	{
		check_quote_num(tokens->token[i], &qut, &db_qut);
		if (ft_strchr(tokens->token[i], '\'') != NULL && qut == 2)
			tokens->token[i] = rm_quote(tokens->token[i], '\'');
		else if (ft_strchr(tokens->token[i], '\"') != NULL && db_qut == 2)
			tokens->token[i] = rm_quote(tokens->token[i], '\"');
		i++;
	}
}
