/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touahman <touahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 10:25:52 by touahman          #+#    #+#             */
/*   Updated: 2024/01/07 12:19:58 by touahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"	

int	main(int argc, char **argv)
{
	char	**args_list;
	t_dblst	alist;
	t_dblst	blist;

	alist.head = NULL;
	alist.tail = NULL;
	blist.head = NULL;
	blist.tail = NULL;
	if (argc == 1)
		return (0);
	else if ((argc == 2 && !argv[1][0]))
		return (write(STDERR_FILENO, "Error\n", 6), 0);
	args_list = parse_args(argc, argv);
	if (!args_list)
		return (ft_free(args_list), 0);
	init_stack(&alist, args_list);
	if (!(stack_sorted(&alist)))
	{
		index_node(&alist);
		push_swap(&alist, &blist);
	}
	free_stack(&alist, 0);
	ft_free(args_list);
	return (0);
}
