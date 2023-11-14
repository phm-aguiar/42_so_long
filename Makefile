NAME = so_long
LIBFT = ./libs/libft/libft.a
MLX = ./libs/MLX42/build/libmlx42.a
MFLAGS = -Iinclude -ldl -lglfw -pthread -lm
CFLAGS = -Wall -Wextra -Werror -O3 -g3

LIBFT_PATH = libs/libft
MLX_PATH = libs/MLX42
OBJ_PATH = ./obj
SRC_PATH = ./src

GREEN = \033[1;32m
RED = \033[1;31m
CYAN = \033[1;35m
RESET = \033[0m

CFILES = assets_init.c init.c main.c \
		map_maker.c map_validator.c \
		miniprintf.c mlx_loader.c \
		mlx_move.c mlx_so_long.c \
		mlx_verify_move.c

OBJECTS = $(addprefix $(OBJ_PATH)/, $(CFILES:.c=.o))

INCLUDES = -I ./includes

all: libft $(MLX) $(OBJ_PATH) $(NAME)

libft:
	@make -C $(LIBFT_PATH) --no-print-directory

$(MLX):
	@cd libs/MLX42 && cmake -B build -DDEBUG=1
	@cd libs/MLX42 && cmake --build build -j4

$(NAME): $(OBJECTS)
	@printf "\n$(CYAN)Creating $(NAME)$(RESET)\n\n"
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(MLX) -o $(NAME) $(INCLUDES) $(MFLAGS)

$(OBJECTS): $(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@printf "$(GREEN)Compiling $(notdir $(<))$(RESET)\n"
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

clean:
	@rm -f $(OBJECTS) -r $(OBJ_PATH)
	@make -C $(LIBFT_PATH) clean --no-print-directory
	@cd libs/MLX42 && cmake --build build --target clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT_PATH) fclean --no-print-directory
	@cd libs/MLX42 && cmake --build build --target clean

re: fclean
	@make all --no-print-directory

.PHONY: all clean fclean re libft