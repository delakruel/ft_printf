LIBFT	= ./libft/libft.a

NAME	= libftprintf.a

SRCS	=	ft_flags.c ft_init.c ft_isdigit.c ft_printf.c \
				ft_putstr.c \
				ft_write_char.c ft_write_string.c \
				ft_write_width.c ft_write_pointer.c \
				ft_write_integer.c ft_write_unsigned.c \
				ft_write_hex.c ft_write_percent.c
CC = gcc

FLAGS = -c -Wall -Werror -Wextra

OBJS = $(SRCS:.c=.o)

%.o: %.c ft_printf.h
	$(CC) $(FLAGS) $< -o $@
	
$(NAME):	$(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(FLAGS) ft_printf.h $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all:	$(NAME)

clean:
	$(MAKE) clean -C ./libft
	rm -rf $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re