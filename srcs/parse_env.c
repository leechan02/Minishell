/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 09:39:56 by euiclee           #+#    #+#             */
/*   Updated: 2023/02/07 10:05:36 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	*get_env(char *line)
{
	int		len;

	len = 0;
	while (ft_isalnum(line[len]) || line[len] == '_')
		len++;
	return (ft_substr(line, 0, len));
}

int	get_len(char *line, char *env)
{
	int		len;
	char	*temp;

	len = 0;
	temp = line;
	while (*temp != '$')
	{
		temp++;
		len++;
	}
	temp++;
	while (ft_isalnum(*temp) || *temp == '_')
		temp++;
	while (*temp != '\0')
	{
		len++;
		temp++;
	}
	len += ft_strlen(env);
	return (len);
}

char	*replace_env(char *line, char *env, char *env_name)
{
	char	*ret;
	char	*temp;
	int		total_len;
	int		len;

	len = 0;
	temp = line;
	env_name = ft_strjoin(env_name, "=");
	env = ft_strtrim(env, env_name);
	total_len = get_len(line, env);
	ret = ft_calloc(total_len + 1, sizeof(char));
	while (*temp != '$')
	{
		len++;
		temp++;
	}
	ft_memmove(ret, line, len);
	ft_strlcat(ret, env, len + ft_strlen(env));
	temp++;
	while (ft_isalnum(*temp) || *temp == '_')
		temp++;
	ft_memmove(ret, temp, ft_strlen(temp));
	free(line);
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
				ret[i] = replace_env(ret[i], temp, variable);
			else
				ret[i] = ft_strtrim(ret[i], variable);
			free(variable);
		}
		i++;
	}
	return (ret);
}
