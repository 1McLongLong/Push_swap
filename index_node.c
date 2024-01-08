/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touahman <touahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:29:59 by touahman          #+#    #+#             */
/*   Updated: 2024/01/05 17:13:42 by touahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	swap(t_node *a, t_node *b)
{
	int	tmp;

	tmp = a->data;
	a->data = b->data;
	b->data = tmp;
}

static void	sort(t_dblst *lst)
{
	int		swapped;
	t_node	*node;
	t_node	*ms_node;

	if (lst->head == NULL)
		return ;
	swapped = 1;
	ms_node = NULL;
	while (swapped)
	{
		swapped = 0;
		node = lst->head;
		while (node->next != ms_node)
		{
			if (node->data > node->next->data)
			{
				swap(node, node->next);
				swapped = 1;
			}
			node = node->next;
		}
		ms_node = node;
	}
}

static void	sort_temp_list(t_dblst *lst, t_dblst *tmpList)
{
	t_node	*current;

	current = lst->head;
	while (current != NULL)
	{
		add_to_stack(tmpList, current->data);
		current = current->next;
	}
	sort(tmpList);
}

static void	index_list(t_dblst *lst, t_dblst *tmpList)
{
	t_node	*head;
	t_node	*temp;
	int		index;

	head = lst->head;
	temp = tmpList->head;
	index = 1;
	while (temp != NULL)
	{
		head = lst->head;
		while (head != NULL)
		{
			if (head->data == temp->data)
			{
				head->index = index;
				index++;
			}
			head = head->next;
		}
		temp = temp->next;
	}
}

void	index_node(t_dblst *lst)
{
	t_dblst	tmplist;

	if (lst->head == NULL)
		return ;
	tmplist.head = NULL;
	tmplist.tail = NULL;
	sort_temp_list(lst, &tmplist);
	index_list(lst, &tmplist);
	free_stack(&tmplist, 0);
}
