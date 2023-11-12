# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/12 17:58:44 by phenriq2          #+#    #+#              #
#    Updated: 2023/11/12 18:46:14 by phenriq2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#******************************************************************************#
#								  CONFIGURATION				       			   #
#******************************************************************************#

NAME = so_long

LIBFT = includes/libft/libft.a
MLX = MLX42/build/libmlx42.a

SHELL := /bin/bash
COUNT := 0

BLACK  		 = \033[0;30m
RED    		 = \033[0;31m
GREEN  		 = \033[0;32m
YELLOW 		 = \033[0;33m
BLUE   		 = \033[0;34m
MAGENTA		 = \033[0;35m
CYAN   		 = \033[0;36m
WHITE  		 = \033[0;37m
RESET  		 = \033[0m

MFLAGS = -ldl -lglfw -pthread -lm
CFLAGS = -Wall -Wextra -Werror -g3 #-O3

SRC = src
INC = includes
OBJ = obj
LIBFT_PATH = includes/libft

define eraseBins
	$(if $(NAME),@$(RM) $(NAME))
	$(if $(BLIBNAME),@$(RM) $(BLIBNAME))
endef

#******************************************************************************#
#				     				FILES      								   #
#******************************************************************************#

CFILES = $(addprefix $(SRC)/, assets_init.c init.c main.c map_maker.c map_validator.c miniprintf.c mlx_loader.c \
mlx_move.c mlx_so_long.c mlx_verify_move.c)

BFILES ?=

OBJ_DIR = obj

OBJECT =  $(patsubst %, $(OBJ)/%, $(notdir $(CFILES:.c=.o)))

INCLUDES = -I./ -I./includes/libft -I./includes/MLX42/include/MLX42
LINCLUDES = -L./includes/libft -lft
MLX = includes/MLX42/build/libmlx42.a

ifdef WITH_BONUS
	CFILES = $(BFILES)
endif

all: $(OBJ) $(NAME)

$(NAME): $(MLX) $(OBJECT)
	@$(MAKE) -sC $(LIBFT_PATH)
	@$(CC) $(OBJECT) $(INCLUDES)  $(LIBFT) $(MLX) $(LINCLUDES) $(CFLAGS) $(MFLAGS) -o $(NAME)
	@$(SLEEP)
	@printf "\n$(MAGENTA)$(MANDATORY)\n$(RESET)"

$(OBJ):
	@mkdir -p $(OBJ)

.SILENT:
$(MLX):
	@cd MLX42 && cmake -B build -DDEBUG=1
	@cd MLX42 && cmake --build build -j4

$(OBJ)/%.o: $(SRC)/%.c
	@$(eval COUNT=$(shell expr $(COUNT) + 1))
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@printf "$(GREEN)$(LIBNAME) $(COMP) %d%%\r$(RESET)" $$(echo $$(($(COUNT) * 100 / $(words $(CFILES)))))

clean:
	@$(MAKE) fclean -sC $(LIBFT_PATH)
	@$(RM) -rf $(OBJ)/
	@$(SLEEP)
	@printf "$(RED)$(CLEAN)$(RESET)\n"

fclean: clean
	$(call eraseBins)
	@$(SLEEP)
	@printf "$(RED)$(FCLEAN)$(RESET)\n"

re: fclean all

bonus:
	@make WITH_BONUS=TRUE --no-print-directory

debbug:
	@make WITH_DEBBUG=TRUE --no-print-directory

.PHONY: all bonus clean fclean re debbug