.PHONY: all clean fclean re
NAME	= libftprintf.a

PATH_INCS 	= includes
PATH_SRCS 	= srcs
PATH_OBJS 	= objs
PATH_LIBFT	= libft
LIBFT		= $(addprefix libft/, libft.a)

SRCS_CORE 	= 	$(addprefix core/, ft_printf.c)
SRCS_DISP	=	$(addprefix display/, charf.c intf.c strf.c uhexaminf.c uhexamajf.c uintf.c)
SRCS_UTILS	=	$(addprefix utils/, print_formated.c define_struct.c)
SRCS		=	$(addprefix $(PATH_SRCS)/, $(SRCS_DISP) $(SRCS_UTILS) $(SRCS_CORE))
OBJS		=	$(addprefix $(PATH_OBJS)/, $(notdir $(SRCS:.c=.o)))
INCS		=	$(PATH_INCS)/ft_printf.h $(PATH_LIBFT)/libft.h

GCC			= gcc
COMP_INC	= -I$(PATH_LIBFT) -I$(PATH_INCS)
RM			= rm -rf

CFLAGS		= -Wall -Wextra -Werror

all:	 $(PATH_OBJS) $(NAME)

$(NAME):	$(OBJS) $(INCS) $(LIBFT)
			mv libft/libft.a libftprintf.a
			ar rcs $(NAME) $(OBJS)

$(PATH_OBJS)/%.o : $(PATH_SRCS)/*/%.c $(INCS)
				$(GCC) $(CFLAGS) $(COMP_INC) -c $< -o $@

$(PATH_OBJS):
		mkdir -p $(PATH_OBJS)

$(LIBFT):
		$(MAKE) -C $(PATH_LIBFT)

clean:
		$(RM) $(PATH_OBJS)
		$(MAKE) -C $(PATH_LIBFT) clean

fclean:	clean
		$(RM) $(NAME)
		$(MAKE) -C $(PATH_LIBFT) fclean

re:		fclean all