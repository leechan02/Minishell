/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:03:03 by nakoo             #+#    #+#             */
/*   Updated: 2023/02/13 18:51:26 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static int	get_del_idx(char *token, char **env, int *del_idx)
{
	int	token_len;

	*del_idx = 0;
	token_len = ft_strlen(token);
	while (env[*del_idx] != NULL)
	{
		if (ft_strncmp(token, env[*del_idx], token_len) == 0)
			return (*del_idx);
		(*del_idx)++;
	}
	return (FALSE);
}

int	ft_unset(char **token, char **env)
{
	int	i;
	int	del_idx;

	i = -1;
	while (ft_strcmp(token[++i], "unset") == 0)
		;
	while (token[++i] != NULL)
	{
		if (ft_isalpha(token[i][0]) == 0 && token[i][0] != '_')
			printf("minishell: unset: `%s': not a valid identifier\n", \
			token[i]);
		else
		{
			if (get_del_idx(token[i], env, &del_idx) != FALSE)
			{
				while (env[del_idx + 1] != NULL)
				{
					env[del_idx] = ft_strdup(env[del_idx + 1]);
					del_idx++;
				}
				env[del_idx] = NULL;
			}
		}
	}
	return (TRUE);
}
