# Colors #
GREEN				=	\033[0;32m
YELLOW			=	\033[0;33m
RED				=	\033[0;31m
RESET				=	\033[0m

NAME 				= minishell

LIBFT_DIR		=	libs/libft

SRC				=	srcs/main.c
OBJ				=	$(SRC:srcs/%.c=$(OBJ_DIR)/%.o)

INC_DIR			=	inc
BUILD_DIR		=	./build
OBJ_DIR			=	$(BUILD_DIR)/objects
ifeq ($(shell uname),Linux)
	READLINE_DIR	=	/usr/include/readline
else
	READLINE_DIR	=	~/.brew/opt/readline/lib
endif

CC 				= gcc
CFLAGS 			= -Wall -Wextra -Werror 
INCLUDES			= -I$(INC_DIR) -I$(LIBFT_DIR) -I$(READLINE_DIR)

all: $(BUILD_DIR) $(NAME) readline

readline:
	@./libreadline.sh

$(NAME): $(OBJ)
	@make -s -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $(@) $(^) -L$(LIBFT_DIR) -lft -L $(READLINE_DIR) -lreadline
	@echo "$(GREEN)[ Minishell is ready to use! ] $(RESET)"

$(OBJ_DIR)/%.o:	srcs/%.c | $(BUILD_DIR)
	@echo "$(GREEN)[ Creating ${@F} ]$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $(^) -o $(@)

.SILENT = $(OBJ)

$(BUILD_DIR):
		@mkdir -p $(BUILD_DIR)
		@mkdir -p $(OBJ_DIR) $(B_OBJ_DIR)
clean:
	@make clean -s -C $(LIBFT_DIR)
	@rm -rf $(BUILD_DIR)
	@echo "$(YELLOW)[ Objects have been removed! ]$(RESET)"

fclean: clean
	@make fclean -s -C $(LIBFT_DIR)
	@rm -f $(NAME)
	@echo "$(RED)[ Minishell has been removed! ]$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus
