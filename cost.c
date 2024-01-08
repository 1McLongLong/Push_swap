/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touahman <touahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:47:54 by touahman          #+#    #+#             */
/*   Updated: 2023/12/28 18:20:12 by touahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	position(t_dblst *list_a, t_dblst *list_b)
{
	t_node	*head_a;
	t_node	*head_b;
	int		i;

	head_a = list_a->head;
	head_b = list_b->head;
	i = 0;
	while (head_a != NULL)
	{
		head_a->pos = i;
		head_a = head_a->next;
		i++;
	}
	i = 0;
	while (head_b != NULL)
	{
		head_b->pos = i;
		head_b = head_b->next;
		i++;
	}
}

void	cost(t_dblst *list_a, t_dblst *list_b)
{
	t_node	*head_b;
	int		size_a;
	int		size_b;

	head_b = list_b->head;
	size_a = ft_lstsize(list_a);
	size_b = ft_lstsize(list_b);
	while (head_b)
	{
		head_b->cost_b = head_b->pos;
		if (head_b->pos > size_b / 2)
			head_b->cost_b = (size_b - head_b->pos) * -1;
		head_b->cost_a = head_b->target_node;
		if (head_b->target_node > size_a / 2)
			head_b->cost_a = (size_a - head_b->target_node) * -1;
		head_b = head_b->next;
	}
}

void	cheapest_move(t_dblst *list_a, t_dblst *list_b)
{
	t_node	*tmp;
	int		cheapest;
	int		a_cost;
	int		b_cost;

	tmp = list_b->head;
	cheapest = INT_MAX;
	while (tmp)
	{
		if (ft_abs(tmp->cost_a) + ft_abs(tmp->cost_b) < ft_abs(cheapest))
		{
			cheapest = ft_abs(tmp->cost_b) + ft_abs(tmp->cost_a);
			a_cost = tmp->cost_a;
			b_cost = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	perform_moves(list_a, list_b, a_cost, b_cost);
}
