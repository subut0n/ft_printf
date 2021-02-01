.PHONY: all clean fclean re bonus

NAME	= ft_printf.a

SRCS		= ft_printf.c \
$(wildcard srcs/*.c) \
$(wildcard libft/*.c)


OBJS		= ${SRCS:.c=.o}

CC			= cc
RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

$(NAME):	${OBJS}
		ar rcs ${NAME} $?

%.o: 	%.c	ft_printf.h
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

bonus: 	${OBJS}
		ar rs ${NAME} ${OBJS}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all