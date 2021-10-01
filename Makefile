# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/15 09:44:02 by guferrei          #+#    #+#              #
#    Updated: 2021/10/01 08:45:29 by guferrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

FILES = src/push_swap.c src/push_swap_utils.c src/stack.c src/actions.c src/small_sort.c src/big_sort.c src/big_sort_utils.c

LIBFT = libft/libft.a

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(LIBFT) $(FILES)
	gcc $(FLAGS) $(FILES) $(LIBFT) -o $(NAME)

$(LIBFT): $(LIBFT)
	make -C libft
	make clean -C libft

clean:
	rm push_swap

fclean: clean
	rm libft/libft.a

re: fclean all

norma:
	norminette $(FILES)