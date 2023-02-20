/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:36:29 by euiclee           #+#    #+#             */
/*   Updated: 2023/02/20 17:37:09 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	is_tokens(char **tok, int qut, int db_qut)
{
	if (qut % 2 == 0 && db_qut % 2 == 0)
	{
		if (**tok != ' ' && (*(*tok + 1) == ' ' || *(*tok + 1) == '\0'))
			return (TRUE);
		else if (**tok == '<' && *(*tok + 1) == '<' && *(*tok + 2) != '<')
		{
			(*tok)++;
			return (TRUE);
		}
		else if (**tok == '>' && *(*tok + 1) == '>' && *(*tok + 2) != '>')
		{
			(*tok)++;
			return (TRUE);
		}
		else if (**tok == '<' || **tok == '>')
			return (TRUE);
		else if ((**tok == '\'' || **tok == '\"') && *(*tok + 1) == ' '
			&& (qut != 0 || db_qut != 0))
			return (TRUE);
	}
	return (FALSE);
}

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
		if (is_tokens(&tok, qut, db_qut))
			num++;
		if (((*tok == '<' && *(tok + 1) == '<' && *(tok + 1) != '<'))
			|| ((*tok == '>' && *(tok + 1) == '>') && *(tok + 1) != '>'))
			tok++;
		tok++;
	}
	return (num);
}
