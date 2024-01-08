/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touahman <touahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:06:52 by touahman          #+#    #+#             */
/*   Updated: 2024/01/06 12:35:33 by touahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	rotate_both(t_dblst *list_a, t_dblst *list_b,
			int *a_cost, int *b_cost)
{
	while (*a_cost > 0 && *b_cost > 0)
	{
		(*a_cost)--;
		(*b_cost)--;
		rotate_rr(list_a, list_b);
	}
}

static void	rev_rotate_both(t_dblst *list_a, t_dblst *list_b,
			int *a_cost, int *b_cost)
{
	while (*a_cost < 0 && *b_cost < 0)
	{
		(*a_cost)++;
		(*b_cost)++;
		rrotate_r(list_a, list_b);
	}
}

static void	ra(t_dblst *list_a, int *a_cost)
{
	while (*a_cost)
	{
		if (*a_cost > 0)
		{
			rotate_a(list_a, 1);
			(*a_cost)--;
		}
		else if (*a_cost < 0)
		{
			rrotate_a(list_a, 1);
			(*a_cost)++;
		}
	}
}

static void	rb(t_dblst *list_b, int *b_cost)
{
	while (*b_cost)
	{
		if (*b_cost > 0)
		{
			rotate_b(list_b, 1);
			(*b_cost)--;
		}
		else if (*b_cost < 0)
		{
			rrotate_b(list_b, 1);
			(*b_cost)++;
		}
	}
}

void	perform_moves(t_dblst *list_a, t_dblst *list_b, int a_cost, int b_cost)
{
	if (a_cost < 0 && b_cost < 0)
		rev_rotate_both(list_a, list_b, &a_cost, &b_cost);
	if (a_cost > 0 && b_cost > 0)
		rotate_both(list_a, list_b, &a_cost, &b_cost);
	ra(list_a, &a_cost);
	rb(list_b, &b_cost);
	push_a(list_a, list_b);
}
