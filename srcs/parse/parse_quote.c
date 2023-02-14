/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 08:47:47 by euiclee           #+#    #+#             */
/*   Updated: 2023/02/14 08:57:29 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	check_quote(t_tokens *tokens)
{
	int		i;
	char	*temp;

	i = 0;
	while (tokens->token[i])
	{
		temp = tokens->token[i];
		if (tokens->token[i][0] == '\'')
		{
			tokens->token[i] = ft_strtrim(temp, "\'");
			free(temp);
		}
		else if (tokens->token[i][0] == '\"')
		{
			tokens->token[i] = ft_strtrim(temp, "\"");
			free(temp);
		}
		i++;
	}
}
