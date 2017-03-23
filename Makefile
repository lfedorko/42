NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

OBJECTS = to_struct.o\
		ft_printf.o\
		convert_size.o\
		handle_output.o\
		handle_string.o\
		itoa_base.o\
		add_functions1.o\
		add_functions2.o\
		fill_array.o\
		handle_widechar.o\
		handle_bonus.o\
		handle_widestring.o\
		handle_char.o


LIB = ./libft/

LIB_INC = ./libft/libft.h

all: $(NAME)

$(NAME): $(OBJECTS) $(LIB)libft.a
	ar rc $(NAME) $(OBJECTS) $(LIB)*.o
	ranlib $(NAME)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@ -I $(LIB) -I $(LIB_INC) -I ft_printf.h

$(LIB)libft.a:
	make -C $(LIB)

clean:
	make clean -C $(LIB)
	rm -f $(OBJECTS)

fclean: clean
	make fclean -C $(LIB)
	rm -f $(NAME)

re: fclean all