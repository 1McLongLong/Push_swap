/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touahman <touahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:50:17 by touahman          #+#    #+#             */
/*   Updated: 2024/01/05 21:30:54 by touahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	rrotate_a(t_dblst *list_a, int flag)
{
	t_node	*lastnode;
	t_node	*beforelastnode;

	if (list_a->head == NULL || list_a->head->next == NULL)
		return ;
	lastnode = list_a->tail;
	beforelastnode = lastnode->prev;
	lastnode->next = list_a->head;
	list_a->head->prev = lastnode;
	list_a->head = lastnode;
	beforelastnode->next = NULL;
	list_a->tail = beforelastnode;
	lastnode->prev = NULL;
	if (flag == 1)
		write(1, "rra\n", 4);
}

void	rrotate_b(t_dblst *list_b, int flag)
{
	t_node	*beforelastnode;
	t_node	*lastnode;

	if (list_b->head == NULL || list_b->head->next == NULL)
		return ;
	lastnode = list_b->tail;
	beforelastnode = lastnode->prev;
	lastnode->next = list_b->head;
	list_b->head->prev = lastnode;
	list_b->head = lastnode;
	beforelastnode->next = NULL;
	list_b->tail = beforelastnode;
	lastnode->prev = NULL;
	if (flag == 1)
		write(1, "rrb\n", 4);
}

void	rrotate_r(t_dblst *list_a, t_dblst *list_b)
{
	rrotate_a(list_a, 0);
	rrotate_b(list_b, 0);
	write(1, "rrr\n", 4);
}

int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	else
		return (x);
}
