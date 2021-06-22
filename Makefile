NAME		=	atomic
CCF			=	gcc $(CFLAGS)
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror -g
SRCS		=	atomic.c stk_utils.c stk_utils_atomic.c
SRCS2		=	atomic2.c stk_utils2.c stk_utils_atomic2.c
HDR			=	atomic.h
OBJS		=	$(SRCS:.c=.o)
OBJS2		=	$(SRCS2:.c=.o)


all:		$(NAME)

$(NAME):	$(OBJS) $(HDR)
			@$(CCF) $(OBJS) -lpthread -o $(NAME)

2:			$(OBJS2) $(HDR)
			@$(CCF) $(OBJS2) -lpthread -o $(NAME)

clean:
			@$(RM) $(OBJS)
			@echo objs deleted

fclean:		clean
			@$(RM) $(NAME)
			@echo $(NAME) deleted

re:			fclean all

%.o:		%.c $(HDR)
			@$(CCF) -c $< -o $@
			@echo $@ compilled

.PHONY:		all clean fclean re so bonus norm