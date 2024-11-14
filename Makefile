# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irkalini <irkalini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 12:12:06 by irkalini          #+#    #+#              #
#    Updated: 2024/11/05 16:29:20 by irkalini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server

SRCS_C = client.c
SRCS_S = server.c
OBJS_C = $(SRCS_C:.c=.o)
OBJS_S = $(SRCS_S:.c=.o)

LIBFT_DIR = ./libft
LIBFT_A = ./libft/libft.a

FT_PRINTF_DIR = ./ft_printf
FT_PRINTF_A = ./ft_printf/libftprintf.a

CC = cc

CCFLAGS = -Wall -Wextra -Werror

all: $(LIBFT_A) $(FT_PRINTF_A) $(SERVER) $(CLIENT)

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

$(SERVER): $(OBJS_S)
	$(CC) $(CCFLAGS) -o $(SERVER) $(OBJS_S) $(LIBFT_A) $(FT_PRINTF_A)

$(CLIENT): $(OBJS_C)
	$(CC) $(CCFLAGS) -o $(CLIENT) $(OBJS_C) $(LIBFT_A) $(FT_PRINTF_A)

$(LIBFT_A):
	make -C $(LIBFT_DIR)

$(FT_PRINTF_A):
	make -C $(FT_PRINTF_DIR)

clean:
	rm -f $(OBJS_S)
	rm -f $(OBJS_C)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(FT_PRINTF_DIR)

fclean: clean
	rm -f $(SERVER)
	rm -f $(CLIENT)
	rm -f $(FT_PRINTF_A)
	rm -f $(LIBFT_A)

re: fclean all
