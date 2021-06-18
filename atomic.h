#ifndef ATOMIC_H
# define ATOMIC_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <pthread.h>
# include "stdatomic.h"

# define MAXSIZE 100000
# define SIZE 2 * MAXSIZE
# define THREAD_COUNT 1000
# define SLEEP_TIME 1000

typedef struct		s_stack_fix {
	atomic_int		data[SIZE];
	atomic_size_t	size;
}					t_stack_fix;

int push(struct s_stack_fix *stk, int value);
int pop(struct s_stack_fix *stk, int *value);
int peek(struct s_stack_fix *stk, int *value);

int atomic_push(struct s_stack_fix *stk, int value);
int atomic_pop(struct s_stack_fix *stk, atomic_int *value);
int atomic_peek(struct s_stack_fix *stk, atomic_int *value);

#endif