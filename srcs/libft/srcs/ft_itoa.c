/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:26:32 by euiclee           #+#    #+#             */
/*   Updated: 2022/11/22 09:31:28 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strnlen(long long n)
{
	int	len;

	len = 1;
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_convert(char *result, int n, int len)
{
	long long	num;

	num = n;
	if (n < 0)
		num *= -1;
	while (len-- && num > 9)
	{
		result[len] = num % 10 + '0';
		num /= 10;
	}
	result[len] = num % 10 + '0';
	if (n < 0)
		result[0] = '-';
	return (result);
}

char	*ft_itoa(int n)
{
	char		*result;
	int			size;
	long long	num;

	num = n;
	size = 0;
	if (num < 0)
	{
		size = 1;
		num *= -1;
	}
	size += ft_strnlen(num);
	result = (char *)ft_calloc(size + 1, sizeof(char));
	if (!result)
		return (0);
	return (ft_convert(result, n, size));
}
