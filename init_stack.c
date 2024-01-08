/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touahman <touahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:11:09 by touahman          #+#    #+#             */
/*   Updated: 2024/01/06 12:33:56 by touahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

static int	check_syntax(char *str)
{
	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	if (!(*str == '+' || *str == '-' || (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '+' || *str == '-') && !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	str++;
	while (*str)
	{
		if ((*str >= '0' && *str <= '9') || (*str == '\t' || *str == ' '))
			str++;
		else
			return (1);
	}
	return (0);
}

static int	check_duplicate(t_dblst *list_a, int n)
{
	t_node	*tmp;

	tmp = list_a->head;
	if (!(tmp))
		return (0);
	while (tmp)
	{
		if (tmp->data == n)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	init_stack(t_dblst *lst, char **str)
{
	long	n;
	int		i;

	i = 0;
	while (str[i])
	{
		if (check_syntax(str[i]))
			free_stack(lst, 1);
		n = ft_atoi(str[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_stack(lst, 1);
		if (check_duplicate(lst, (int)n))
			free_stack(lst, 1);
		if (check_space(str[i]))
			free_stack(lst, 1);
		add_to_stack(lst, n);
		i++;
	}
}
