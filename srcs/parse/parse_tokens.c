/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:36:29 by euiclee           #+#    #+#             */
/*   Updated: 2023/02/17 16:43:28 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	is_tokens(char *tok, int qut, int db_qut)
{
	if ((*tok != ' ' && ((*tok + 1) == ' ' || *(tok + 1) == '\0'))
		|| )
		if (qut % 2 == 0 && db_qut % 2 == 0)
			return (TRUE);
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
