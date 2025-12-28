# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bayam <bayam@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/10 20:57:06 by bayam             #+#    #+#              #
#    Updated: 2025/12/26 13:44:49 by bayam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

# Compiler and Flags
CC = cc 
CFLAGS = -Wall -Wextra -Werror

# Folders
SRC_DIR = src
OBJ_DIR = obj
MLX_DIR = ./minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a

SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/render.c $(SRC_DIR)/utils.c
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
HEADER = $(SRC_DIR)/ft_mlx_app.h

# *** MLX flags and includes for Linux ***
MLXFLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm
INCLUDES = -I$(MLX_DIR) -I$(SRC_DIR)

all:	$(NAME)

# *** 1. Build the library file first ***
$(MLX_LIB):
		make -C $(MLX_DIR)
		
# *** Link the executable using MLXFLAGS ***
$(NAME)	:	$(OBJ_DIR)	$(OBJS) $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@	

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re