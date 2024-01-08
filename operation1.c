/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touahman <touahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:36:15 by touahman          #+#    #+#             */
/*   Updated: 2024/01/05 21:36:57 by touahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	push_b(t_dblst *list_a, t_dblst *list_b)
{
	t_node	*popped_node;

	if (list_a->head == NULL)
		return ;
	popped_node = list_a->head;
	list_a->head = list_a->head->next;
	if (list_a->head == NULL)
		list_a->tail = NULL;
	else
		list_a->head->prev = NULL;
	popped_node->next = list_b->head;
	popped_node->prev = NULL;
	if (list_b->head == NULL)
		list_b->tail = popped_node;
	else
		list_b->head->prev = popped_node;
	list_b->head = popped_node;
	write(1, "pb\n", 3);
}

void	push_a(t_dblst *list_a, t_dblst *list_b)
{
	t_node	*popped_node;

	if (list_b->head == NULL)
		return ;
	popped_node = list_b->head;
	list_b->head = list_b->head->next;
	if (list_b->head == NULL)
		list_b->tail = NULL;
	else
		list_b->head->prev = NULL;
	popped_node->next = list_a->head;
	popped_node->prev = NULL;
	if (list_a->head == NULL)
		list_a->tail = popped_node;
	else
		list_a->head->prev = popped_node;
	list_a->head = popped_node;
	write(1, "pa\n", 3);
}

void	swap_a(t_dblst *list_a)
{
	t_node	*n1;
	t_node	*n2;

	if (list_a->head == NULL)
		return ;
	if (list_a->head != NULL && list_a->head->next != NULL)
	{
		n1 = list_a->head;
		n2 = list_a->head->next;
		n1->prev = n2;
		if (n2->next != NULL)
			n2->next->prev = n1;
		n1->next = n2->next;
		n2->next = n1;
		n2->prev = NULL;
		list_a->head = n2;
	}
	write(1, "sa\n", 3);
}

void	swap_b(t_dblst *list_b)
{
	t_node	*n1;
	t_node	*n2;

	if (list_b->head == NULL)
		return ;
	if (list_b->head != NULL && list_b->head->next != NULL)
	{
		n1 = list_b->head;
		n2 = list_b->head->next;
		n1->prev = n2;
		if (n2->next != NULL)
			n2->next->prev = n1;
		n1->next = n2->next;
		n2->next = n1;
		n2->prev = NULL;
		list_b->head = n2;
	}
	write(1, "sb\n", 3);
}

void	swap_ss(t_dblst *list_a, t_dblst *list_b)
{
	swap_a(list_a);
	swap_b(list_b);
	write(1, "ss\n", 3);
}
