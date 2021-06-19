#include "atomic.h"

/**
 * пока один поток спит, другой может изменить стек, и запись произойдет
 * не туда, куда должна была
 */

int push(struct s_stack_fix *stk, const int value)
{
	if (stk->size >= MAXSIZE) {
		return(0);
	}
	usleep(SLEEP_TIME);
	stk->data[stk->size] = value;
	stk->size++;
	return (1);
}

int pop(struct s_stack_fix *stk, int *value)
{
	if (stk->size == 0) {
		return(0);
	}
	stk->size--;
	*value = stk->data[stk->size];
	return (1);
}

int peek(struct s_stack_fix *stk, int *value)
{
	if (stk->size <= 0) {
		return(0);
	}
	*value = stk->data[stk->size - 1];
	return (1);
}
