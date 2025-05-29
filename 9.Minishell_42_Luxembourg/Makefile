NAME = minishell
SRC_DIR = src
OBJ_DIR = .objs

# Usar todos os arquivos .c no diretório sources
SRC = $(wildcard $(SRC_DIR)/*.c)

OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

CC = clang
HEAD = -I./includes
CFLAGS = -Wall -Werror -Wextra -g  -fsanitize=address
LFLAGS = -lreadline
RM = /bin/rm -rf

all: $(NAME)

$(NAME): $(OBJ)
		@$(CC) $(OBJ) $(HEAD) $(CFLAGS) $(LFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(OBJ_DIR)
		@$(CC) $(CFLAGS) $(HEAD) -c $< -o $@

clean:
		@$(RM) $(OBJ_DIR)

fclean: clean
		@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
