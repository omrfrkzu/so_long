CFLAGS      = -Wall -Wextra -Werror -I.
SRC_DIR     = codes
GNL_DIR     = get_next_line
MLX_DIR     = minilibx-linux
IMG_DIR     = images
MAP_DIR     = maps
OBJ_DIR     = obj

SRC_FILES = $(SRC_DIR)/so_long.c \
            $(GNL_DIR)/get_next_line.c \
            $(GNL_DIR)/get_next_line_utils.c \
            $(SRC_DIR)/map_control.c\
            $(SRC_DIR)/map_check_routes.c\
            $(SRC_DIR)/location_checker.c\
            $(SRC_DIR)/data_setup.c\
            $(SRC_DIR)/dfs_function.c\
            $(SRC_DIR)/keys.c\
            $(SRC_DIR)/navigator.c\
            $(SRC_DIR)/utils.c\
            $(SRC_DIR)/render.c\
            $(SRC_DIR)/error.c\
            $(SRC_DIR)/map_search.c

OBJ_FILES = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

NAME = so_long
MLX_LIB = $(MLX_DIR)/libmlx.a

all: $(NAME)

$(NAME): $(OBJ_FILES) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJ_FILES) -L$(MLX_DIR) -L. -lmlx -lX11 -lXext -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(MLX_LIB):
	@make -C $(MLX_DIR)

clean:
	rm -rf $(OBJ_DIR)
	@make clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
