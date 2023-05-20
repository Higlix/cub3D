

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
RESET = [0m
BOLD = [1m

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc -I lib/libft/inc -I lib/minilibx
LIB_DIR = lib
LIBFT_DIR = libft
MLX_DIR = minilibx

SRC += $(wildcard $(SRC_DIR)/window/*.c)
SRC += $(wildcard $(SRC_DIR)/config/*.c)
SRC += $(wildcard $(SRC_DIR)/image/*.c)
SRC += $(wildcard $(SRC_DIR)/input/*.c)
SRC += $(wildcard $(SRC_DIR)/render/*.c)
SRC += $(wildcard $(SRC_DIR)/player/*.c)
SRC += $(wildcard $(SRC_DIR)/map/*.c)
SRC += $(wildcard $(SRC_DIR)/debug/*.c)
SRC += $(wildcard $(SRC_DIR)/game/*.c)
SRC += $(wildcard $(SRC_DIR)/*.c)

OBJ += $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIB = lib/minilibx/libmlx.a lib/libft/libft.a
CC = gcc
#CFLAGS = -Wall -Werror -Wextra -I $(INC_DIR)
CFLAGS = -I $(INC_DIR)
NAME = cub3d

all: $(OBJ_DIR) $(LIB) $(NAME)

$(OBJ_DIR):
	@mkdir -p $@
	@mkdir -p $@/map
	@mkdir -p $@/config
	@mkdir -p $@/window
	@mkdir -p $@/image
	@mkdir -p $@/input
	@mkdir -p $@/render
	@mkdir -p $@/player
	@mkdir -p $@/game
	@mkdir -p $@/debug
	@echo "$(MAGENTA)Object directories created..."

$(LIB):
	@make -C lib/$(MLX_DIR)
	@make -C lib/$(LIBFT_DIR)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(LIB) -framework OpenGL -framework Appkit
	@mkdir -p bin
	@mv $(NAME) bin
	@echo "$(GREEN)Compiled { $(CYAN)$(NAME) $(GREEN)}"

$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) -c $< -o $@ $(CFLAGS) 
	@echo "$(GREEN)Compiled {$(RED) $@ $(GREEN)}"

src: clean all

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf bin
	@echo "$(YELLOW)Object directory $(RED)DELETED"

fclean: clean
	@make clean -C lib/$(MLX_DIR)
	@make clean -C lib/$(LIBFT_DIR)
	@echo "$(YELLOW)$(NAME) $(RED)DELETED"

re: fclean all

.PHONY: all clean fclean re