/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 09:39:56 by euiclee           #+#    #+#             */
/*   Updated: 2023/02/07 17:54:06 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	*replace_env(char *loca, char *origin)
{

}

char	**check_env(char *line, char **env)
{
	char	**ret;
	char	*loca;
	int		i;

	i = 0;
	ret = ft_split(line, ' ');
	while (ret[i])
	{
		loca = ret[i];
		while (loca)
		{
			loca = ft_strchr(loca, '$');
			if (!loca && (ft_isalnum(*(++loca)) || *loca == '_'))
			{
				if (ft_isdigit(*loca))
					ft_memmove(loca - 1, loca + 1, ft_strlen(loca));
				else
					ret[i] = replace_env(loca, ret[i]);
			}
			loca = ret[i];
		}
		i++;
	}
	return (ret);
}
