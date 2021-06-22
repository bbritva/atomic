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
# define THREAD_COUNT 100
# define SLEEP_TIME 1000

/**
 * размер массива делаю в 2 раза больше, чтоб был доступ к памяти
 * за стеком (для демонстрации ошибки)
 */

typedef struct		s_stack_fix {
	atomic_int		data[SIZE];
	atomic_int 		size;
}					t_stack_fix;

typedef struct			s_stack_ptr {
	atomic_int			*data[SIZE];
	atomic_int 			size;
}						t_stack_ptr;

int push(t_stack_fix *stk, int value);
int pop(t_stack_fix *stk, int *value);
int peek(t_stack_fix *stk, int *value);

int atomic_push(t_stack_fix *stk, atomic_int value);
int atomic_pop(t_stack_fix *stk, atomic_int *value);
int atomic_peek(t_stack_fix *stk, atomic_int *value);

int push2(t_stack_ptr *stk, int value);
int pop2(t_stack_ptr *stk, int *value);
int peek2(t_stack_ptr *stk, int *value);

int atomic_push2(t_stack_ptr *stk, atomic_int value);
int atomic_pop2(t_stack_ptr *stk, atomic_int *value);
int atomic_peek2(t_stack_ptr *stk, atomic_int *value);


#endif