# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/15 09:44:02 by guferrei          #+#    #+#              #
#    Updated: 2021/10/06 13:31:00 by guferrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_BONUS = checker

FILES = src/push_swap.c src/push_swap_utils.c src/stack.c src/actions.c src/small_sort.c src/big_sort.c src/big_sort_utils.c

BONUS = checker_files/src/checker.c checker_files/src/checker_actions.c checker_files/src/checker_utils.c \
		checker_files/get_next_line/get_next_line.c checker_files/get_next_line/get_next_line_utils.c \
		checker_files/src/checker_instructions.c

LIBFT = libft/libft.a

FLAGS = -Wall -Werror -Wextra

all: $(NAME) bonus

$(NAME): $(LIBFT) $(FILES)
	gcc $(FLAGS) $(FILES) $(LIBFT) -o $(NAME)

bonus: $(LIBFT) $(BONUS)
	gcc $(FLAGS) $(BONUS) $(LIBFT) -o $(NAME_BONUS)

$(LIBFT): $(LIBFT)
	make -C libft
	make clean -C libft

clean:
	rm push_swap
	rm checker

fclean: clean
	rm libft/libft.a

re: fclean all

norma:
	norminette $(FILES)