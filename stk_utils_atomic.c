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
	atomic_int curr;
	
	curr = atomic_fetch_add(&stk->size, 1);
	usleep(SLEEP_TIME);
	if (curr < MAXSIZE)
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
	atomic_int curr;

	curr = atomic_fetch_sub(&stk->size, 1);
	usleep(SLEEP_TIME);
	if (curr > 0 && curr <= MAXSIZE )
		*value = stk->data[curr - 1];
	else
	{
		atomic_fetch_add(&stk->size, 1);
		return (0);
	}
	return (1);
}

int atomic_peek(struct s_stack_fix *stk, atomic_int *value) {
	atomic_int curr;

	curr = atomic_load(&stk->size);
	if (curr > 0 && curr <= MAXSIZE )
		*value = stk->data[curr - 1];
	else
		return (0);
	return (1);
}
