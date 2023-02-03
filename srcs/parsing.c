/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:18:22 by euiclee           #+#    #+#             */
/*   Updated: 2023/02/03 20:31:55 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	get_pipe(char *line)
{
	int	i;
	int	pipe_num;

	i = -1;
	pipe_num = 0;
	while (line[++i])
		if(line[i] == '|')
			pipe_num++;
	return (pipe_num);
}

int	until_pipe(char *line, int *i)
{
	int	len;

	len = 0;
	while (line[*i] != '|')
	{
		len++;
		i++;
	}
	return (len);
}

char	***parsing(char *line)
{
	char	***tokens;
	char	*token;
	int		pipe_num;
	int		idx;
	int		i;

	pipe_num = get_pipe(line);
	tokens = malloc(sizeof(char **) * (pipe_num + 2));
	idx = 0;
	while (pipe_num > 0)
	{
		token = ft_substr(line, i, until_pipe(line, &i));
		tokens[idx++] = ft_split(token, ' ');
		pipe_num--;
		free(token);
	}
	tokens[idx] = NULL;
	return (tokens);
}
