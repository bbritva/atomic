NAME		=	atomic
CCF			=	gcc $(CFLAGS)
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror -g -std=c11
SRCS		=	atomic.c stk_utils.c stk_utils_atomic.c
HDR			=	atomic.h
OBJS		=	$(SRCS:.c=.o)


all:		$(NAME)

$(NAME):	$(OBJS) $(HDR)
			@$(CCF) $(OBJS) -o $(NAME)

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