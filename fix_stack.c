/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touahman <touahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:07:18 by touahman          #+#    #+#             */
/*   Updated: 2024/01/06 13:07:06 by touahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

t_node	*min_node(t_dblst *lst)
{
	t_node	*min_node;
	t_node	*tmp;

	if (lst->head == NULL)
		return (NULL);
	tmp = lst->head;
	min_node = lst->head->next;
	while (tmp)
	{
		if (tmp->data < min_node->data)
			min_node = tmp;
		tmp = tmp->next;
	}
	return (min_node);
}

static void	fix_pos(t_dblst *lst)
{
	t_node	*head_a;
	int		i;

	head_a = lst->head;
	i = 0;
	while (head_a != NULL)
	{
		head_a->pos = i;
		head_a = head_a->next;
		i++;
	}
}

void	fix_stack(t_dblst *list_a)
{
	t_node	*lowest_node;
	int		stack_size;
	int		lowest_pos;

	fix_pos(list_a);
	stack_size = ft_lstsize(list_a);
	lowest_node = min_node(list_a);
	lowest_pos = lowest_node->pos;
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
		{
			rrotate_a(list_a, 1);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			rotate_a(list_a, 1);
			lowest_pos--;
		}
	}
}
