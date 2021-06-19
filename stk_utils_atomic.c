#include "atomic.h"

/**
 * Здесь с помощью атомарной функции мы увеличили размер стека на единицу,
 * и она вернула индекс элемента, в который должны положить новое значение.
 * Если размер не вышел за пределы, кладем значение, если вышел - уменьшаем 
 * на единицу размер и возвращаем 0
 */

int atomic_push(struct s_stack_fix *stk, atomic_int value)
{
	atomic_int curr;

	curr = atomic_fetch_add(&stk->size, 1);
	usleep(SLEEP_TIME);
	if (curr < MAXSIZE)
		stk->data[curr] = value;
	else
	{
		atomic_fetch_sub(&stk->size, 1);
		return (0);
	}
	return (1);
}

/**
 * Здесь с помощью атомарной функции мы уменьшили размер стека на единицу,
 * и она вернула индекс элемента, следующего за тем, из которого мы должны 
 * брать значение.
 * Если размер не вышел за пределы, записываем значение в переданный адрес, 
 * если вышел - увеличиваем на единицу и возвращаем 0
 */

int atomic_pop(struct s_stack_fix *stk, atomic_int *value)
{
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

/**
 * Здесь с помощью атомарной функции мы получаем индекс элемента, следующего за 
 * тем, из которого мы должны брать значение.
 * Если индекс не вышел за пределы, записываем значение в переданный адрес, 
 * если вышел - возвращаем 0
 */

int atomic_peek(struct s_stack_fix *stk, atomic_int *value)
{
	atomic_int curr;

	curr = atomic_load(&stk->size);
	if (curr > 0 && curr <= MAXSIZE )
		*value = stk->data[curr - 1];
	else
		return (0);
	return (1);
}
