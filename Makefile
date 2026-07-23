NAME	= push_swap

# Mapeamento dos arquivos em suas respectivas subpastas
SRCS		= push_swap.c \
			flags_bench/op_parse_flags.c \
			flags_bench/op_print_bench.c \
			rotatio_swap/op_swap.c \
			rotatio_swap/op_rotation.c \
			rotatio_swap/op_reverse_rotation.c \
			sorting_algoritms/op_sorting_simple.c \
			sorting_algoritms/op_sorting_medium.c \
			sorting_algoritms/op_sorting_complex.c \
			sorting_algoritms/op_sorting_adaptive.c \
			start/op_start_push_swap.c \
			utils/op_calc_disorder.c \
			utils/op_helpers.c \
			utils/op_indexing.c \
			utils/op_utils.c \

OBJ_DIR     = obj
INC_DIR     = .

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
	@mkdir -p $(dir $@)
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
