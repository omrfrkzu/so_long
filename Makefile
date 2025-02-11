CFLAGS		= -Wall -Wextra -Werror -I.
SRC_DIR		= src
GNL_DIR		= get_next_line
MLX_DIR		= minilibx-linux
TEX_DIR		= textures
MAP_DIR		= maps

SRC_FILES = $(SRC_DIR)/main.c \
			$(GNL_DIR)/get_next_line.c \
			$(GNL_DIR)/get_next_line_utils.c \
			$(SRC_DIR)/check_map.c\
			$(SRC_DIR)/check_paths.c\
			$(SRC_DIR)/check_pos.c\
			$(SRC_DIR)/draw.c\
			$(SRC_DIR)/error.c\
			$(SRC_DIR)/find_in_map.c\
			$(SRC_DIR)/import_data.c\
			$(SRC_DIR)/import_dfs.c\
			$(SRC_DIR)/keys.c\
			$(SRC_DIR)/pathfinder.c\
			$(SRC_DIR)/utils.c\

OBJ_FILES = $(SRC_FILES:.c=.o)

NAME = so_long

MLX_LIB = $(MLX_DIR)/libmlx.a
all: $(NAME)

$(NAME): $(OBJ_FILES) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJ_FILES) -L$(MLX_DIR) -L. -lmlx -lX11 -lXext  -o $(NAME)

$(MLX_LIB):
	@make -C $(MLX_DIR)

clean:
	rm -f $(OBJ_FILES)
	@make clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re