# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmouette <jmouette@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/02 13:11:19 by jmouette          #+#    #+#              #
#    Updated: 2024/08/08 16:19:14 by jmouette         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= so_long
NAME_BONUS		= so_long_bonus

CC				= cc

CFLAGS			= -Wextra -Wall -Werror
MLX_FLAGS		= -lglfw -ldl -pthread -lm

LIBFT			= ./libft/libft.a
LIBFT_DIR		= ./libft

MLX42_DIR		= MLX42
MLX42_BUILD_DIR	= MLX42/build
MLX42			= $(MLX42_BUILD_DIR)/libmlx42.a

HEADER			= ./src/so_long.h
HEADER_BONUS	= ./src_bonus/so_long_bonus.h

SRCS			= so_long.c check_map.c draw_map.c read_map.c exit_free_game.c init_game.c \
				init_hooks.c player.c is_accessible.c

SRCS_BONUS		= so_long_bonus.c check_map_bonus.c draw_map_bonus.c read_map_bonus.c \
				exit_free_game_bonus.c init_game_bonus.c init_hooks_bonus.c player_bonus.c \
				is_accessible_bonus.c moves_bonus.c put_ennemies_bonus.c

SOURCES_DIR		=	src
BONUS_DIR		=	src_bonus

FILES			= $(addprefix $(SOURCES_DIR)/, $(SRCS))
BONUS_FILES		= $(addprefix $(BONUS_DIR)/, $(SRCS_BONUS))

OBJS			= ${FILES:.c=.o}
OBJS_BONUS		= ${BONUS_FILES:.c=.o}


%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAME) $(NAME_BONUS)

bonus: $(NAME_BONUS)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX42_BUILD_DIR)/libmlx42.a:
	@mkdir -p $(MLX42_BUILD_DIR)
	@cd $(MLX42_DIR) && cmake -B build && cmake --build build -j4

$(NAME): $(LIBFT) $(MLX42) $(OBJS) $(HEADER)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX42) $(MLX_FLAGS) -o $(NAME)
	@echo "so_long compiled"

$(NAME_BONUS): $(LIBFT) $(MLX42) $(OBJS_BONUS) $(HEADER_BONUS)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) $(MLX42) $(MLX_FLAGS) -o $(NAME_BONUS)
	@echo "so_long_bonus compiled"

clean:
	@rm -rf $(OBJS) $(OBJS_BONUS)
	@rm -rf $(MLX42_BUILD_DIR) clean
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -rf $(NAME) $(NAME_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re rebonus libft mlx42 bonus
