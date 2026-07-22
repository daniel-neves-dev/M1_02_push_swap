NAME		= push_swap
SRCS		= \
			push_swap.c op_swap.c op_rotation.c op_reverse_rotation.c \
			op_sorting_simple.c op_sorting_medium.c op_sorting_complex.c \
			op_sorting_adaptive.c op_fill_stack.c \
			op_helpers.c op_utils.c op_indexing.c op_parse_flags.c

OBJ_DIR		= obj
INC_DIR		= .

LIBFT_DIR	= ./libft
PRINTF_DIR	= ./printf
LIBFT		= $(LIBFT_DIR)/libft.a
PRINTF		= $(PRINTF_DIR)/libftprintf.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

OBJS		= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
INCLUDES	= -I $(INC_DIR) -I $(LIBFT_DIR) -I $(PRINTF_DIR)

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(PRINTF):
	@make -C $(PRINTF_DIR)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

$(OBJ_DIR)/%.o: %.c push_swap.h
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(PRINTF_DIR)
	$(RM) -r $(OBJ_DIR)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(PRINTF_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re $(LIBFT) $(PRINTF)
.SILENT:
