#ifndef ATOMIC_H
# define ATOMIC_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <pthread.h>
# include "stdatomic.h"

# define MAXSIZE 1000
# define SIZE 2 * MAXSIZE
# define T_COUNT 3

typedef struct		s_stack_fix {
	atomic_int		data[SIZE];
	atomic_size_t	size;
}					t_stack_fix;

int push(struct s_stack_fix *stk, int value);
int pop(struct s_stack_fix *stk, int *value);
int peek(struct s_stack_fix *stk, int *value);

int atomic_push(struct s_stack_fix *stk, int value);
int atomic_pop(struct s_stack_fix *stk, int *value);
int atomic_peek(struct s_stack_fix *stk, int *value);


typedef struct		s_stack {
	void			*content;
	struct s_stack	*next;
}					t_stack;



t_stack	*ft_stknew(void *content);
void	ft_stkadd_front(t_stack **stk, t_stack *new_el);
void	*ft_get_content(t_stack **stk);




#endif