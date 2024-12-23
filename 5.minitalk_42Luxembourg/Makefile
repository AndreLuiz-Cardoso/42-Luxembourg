# Definições de variáveis
CC = gcc
CFLAGS = -Wall -Wextra -Werror -no-pie
NAME = server client

SRCS = server.c client.c

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

RM = rm -rf

# Compilação de todos os binários
all: $(LIBFT) $(NAME)

bonus: all

# Regras para compilar server e client
server: server.c $(LIBFT)
	$(CC) $(CFLAGS) server.c $(LIBFT) -o server

client: client.c $(LIBFT)
	$(CC) $(CFLAGS) client.c $(LIBFT) -o client

# Construção da libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) all

# Limpeza dos objetos e binários
clean:
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

