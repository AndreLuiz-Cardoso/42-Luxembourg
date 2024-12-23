# Nome do executável
NAME = push_swap

# Arquivos fonte
SRC = src/begin.c \
      src/index.c \
      src/init.c \
      src/main.c \
      src/push.c \
      src/simple.c \
      src/radix.c \
      src/reverse.c \
      src/rotate.c \
      src/stack_operations.c \
      src/swap.c \
      utils/ft_freesplit.c \
      utils/ft_atoi.c \
      utils/ft_atol.c \
      utils/ft_putstr_fd.c \
      utils/ft_split.c \
      utils/ft_strlen.c \
      utils/is_nbr.c \
      utils/utils.c

# Objetos correspondentes
OBJS = $(SRC:.c=.o)

# Opções do compilador
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# Comando para remover arquivos
RM = rm -f

# Regra implícita para compilar .c em .o
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Regra para linkar o executável
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "Compilation of $(NAME) complete."

# Regra padrão
all: $(NAME)

# Regra para rodar o valgrind
check: $(NAME)
	valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./$(NAME); true

# Regra para limpar objetos e executáveis
clean:
	@$(RM) $(OBJS)
	@echo "Object files cleaned up."

fclean: clean
	@$(RM) $(NAME)
	@echo "Executable and object files cleaned up."

# Regra para recompilar tudo
re: fclean all

.PHONY: all check clean fclean re

