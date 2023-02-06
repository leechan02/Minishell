/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:18:22 by euiclee           #+#    #+#             */
/*   Updated: 2023/02/06 19:57:24 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	get_pipe(char *line)
{
	int	i;
	int	pipe_num;

	i = 0;
	pipe_num = 0;
	while (line[i])
	{
		if (line[i] == '|')
			pipe_num++;
		i++;
	}
	return (pipe_num);
}

int	until_pipe(char *line, int i)
{
	int	len;

	len = 0;
	while (line[i] && line[i] != '|')
	{
		len++;
		i++;
	}
	return (len);
}

char	*get_env(char *line)
{
	int		len;

	len = 0;
	while (ft_isalnum(line[len]) || line[len] == '_')
		len++;
	return (ft_substr(line, 0, len));
}

char	*replace_env(char *line, char *env)
{
	char	*ret;
	char	*start;
	char	*finish;
	int		len1;
	int		len2;
	int		len3;

	len1 = 0;
	start = line;
	while (*start != '$')
	{
		start++;
		len1++;
	}
	len2 = 0;
	finish = start;
	while (ft_isalnum(*finish) || *finish == '_')
	{
		finish++;
		len2++;
	}
	len3 = 0;
	return (ret);
}

char	**check_env(char *line, char **env)
{
	char	**ret;
	char	*temp;
	char	*variable;
	int		i;

	i = 0;
	ret = ft_split(line, ' ');
	while (ret[i])
	{
		temp = ft_strchr(ret[i], '$');
		if (temp != NULL)
		{
			variable = get_env(++temp);
			temp = ft_strfind(env, variable);
			if (temp != NULL)
				ret[i] = replace_env(ret[i], temp);
			else
				ret[i] = ft_strtrim(ret[i], variable);
			free(variable);
		}
		i++;
	}
	return (ret);
}

void	parsing(char *line, char ***tokens, char **env)
{
	char	*token;
	int		token_num;
	int		idx;
	int		i;
	int		token_len;

	token_num = get_pipe(line) + 1;
	tokens = malloc(sizeof(char **) * (token_num + 1));
	i = 0;
	idx = 0;
	while (token_num > 0)
	{
		token_len = until_pipe(line, i);
		token = ft_substr(line, i, token_len);
		tokens[idx] = check_env(token, env);
		i += token_len + 1;
		idx++;
		token_num--;
		free(token);
	}
	printf("tokens : %d\n", idx);
	tokens[idx] = NULL;
	for (int k = 0; tokens[k]; k++)
	{
		printf("token[%d] : ", k);
		for (int j = 0; tokens[k][j]; j++)
			printf("%s ", tokens[k][j]);
		printf("\n");
	}
}
