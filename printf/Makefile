NAME = libftprintf.a

SRC = ft_printf.c ft_check.c ft_printf_utils_cspxX.c ft_printf_utils_diu.c

OBJ = ${SRC:.c=.o}

FLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJ}
	@ar rcs ${NAME} ${OBJ}

%.o: %.c
	@cc ${FLAGS} -c $< -o $@

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf *.a

re: fclean all

.PHONY: all clean fclean re
