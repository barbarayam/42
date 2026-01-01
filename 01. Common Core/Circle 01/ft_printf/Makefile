# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bayam <bayam@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/12 18:11:58 by bayam             #+#    #+#              #
#    Updated: 2025/07/20 21:08:18 by bayam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./libft
 
#library name
NAME = libftprintf.a

SRCS = ft_printf.c ft_print_str.c ft_print_ptr.c ft_print_int.c \
       ft_print_unsigned.c ft_print_hex.c ft_print_percent.c

LIBFT_DIR = libft

OBJS = $(SRCS:.c=.o)

###########--Target--###########

all: $(NAME)

#creates only mandatory files
$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/libft.a $@
	ar rcs $@ $(OBJS)

#ft_printf.h
%.o: %.c ft_printf.h
		$(CC) $(CFLAGS) -c $< -o $@

########--Clean--########
clean: 
		@rm -f $(OBJS)
		make clean -C $(LIBFT_DIR)

fclean: clean
		@rm -f $(NAME)
		make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re