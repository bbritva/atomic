#include "atomic.h"

/**
 * пока один поток спит, другой может изменить стек, и запись произойдет
 * не туда, куда должна была
 */

int push2(t_stack_ptr *stk, const int value)
{
	atomic_int	*ptr;

	if (stk->size >= MAXSIZE) {
		return(0);
	}
	usleep(SLEEP_TIME);
	ptr = (atomic_int *)calloc(1, sizeof(atomic_int));
	if (ptr)
	{
		*ptr = value;
		stk->data[stk->size] = ptr;
		stk->size++;
		return (1);
	}
	return (0);
}

int pop2(t_stack_ptr *stk, int *value)
{
	if (stk->size == 0) {
		return(0);
	}
	stk->size--;
	*value = *stk->data[stk->size];
	return (1);
}

int peek2(t_stack_ptr *stk, int *value)
{
	if (stk->size <= 0) {
		return(0);
	}
	*value = *stk->data[stk->size - 1];
	return (1);
}
