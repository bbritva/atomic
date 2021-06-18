#include "atomic.h"
//
//int atomic_push(struct s_stack_fix *stk, const int value) {
//	size_t max = MAXSIZE;
//	if (atomic_compare_exchange_strong(&(stk->size), &max,
//		atomic_fetch_add(&stk->size, 1)))
//		return(0);
//	usleep(1000);
//	if (max < 1000)
//		atomic_store(&stk->data[max], value);
//	else
//		return (0);
//	return (1);
//}


int atomic_push(struct s_stack_fix *stk, const int value) {
	size_t curr;
	
	curr = atomic_fetch_add(&stk->size, 1);
	usleep(1000);
	if (curr < 1000)
		stk->data[curr] = value;
//		atomic_store(&stk->data[curr], value);
	else
	{
		atomic_fetch_sub(&stk->size, 1);
		return (0);
	}
	return (1);
}

int atomic_pop(struct s_stack_fix *stk, atomic_int *value) {
	atomic_size_t min = 0;
	if (atomic_compare_exchange_strong(&(stk->size), (size_t *) &min,
									   atomic_fetch_sub(&stk->size, 1)))
		return(0);
	usleep(1000);
	*value = atomic_load(&stk->data[stk->size]);
	return (1);
}

int atomic_peek(struct s_stack_fix *stk, atomic_int *value) {
	if (stk->size <= 0) {
		return(0);
	}
	*value = stk->data[stk->size - 1];
	return (1);
}
