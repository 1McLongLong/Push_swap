/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touahman <touahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:06:17 by touahman          #+#    #+#             */
/*   Updated: 2024/01/05 18:40:23 by touahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sort_3_n(t_dblst *list_a)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	first = list_a->head;
	second = first->next;
	third = second->next;
	if (first->data > second->data && second->data > third->data)
	{
		rotate_a(list_a, 1);
		swap_a(list_a);
	}
	else if (first->data > third->data && third->data < second->data)
		rrotate_a(list_a, 1);
	else if (second->data < first->data && first->data > third->data)
		rotate_a(list_a, 1);
	else if (second->data > third->data && third->data > first->data)
	{
		rrotate_a(list_a, 1);
		swap_a(list_a);
	}
	else if (third->data > first->data && first->data > second->data)
		swap_a(list_a);
}

void	sort_n_n(t_dblst *list_a, t_dblst *list_b)
{
	int	size;
	int	i;
	int	pushed;

	i = 0;
	pushed = 0;
	size = ft_lstsize(list_a);
	while (size > 4 && i < size && pushed < size / 2)
	{
		if (list_a->head->index <= size / 2)
		{
			push_b(list_a, list_b);
			pushed++;
		}
		else
			rotate_a(list_a, 1);
		i++;
	}
	size = ft_lstsize(list_a);
	while (size > 3)
	{
		push_b(list_a, list_b);
		size--;
	}
	sort_3_n(list_a);
}

void	push_swap(t_dblst *list_a, t_dblst *list_b)
{
	if (ft_lstsize(list_a) == 2 && !stack_sorted(list_a))
		swap_a(list_a);
	else if (ft_lstsize(list_a) == 3 && !stack_sorted(list_a))
		sort_3_n(list_a);
	else if (ft_lstsize(list_a) > 3)
	{
		sort_n_n(list_a, list_b);
		while (list_b->head)
		{
			position(list_a, list_b);
			target_node(list_a, list_b);
			cost(list_a, list_b);
			cheapest_move(list_a, list_b);
		}
	}
	if (!(stack_sorted(list_a)))
		fix_stack(list_a);
}
