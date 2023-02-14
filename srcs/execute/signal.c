/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:02:33 by nakoo             #+#    #+#             */
/*   Updated: 2023/02/14 20:46:05 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	sigexit_handler(void)
{
	write(1, "exit\n", 5);
	exit(0);
}

void	sigint_handler(void)
{
	
}

void	sigquit_handler(void)
{
		
}
