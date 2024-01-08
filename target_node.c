/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touahman <touahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:17:03 by touahman          #+#    #+#             */
/*   Updated: 2024/01/04 18:28:27 by touahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	update_target_node(t_node *head_b, t_node *head_a, int size_list_a)
{
	int	min_diff;
	int	diff;
	int	j;

	min_diff = INT_MAX;
	j = 0;
	while (j < size_list_a)
	{
		diff = head_a->index - head_b->index;
		if (diff > 0 && diff < min_diff)
		{
			head_b->target_node = head_a->pos;
			min_diff = diff;
		}
		head_a = head_a->next;
		j++;
	}
}

void	target_node(t_dblst *list_a, t_dblst *list_b)
{
	t_node	*mini_node;
	t_node	*head_a;
	t_node	*head_b;
	t_node	*temp_b;
	int		i;

	head_a = list_a->head;
	head_b = list_b->head;
	temp_b = head_b;
	i = 0;
	while (i < ft_lstsize(list_b))
	{
		temp_b->target_node = INT_MAX;
		update_target_node(temp_b, head_a, ft_lstsize(list_a));
		if (temp_b->target_node == INT_MAX)
		{
			mini_node = min_node(list_a);
			temp_b->target_node = mini_node->pos;
		}
		temp_b = temp_b->next;
		i++;
	}
}
