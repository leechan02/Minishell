/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:53:15 by euiclee           #+#    #+#             */
/*   Updated: 2022/12/15 14:58:17 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfind(char **str, char *find)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strstr(str[i], find))
			return (str[i]);
		i++;
	}
	return (NULL);
}
