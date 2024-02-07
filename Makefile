# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: touahman <touahman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/30 11:47:32 by touahman          #+#    #+#              #
#    Updated: 2024/01/05 17:14:18 by touahman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCF= operation1.c operation2.c operation3.c list_utils.c index_node.c fix_stack.c atoi.c \
			split.c push_swap.c moves.c target_node.c parse.c cost.c init_stack.c main.c
			
OBJF = $(SRCF:.c=.o)

NAME = push_swap

all : $(NAME)

$(NAME): $(OBJF)
	$(CC) $(CFLAGS) $^ -o $@ 


$(OBJF) : header.h

clean:
	rm -f $(OBJF)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
