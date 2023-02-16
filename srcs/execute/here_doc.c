/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:19:21 by euiclee           #+#    #+#             */
/*   Updated: 2023/02/16 14:56:35 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	here_doc(t_tokens *tokens, int i)
{
	char	*limiter;
	char	*line;
	int		fd;

	fd = open_file(tokens->token[i + 1], WRITE);
	limiter = ft_strjoin(tokens->token[i + 1], "\n");
	while (TRUE)
	{
		write (STDIN_FILENO, "> ", 2);
		line = get_next_line(STDIN_FILENO);
		if (line == NULL || ft_strcmp(line, limiter) == 0)
			break ;
		write(fd, line, ft_strlen(line));
		free(line);
	}
	free(line);
	free(limiter);
}

void	save_filename(char *file_name, char **name, int *file_n)
{
	char	*num;

	num = ft_itoa((*file_n));
	name[(*file_n)] = ft_strjoin(file_name, num);
	free(num);
}

char	**name_save(t_tokens *tokens)
{
	char	**name;
	int		i;
	int		j;
	int		num;

	i = 0;
	num = 0;
	while (tokens[i].token)
	{
		j = 0;
		while (tokens[i].token[j])
			if (ft_strcmp(tokens[i].token[j], "<<") == 0)
				num++;
	}
	name = ft_calloc(num + 1, sizeof(char *));
	return (name);
}

void	replace_here_doc(t_tokens *tokens, int i, int *file_n)
{
	char	*num;

	num = ft_itoa((*file_n));
	free(tokens->token[i]);
	tokens->token[i] = ft_strdup("<");
	free(tokens->token[i + 1]);
	tokens->token[i + 1] = ft_strjoin(tokens->token[i + 1], num);
	free(num);
}

char	**find_here_doc(t_tokens *tokens)
{
	int		i;
	int		j;
	int		file_n;
	char	**name;

	i = 0;
	file_n = 0;
	name = name_save(tokens);
	while (tokens[i].token)
	{
		j = 0;
		while (tokens[i].token[j])
		{
			if (ft_strcmp(tokens[i].token[j], "<<") == 0)
			{
				save_filename(tokens[i].token[j + 1], name, &file_n);
				here_doc(&tokens[i], j);
				replace_here_doc(&tokens[i], j, &file_n);
			}
			j++;
		}
		i++;
	}
	return (name);
}
