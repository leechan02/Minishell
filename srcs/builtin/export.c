/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:03:03 by nakoo             #+#    #+#             */
/*   Updated: 2023/02/06 19:11:49 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	print_export(char **env)
{
}

void	ft_export(char *str, char **env)
{
	int	i;

	i = 0;
	if (*(str + i) == '\0')
		return (print_export(env));
	else if (ft_isalpha(*(str + i)) == 0)
	{
		printf("minishell: export: `%s': not a valid identifier\n", str);
		return ;
	}
}
