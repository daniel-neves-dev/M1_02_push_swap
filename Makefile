NAME        = push_swap
SRCS        = push_swap.c op_swap.c op_rotation.c op_reverse_rotation.c \
			op_helpers.c op_sorting_big.c op_utils.c op_sorting.c op_indexing.c

LIBFT_DIR   = ./libft
PRINTF_DIR  = ./printf
LIBFT       = $(LIBFT_DIR)/libft.a
PRINTF      = $(PRINTF_DIR)/libftprintf.a

CC          = cc
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -f

OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(PRINTF):
	@make -C $(PRINTF_DIR)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

%.o: %.c push_swap.h
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
