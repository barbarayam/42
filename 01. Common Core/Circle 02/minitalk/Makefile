# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bayam <bayam@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/26 21:50:53 by bayam             #+#    #+#              #
#    Updated: 2025/12/28 21:01:33 by bayam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME_SERVER = server
NAME_CLIENT = client
BONUS_MARKER = .bonus_done

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -I$(FT_PRINTF_PATH)
RM		= rm -f

# Paths to ft_printf
FT_PRINTF_PATH	= ./ft_printf
FT_PRINTF 		= $(FT_PRINTF_PATH)/libftprintf.a

# Mandatory Files
SRC_SERVER = server.c
SRC_CLIENT = client.c
OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

# Bonus Files
SRC_SERVER_B = server_bonus.c
SRC_CLIENT_B = client_bonus.c
OBJ_SERVER_B = $(SRC_SERVER_B:.c=.o)
OBJ_CLIENT_B = $(SRC_CLIENT_B:.c=.o)

# Default Rule
all: $(FT_PRINTF) $(NAME_SERVER) $(NAME_CLIENT)

# Compiling ft_printf with libft
$(FT_PRINTF):
	@make -C $(FT_PRINTF_PATH)

# Compiling Server - links the .a file directly
$(NAME_SERVER): $(OBJ_SERVER)
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(FT_PRINTF) -o $(NAME_SERVER)

# Compiling Client - links the .a file directly
$(NAME_CLIENT): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(FT_PRINTF) -o $(NAME_CLIENT)

# Compiling the Bonus
bonus: $(BONUS_MARKER)

$(BONUS_MARKER): $(FT_PRINTF) $(OBJ_SERVER_B) $(OBJ_CLIENT_B)
	$(CC) $(CFLAGS) $(OBJ_SERVER_B) $(FT_PRINTF) -o $(NAME_SERVER)
	$(CC) $(CFLAGS) $(OBJ_CLIENT_B) $(FT_PRINTF) -o $(NAME_CLIENT)
	@touch $(BONUS_MARKER)

# Rule for object files to prevent unnecessary recompilation
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean Object Files
clean:
	$(RM) $(OBJ_SERVER) $(OBJ_CLIENT) $(OBJ_SERVER_B) $(OBJ_CLIENT_B)
	$(RM) $(BONUS_MARKER)
	@make -C $(FT_PRINTF_PATH) clean

# Full Clean
fclean: clean
	$(RM) $(NAME_SERVER) $(NAME_CLIENT) 
	$(RM) $(BONUS_MARKER)
	@make -C $(FT_PRINTF_PATH) fclean
	
re: fclean all

.PHONY: all clean fclean re bonus