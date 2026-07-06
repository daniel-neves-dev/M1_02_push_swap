NAME        = push_swap
SRCS        = push_swap.c op_swap.c op_rotation.c

LIBFT_DIR   = ./libft
PRINTF_DIR  = ./printf
LIBFT       = $(LIBFT_DIR)/libft.a
PRINTF      = $(PRINTF_DIR)/libftprintf.a

CC          = cc
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -f

OBJS        = $(SRCS:.c=.o)

all: $(LIBFT) $(PRINTF) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(PRINTF):
	@make -C $(PRINTF_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

	#DELETAR AO FIM DO PROJETO
	#######################
	gcc *.c -L./libft -L./printf -lft -lftprintf -o push_swap
	./push_swap
	#######################
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(PRINTF_DIR)
	$(RM) $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(PRINTF_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re