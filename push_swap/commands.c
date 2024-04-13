/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperperi <eperperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:01:55 by eperperi          #+#    #+#             */
/*   Updated: 2024/04/13 20:06:24 by eperperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(long *a, int len)
{
	long	temp;

	if (len != 0 || len != 1)
	{
		temp = a[0];
		a[0] = a[1];
		a[1] = temp;
	}
	// ft_printf("sa");
}

void	sb(long *b, int len)
{
	long	temp;

	if (len != 0 || len != 1)
	{
		temp = b[0];
		b[0] = b[1];
		b[1] = temp;
	}
}

void	ss(long *b, long *a, int len)
{
	long	temp;

	if (len != 0 || len != 1)
	{
		temp = a[0];
		a[0] = a[1];
		a[1] = temp;
	}
	if (len != 0 || len != 1)
	{
		temp = b[0];
		b[0] = b[1];
		b[1] = temp;
	}
}
