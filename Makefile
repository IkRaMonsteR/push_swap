# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irkalini <irkalini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 12:47:41 by irkalini          #+#    #+#              #
#    Updated: 2024/10/22 21:31:41 by irkalini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = push_swap.c init.c split.c errors.c sa_sb_ss_swap.c pa_pb_push.c \
		ra_rb_rr_rotate.c rra_rrb_rrr_reverse.c sort_stack.c utils.c \
		sort_more.c

OBJS = $(SRCS:.c=.o)

FT_PRINTF_A = ./lib/ft_printf/libftprintf.a
FT_PRINTF_DIR = ./lib/ft_printf

LIBFT_A = ./lib/libft/libft.a
LIBFT_DIR = ./lib/libft

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(FT_PRINTF_A) $(LIBFT_A) $(NAME)

%.o: %.C
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_A) $(FT_PRINTF_A)

$(FT_PRINTF_A):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(FT_PRINTF_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT_A)
	rm -f $(FT_PRINTF_A)

re: fclean all

.PHONY: all clean fclean re
