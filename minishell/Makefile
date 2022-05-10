# Colors #
GREEN				=	\033[0;32m
YELLOW			=	\033[0;33m
RED				=	\033[0;31m
RESET				=	\033[0m

NAME 				= minishell

LIBFT_DIR		=	libs/libft
READLINE_DIR	=	libs/readline

SRC				=	srcs/main.c
OBJ				=	$(SRC:srcs/%.c=$(OBJ_DIR)/%.o)

INC_DIR			=	inc
BUILD_DIR		=	./build
BIN_DIR			=	$(BUILD_DIR)/bin
OBJ_DIR			=	$(BUILD_DIR)/objects
BIN				=	$(BIN_DIR)/$(NAME)

CC 				= gcc
CFLAGS 			= -Wall -Wextra -Werror -fsanitize=address -I$(INC_DIR) -I$(LIBFT_DIR) -I$(READLINE_DIR)

all: $(NAME)

$(NAME): $(BUILD_DIR) $(BIN)

$(BIN): $(OBJ) | $(BIN_DIR)
	@make -s -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) -o $(@) $(^) -L$(LIBFT_DIR) -lft -L $(READLINE_DIR) -lreadline
	@echo "$(GREEN)[ Minishell is ready to use ! ] $(RESET)"

$(OBJ_DIR)/%.o:	srcs/%.c | $(BUILD_DIR)
	@echo "$(GREEN)[ Creating ${@F} ]$(RESET)"
	@$(CC) $(CFLAGS) -c $(^) -o $(@)

.SILENT = $(OBJ)

$(BUILD_DIR):
		@mkdir -p $(BUILD_DIR)
		@mkdir -p $(OBJ_DIR) $(B_OBJ_DIR) $(BIN_DIR)
clean:
	@make clean -s -C $(LIBFT_DIR)
	@rm -rf $(OBJ_DIR)/*.o
	@#echo "$(YELLOW)[    Objects have been removed!  ]$(RESET)"

fclean: clean
	@make fclean -s -C $(LIBFT_DIR)
	@rm -rf build
	@echo "$(RED)[ Minishell has been removed ! ]$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus
