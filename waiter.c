/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:58:35 by gifulvi           #+#    #+#             */
/*   Updated: 2022/05/19 17:59:13 by gifulvi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	waiter(void)
{
	static int	ao;

	if (!ao)
	{
		ao = 1;
		sleep(5);
		exit (0);
	}
	return (0);
}
