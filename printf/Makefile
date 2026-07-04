NAME        = libftprintf.a

CC          = cc
CFLAGS      = -Wall -Wextra -Werror
AR          = ar rcs
RM          = rm -f

SRCS        = ft_printf.c \
			ft_putchar_fd_pf.c ft_putstr_fd_pf.c ft_putnbr_fd_pf.c ft_putnbr_uns.c \
			ft_putnbr_hex.c ft_putnbr_mem.c ft_conversion.c

OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re