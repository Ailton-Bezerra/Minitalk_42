SRCS	= client.c server.c
SRCS_BONUS = client_bonus.c server_bonus.c
OBJS	:= $(SRCS:%.c=%.o)
OBJS_BONUS := $(SRCS_BONUS:%.c=%.o)
NAME	= minitalk
CC		= cc
RM		= rm -f
CFLAGS 	= -Wall -Wextra -Werror

BLUE = \033[1;34m
GREEN=\033[0;32m
END=\033[0m

all: ${NAME}

%.o: %.c
	@${CC} ${CFLAGS} -Ilibft -Iprintf -c $? -o $@

${NAME}: server client

server: server.o
	@echo "$(BLUE)Compiling server...$(END)\n"
	@make -C libft --no-print-directory
	@make -C printf --no-print-directory
	@${CC} ${CFLAGS} $? -Llibft -lft -Lprintf -lftprintf -o server

client: client.o
	@echo "$(BLUE)Compiling client...$(END)\n"
	@${CC} ${CFLAGS} $? -Llibft -lft -Lprintf -lftprintf -o client
	@echo "$(GREEN) server and client are ready to use!$(END)"

bonus: serverb clientb

serverb: server_bonus.o
	@echo "$(BLUE)Compiling server_bonus...$(END)\n"
	@make -C libft --no-print-directory
	@make -C printf --no-print-directory
	@${CC} ${CFLAGS} $? -Llibft -lft -Lprintf -lftprintf -o server_bonus

clientb: client_bonus.o
	@echo "$(BLUE)Compiling client_bonus...$(END)\n"
	@${CC} ${CFLAGS} $? -Llibft -lft -Lprintf -lftprintf -o client_bonus
	@echo "$(GREEN) server_bonus and client_bonus are ready to use!$(END)\n"

clean:
	@echo "$(GREEN)cleaning...$(END)"
	@make clean -C ./libft --no-print-directory
	@make clean -C ./printf --no-print-directory
	@${RM} ${OBJS} ${OBJS_BONUS}

fclean: clean
	@${RM} server client client_bonus server_bonus
	@make -C ./printf --no-print-directory fclean
	@make -C ./libft --no-print-directory fclean
	@echo "$(GREEN) all cleaned!$(END)"

re: fclean all

.PHONY: all bonus clean client clientb fclean server serverb