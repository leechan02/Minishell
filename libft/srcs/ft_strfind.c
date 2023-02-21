/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:53:15 by euiclee           #+#    #+#             */
/*   Updated: 2023/02/21 17:27:40 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfind(char **str, char *find)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (str[i])
	{
		if (ft_strstr(str[i], find))
		{
			j = 0;
			while (str[i][j] != '=')
				j++;
			temp = ft_substr(str[i], 0, j + 1);
			if (ft_strcmp(temp, find) == 0)
			{
				free(temp);
				return (str[i]);
			}
			free(temp);
		}
		i++;
	}
	return (NULL);
}
