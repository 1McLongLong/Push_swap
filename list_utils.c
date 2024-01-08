/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touahman <touahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:29:44 by touahman          #+#    #+#             */
/*   Updated: 2023/12/29 21:51:58 by touahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_node	*create_stack(int data)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		return (NULL);
	new_node->data = data;
	new_node->index = 0;
	new_node->pos = 0;
	new_node->target_node = 0;
	new_node->cost_a = 0;
	new_node->cost_b = 0;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

void	add_to_stack(t_dblst *list, int data)
{
	t_node	*new_node;

	new_node = create_stack(data);
	if (list->head == NULL)
	{
		list->head = new_node;
		list->tail = new_node;
	}
	else
	{
		new_node->prev = list->tail;
		list->tail->next = new_node;
		list->tail = new_node;
	}
}

int	ft_lstsize(t_dblst *lst)
{
	t_node	*temp;
	int		size;

	temp = lst->head;
	size = 0;
	while (temp != NULL)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}

int	stack_sorted(t_dblst *stack)
{
	t_node	*head;

	head = stack->head;
	if (stack->head == NULL)
		return (0);
	while (head->next)
	{
		if (head->data > head->next->data)
			return (0);
		head = head->next;
	}
	return (1);
}

void	free_stack(t_dblst *list, int flag)
{
	t_node	*current;
	t_node	*next;

	current = list->head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	list->head = NULL;
	list->tail = NULL;
	if (flag == 1)
	{
		write(STDERR_FILENO, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}
