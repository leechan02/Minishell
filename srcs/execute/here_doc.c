/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:19:21 by euiclee           #+#    #+#             */
/*   Updated: 2023/02/20 18:55:43 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	here_doc(t_tokens *tokens, int i, int *file_n)
{
	char	*line;
	char	*name;
	char	*num;
	int		fd;
	int		save;

	num = ft_itoa((*file_n));
	name = ft_strjoin(tokens->token[i + 1], num);
	fd = open_file(name, WRITE);
	save = dup(STDIN_FILENO);
	setting_signal(PARENT_HEREDOC);
	while (TRUE)
	{
		write(1, "> ", 2);
		line = get_next_line(STDIN_FILENO);
		if (line == NULL || ft_strcmp(line, tokens->token[i + 1]) == 0)
			break ;
		write(fd, line, ft_strlen(line));
		free(line);
	}
	dup2(save, STDIN_FILENO);
	free(num);
	free(name);
	free(line);
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
		{
			if (ft_strcmp(tokens[i].token[j], "<<") == 0)
				num++;
			j++;
		}
		i++;
	}
	name = ft_calloc(num + 1, sizeof(char *));
	return (name);
}

void	replace_here_doc(t_tokens *tokens, int i, int *file_n)
{
	char	*num;
	char	*temp;

	num = ft_itoa((*file_n));
	free(tokens->token[i]);
	tokens->token[i] = ft_strdup("<");
	temp = tokens->token[i + 1];
	tokens->token[i + 1] = ft_strjoin(temp, num);
	free(temp);
	free(num);
	(*file_n)++;
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
				here_doc(&tokens[i], j, &file_n);
				replace_here_doc(&tokens[i], j, &file_n);
			}
			j++;
		}
		i++;
	}
	return (name);
}
