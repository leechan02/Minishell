/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:03:03 by nakoo             #+#    #+#             */
/*   Updated: 2023/02/17 14:34:58 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static void	swap(int *a, int *b)
{
	if (a == b)
		return ;
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

static int	*sort_ascii(char **env)
{
	int	*sorted_idx;
	int	idx;
	int	i;
	int	j;

	idx = 0;
	while (env[idx] != NULL)
		idx++;
	sorted_idx = (int *)malloc(sizeof(int) * idx);
	idx = -1;
	while (env[++idx] != NULL)
		sorted_idx[idx] = idx;
	i = -1;
	while (++i < idx - 1)
	{
		j = i + 1;
		while (++j < idx)
		{
			if (ft_strcmp(env[sorted_idx[i]], env[sorted_idx[j]]) > 0)
				swap(&sorted_idx[i], &sorted_idx[j]);
		}
	}
	return (sorted_idx);
}

static int	print_export(char **env, int *sorted_idx, int sign)
{
	int	i;
	int	j;

	sorted_idx = sort_ascii(env);
	i = -1;
	while (env[++i] != NULL)
	{
		j = -1;
		printf("declare -x ");
		sign = NO_EQUAL;
		while (env[sorted_idx[i]][++j] != '\0')
		{
			if (env[sorted_idx[i]][j] == '=' && sign == NO_EQUAL)
			{
				sign = EQUAL;
				printf("=\"");
			}
			else
				printf("%c", env[sorted_idx[i]][j]);
		}
		if (sign == EQUAL)
			printf("\"");
		printf("\n");
	}
	return (free(sorted_idx), TRUE);
}

void	variable_init(int **sorted_idx, int *sign, int *i)
{
	*sorted_idx = NULL;
	*sign = 0;
	*i = -1;
}

int	ft_export(char **token, char **env)
{
	int	*sorted_idx;
	int	sign;
	int	i;
	int	j;

	variable_init(&sorted_idx, &sign, &i);
	while (ft_strcmp(token[++i], "export") != 0)
		;
	if (token[i + 1] == NULL || token[i + 1][0] == '\0')
		return (print_export(env, sorted_idx, sign));
	while (token[++i] != NULL)
	{
		if (ft_isalpha(token[i][0]) == 0 && token[i][0] != '_')
			printf("minishell: export: `%s': not a valid identifier\n", \
			token[i]);
		else
		{
			j = 0;
			while (env[j] != NULL)
				j++;
			env[j] = ft_strdup(token[i]);
			env[j + 1] = NULL;
		}
	}
	return (TRUE);
}
