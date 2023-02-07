/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:03:03 by nakoo             #+#    #+#             */
/*   Updated: 2023/02/07 20:23:56 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	swap(int *a, int *b)
{
	if (a == b)
		return ;
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

void	sort_ascii(int *sorted_idx, char **env)
{
	int	idx;
	int	i;
	int	j;

	idx = 0;
	while (env[idx] != NULL)
	{
		sorted_idx[idx] = idx;
		idx++;
	}
	i = 0;
	while (i < idx - 1)
	{
		j = i + 1;
		while (j < idx)
		{
			if (ft_strcmp(env[sorted_idx[i]], env[sorted_idx[j]]) > 0)
				swap(&sorted_idx[i], &sorted_idx[j]);
			j++;
		}
		i++;
	}
}

void	print_export(char **env)
{
	int	*sorted_idx;
	int	idx;
	int	i;
	int	j;

	idx = -1;
	while (env[++idx] != NULL)
	sorted_idx = (int *)malloc(sizeof(int) * idx);
	sort_ascii(sorted_idx, env);
	i = -1;
	while (++i < idx)
	{
		j = -1;
		printf("declare -x ");
		while (env[sorted_idx[i]][++j] != '\0')
		{
			if (env[sorted_idx[i]][j] == '=')
				printf("=\"");
			else
				printf("%c", env[sorted_idx[i]][j]);
		}
		printf("\"\n");
	}
	free(sorted_idx);
}

void	ft_export(char *str, char **env)
{
	int	i;

	i = 0;
	if (str == NULL || *(str + i) == '\0')
		return (print_export(env));
	else if (ft_isalpha(*(str + i)) == 0 && *(str + i) != '_')
	{
		printf("minishell: export: `%s': not a valid identifier\n", str);
		return ;
	}
}
