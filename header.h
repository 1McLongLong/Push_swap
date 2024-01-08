/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touahman <touahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 10:51:46 by touahman          #+#    #+#             */
/*   Updated: 2024/01/06 12:35:05 by touahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct node
{
	int			target_node;
	int			index;
	int			pos;
	int			data;
	int			cost_a;
	int			cost_b;
	struct node	*prev;
	struct node	*next;
}				t_node;

typedef struct d_node
{
	t_node	*head;
	t_node	*tail;
}		t_dblst;

int		check_space(char *str);
void	ft_free(char **lst);
int		ft_abs(int x);
int		ft_strlen(char *s);
long	ft_atoi(char *str);
char	**split(char *s, char c);
int		count_words(char *str, char c);
char	**parse_args(int argc, char **argv);
void	init_stack(t_dblst *lst, char **str);
void	add_to_stack(t_dblst *list, int data);
t_node	*create_stack(int data);
int		ft_lstsize(t_dblst *lst);
int		stack_sorted(t_dblst *stack);
void	printList(t_dblst *list);
t_node	*min_node(t_dblst *lst);
void	index_node(t_dblst *lst);
void	position(t_dblst *list_a, t_dblst *list_b);
void	target_node(t_dblst *list_a, t_dblst *list_b);
void	cost(t_dblst *list_a, t_dblst *list_b);
void	cheapest_move(t_dblst *list_a, t_dblst *list_b);
void	perform_moves(t_dblst *list_a, t_dblst *list_b,
			int a_cost, int b_cost);
void	fix_stack(t_dblst *list_a);
void	push_swap(t_dblst *list_a, t_dblst *list_b);
void	free_stack(t_dblst *list, int flag);
void	push_b(t_dblst *list_a, t_dblst *list_b);
void	push_a(t_dblst *list_a, t_dblst *list_b);
void	swap_a(t_dblst *list_a);
void	swap_b(t_dblst *list_b);
void	swap_ss(t_dblst *list_a, t_dblst *list_b);
void	rotate_a(t_dblst *list_a, int flag);
void	rotate_b(t_dblst *list_b, int flag);
void	rotate_rr(t_dblst *list_a, t_dblst *list_b);
void	rrotate_a(t_dblst *list_a, int flag);
void	rrotate_b(t_dblst *list_a, int flag);
void	rrotate_r(t_dblst *list_a, t_dblst *list_b);
void	sort_3_n(t_dblst *list_a);
void	sort_n_n(t_dblst *list_a, t_dblst *list_b);

#endif
