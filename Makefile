.PHONY: all clean fclean re init

NAME	= libprintf.a

PATH_INCS 	= includes
PATH_SRCS 	= srcs
PATH_OBJS 	= objs
PATH_LIBFT	= ../libft	


CORE 		= 	ft_printf.c
SRCS_DISP	=	$(addprefix display/, charf.c intf.c strf.c uhexaminf.c uhexamajf.c uintf.c)
SRCS_UTILS	=	$(addprefix utils/, print_formated.c define_struct.c)
SRCS		=	$(addprefix $(PATH_SRCS)/, $(SRCS_DISP) $(SRCS_UTILS) $(CORE))
OBJS		=	$(addprefix $(PATH_OBJS)/, $(notdir $(SRCS:.c=.o)))
INCS		=	$(PATH_INCS)/ft_printf.h

GCC			= gcc
COMP_INC	= -I$(PATH_LIBFT) -I$(PATH_INCS)
RM			= rm -rf

CFLAGS		= -Wall -Wextra -Werror

$(NAME):	$(OBJS) $(INCS)
			ar rcs $(NAME) $(OBJS)

$(PATH_OBJS)/%.o : $(PATH_SRCS)/*/%.c $(INCS)
				$(GCC) $(CFLAGS) $(COMP_INC) -c $< -o

all:	init $(NAME)

init: 	$(shell mkdir -p $(PATH_OBJS))
		make -C $(PATH_LIBFT)

clean:
		$(RM) $(PATH_OBJS)
		make -C $(PATH_LIBFT) clean

fclean:	clean
		$(RM) $(NAME)
		make -C $(PATH_LIBFT) fclean

re:		fclean all