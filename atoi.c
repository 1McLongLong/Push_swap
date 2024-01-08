/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touahman <touahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:10:11 by touahman          #+#    #+#             */
/*   Updated: 2024/01/05 16:58:43 by touahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static long	ft_handle(char *s, int sign)
{
	long int	nbr;

	nbr = 0;
	while (*s >= '0' && *s <= '9' && nbr < (long) INT_MAX + 1)
	{
		nbr = nbr * 10 + (*s - '0');
		s++;
	}
	return (nbr * sign);
}

long	ft_atoi(char *s)
{
	int		sign;

	sign = 1;
	while (*s == ' ' || *s == '\n' || *s == '\v' || *s == '\f'
		|| *s == '\t' || *s == '\r')
		s++;
	if (*s == '+')
		s++;
	else if (*s == '-')
	{
		sign = -1;
		s++;
	}
	return (ft_handle(s, sign));
}
