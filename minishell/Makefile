# Colors #
GREEN		=	\033[0;32m
YELLOW		=	\033[0;33m
RED			=	\033[0;31m
RESET		=	\033[0m

NAME		=	minishell

INC_DIR		=	inc
LIBFT_DIR	=	libft
BUILD_DIR	=	build
SRC_DIR		=	srcs
OBJ_DIR		=	$(BUILD_DIR)/objects

SRC		=	$(SRC_DIR)/pipes.c \
				$(SRC_DIR)/unset.c \
				$(SRC_DIR)/export.c \
				$(SRC_DIR)/env.c \
				$(SRC_DIR)/expand_var.c \
				$(SRC_DIR)/echo.c\
				$(SRC_DIR)/cd.c		\
				$(SRC_DIR)/parser_quotes.c \
				$(SRC_DIR)/parser_lines.c \
				$(SRC_DIR)/parser_tokens.c \
				$(SRC_DIR)/prompt_ft.c \
				$(SRC_DIR)/p.c \
				$(SRC_DIR)/cmd.c \
				$(SRC_DIR)/free_parser.c \
				$(SRC_DIR)/declare_structs.c \
				#$(SRC_DIR)/prompt.c		\
				$(SRC_DIR)/free_clean.c

OBJ			=	$(patsubst %.c, %.o, $(subst $(SRC_DIR), $(OBJ_DIR), $(SRC)))

ifeq ($(shell uname), Linux)
	READLINE_DIR	=	/usr/include/readline
else
	READLINE_DIR	=	~/.brew/opt/readline/lib
endif

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -fsanitize=address -g
INCLUDES	=	-I$(INC_DIR) -I$(LIBFT_DIR) -I$(READLINE_DIR)
LINKS		=	-L$(LIBFT_DIR) -lft -L$(READLINE_DIR) -lreadline

.SILENT		=	$(OBJ)

all: mklibft $(BUILD_DIR) $(NAME)

readline:
	@../libreadline.sh

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(^) -o $(@) $(LINKS)
	@echo "$(GREEN)[ Minishell is ready to use! ] $(RESET)"

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c | $(BUILD_DIR)
	@echo "$(GREEN)[ Creating $(notdir $@) ]$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $(^) -o $(@)

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(OBJ_DIR)

mklibft:
	@make -s -C $(LIBFT_DIR)

clean:
	@make clean -s -C $(LIBFT_DIR)
	@rm -rf $(BUILD_DIR)
	@echo "$(YELLOW)[ Objects have been removed! ]$(RESET)"

fclean: clean
	@make fclean -s -C $(LIBFT_DIR)
	@rm -f $(NAME)
	@echo "$(RED)[ Minishell has been removed! ]$(RESET)"

re: fclean all

e: re
	@./minishell

.PHONY: all clean fclean re bonus
