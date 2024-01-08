/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touahman <touahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:39:01 by touahman          #+#    #+#             */
/*   Updated: 2024/01/05 20:54:51 by touahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	rotate_a(t_dblst *list_a, int flag)
{
	t_node	*last_node;

	last_node = list_a->tail;
	if (list_a->head == NULL || list_a->head->next == NULL)
		return ;
	last_node->next = list_a->head;
	list_a->head->prev = last_node;
	list_a->tail = list_a->head;
	list_a->head = list_a->head->next;
	list_a->head->prev = NULL;
	last_node->next->next = NULL;
	if (flag == 1)
		write(1, "ra\n", 3);
}

void	rotate_b(t_dblst *list_b, int flag)
{
	t_node	*last_node;

	last_node = list_b->tail;
	if (list_b->head == NULL || list_b->head->next == NULL)
		return ;
	last_node->next = list_b->head;
	list_b->head->prev = last_node;
	list_b->tail = list_b->head;
	list_b->head = list_b->head->next;
	list_b->head->prev = NULL;
	last_node->next->next = NULL;
	if (flag == 1)
		write(1, "rb\n", 3);
}

void	rotate_rr(t_dblst *list_a, t_dblst *list_b)
{
	rotate_a(list_a, 0);
	rotate_b(list_b, 0);
	write(1, "rr\n", 3);
}
