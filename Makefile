# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/28 19:18:15 by sarchoi           #+#    #+#              #
#    Updated: 2022/09/01 20:41:24 by sarchoi          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re $(LIBFT) $(NAME)

NAME = cub3d

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS_ROOT = main.c \
			map.c \
			map_parse.c \
			map_parse_read_colors.c \
			map_parse_read_map.c \
			map_parse_read_textures.c \
			map_validate.c \
			map_validate_char.c \
			map_validate_walls.c \
			map_validate_empty.c \
			get_map_array.c \
			graphic_init.c \
			draw_frame.c \
			find_map_start_line.c \
			free.c \
			put_screen.c \
			key_hook.c \
			calc_rotated_vector.c \
			player.c \
			init_player.c
SRCS_UTIL = global.c \
			draw.c \
			draw_pixel.c \
			mlx_image.c \
			put_image.c \
			get_image.c \
			exit.c \
			dda_algo.c \
			print.c
SRCS = $(addprefix ./src/, $(SRCS_ROOT)) \
			$(addprefix ./src/utils/, $(SRCS_UTIL))
SRCS_ONLY_BONUS = put_minimap_floor_bonus.c \
			put_minimap_player_bonus.c \
			put_minimap_ray_bonus.c \
			put_minimap_line_bonus.c \
			put_minimap_tiles_bonus.c \
			set_fire_texture_bonus.c \
			bres_algo_bonus.c \
			mouse_hook_bonus.c
SRCS_BONUS = $(addprefix ./src_bonus/, $(SRCS_ONLY_BONUS)) \
			$(addprefix ./src_bonus/, $(SRCS_ROOT:.c=_bonus.c)) \
			$(addprefix ./src_bonus/utils/, $(SRCS_UTIL:.c=_bonus.c))

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

ifdef BONUS
	OBJECTS = $(OBJS_BONUS)
else
	OBJECTS = $(OBJS)
endif

MLX = minilibx
MLX_FLAGS = -L libs/minilibx -lmlx -framework OpenGl -framework AppKit

LIBFT = libft
LIBFT_FLAGS = -L libs/libft -lft

SRCS_GNL = libs/get_next_line/get_next_line_utils.c \
		   libs/get_next_line/get_next_line.c
OBJS_GNL = $(SRCS_GNL:.c=.o)
GNL = get_next_line

INC_FLAGS = -I includes -I libs/$(LIBFT) -I libs/$(GNL) -I libs/$(MLX)

green:=$(shell tput setaf 2)
reset:=$(shell tput sgr0)

all: $(LIBFT) $(MLX) $(NAME)

bonus:
	make BONUS=1 all

$(NAME): $(OBJECTS) $(OBJS_GNL)
	$(info $(green)<MAKE> NAME$(reset))
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT_FLAGS) $(MLX_FLAGS)
	install_name_tool -change libmlx.dylib $(CURDIR)/libs/$(MLX)/libmlx.dylib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INC_FLAGS)
	$(info $(green)<MAKE> $(<) -> $(@)$(reset))

$(LIBFT):
	make all --directory=libs/$(LIBFT)

$(MLX):
	make --directory=libs/$(MLX)

clean:
	@make clean --directory=libs/$(LIBFT)
	$(info $(green)<MAKE> Libft - clean$(reset))
	@make clean --directory=libs/$(MLX)
	$(info $(green)<MAKE> MinilibX - clean$(reset))
	rm -f $(OBJS) $(OBJS_BONUS) $(OBJS_GNL)
	$(info $(green)<MAKE> clean$(reset))

fclean: clean
	make fclean --directory=libs/$(LIBFT)
	$(info $(green)<MAKE> Libft - fclean$(reset))
	rm -f $(NAME)
	rm -rf $(NAME).dSYM
	rm -rf libs/minilibx/*.swiftsourceinfo
	$(info $(green)<MAKE> fclean$(reset))

re: fclean all
	$(info $(red)<MAKE> re$(reset))
