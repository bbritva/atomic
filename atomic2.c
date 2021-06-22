#include "atomic.h"

void *atomic_fill_stack(void *stk)
{
	int i;
	
	i = 0;
	while (i < MAXSIZE && atomic_push2((t_stack_ptr *)stk, i))
		i++;
	return (NULL);
}

void *atomic_empty_stack(void *stk)
{
	int			i;
	atomic_int	value;
	
	i = 0;
	while (i < MAXSIZE && atomic_pop2((t_stack_ptr *)stk, &value))
		i++;
	return (NULL);
}

void *fill_stack(void *stk)
{
	int i;
	
	i = 0;
	while (i < MAXSIZE && push2((t_stack_ptr *)stk, i))
		i++;
	return (NULL);
}

int show_stack(t_stack_ptr *stk)
{
	int i;
	
	i = MAXSIZE - 5;
	while (i < MAXSIZE + 5)
	{
		if (stk->data[i])
			printf("stk[%d] = %d\n", i, *stk->data[i]);
		else
			printf("stk[%d] = (NULL)\n", i);
		i++;
	}
	return (0);
}

int fill_zero(t_stack_ptr	*stk)
{
	int i;

	i = 0;
	while (i < SIZE)
	{
		*stk->data[i] = 0;
	}
	return (0);
}

int main()
{
	t_stack_ptr	*stk;
	pthread_t	t1[THREAD_COUNT];
	int			i;
	atomic_int	value;

	
	/**	
	 * заполняем стек простой функцией
	*/
	stk = (t_stack_ptr *)calloc(1, sizeof(t_stack_ptr));
	if (stk)
	{
		stk->size = 0;
		i = 0;
		while (i < THREAD_COUNT)
		{
			pthread_create(&t1[i], NULL, fill_stack, (void *) stk);
			i++;
		}
		i = 0;
		while (i < THREAD_COUNT)
		{
			pthread_join(t1[i], NULL);
			i++;
		}
		/**
		 * при потоконебезопасной функции размер стека выходит за ограничение и
		 * происходит запись в элементы за максимальным размером
		*/
		printf("stk size = %d\n", stk->size);
		show_stack(stk);
		fill_zero(stk);


	
	/**
	 * заполняем стек с помощью атомиков
	 */
		stk->size = 0;
		i = 0;
		while (i < THREAD_COUNT)
		{
			pthread_create(&t1[i], NULL, atomic_fill_stack, (void *) stk);
			i++;
		}
		i = 0;
		while (i < THREAD_COUNT)
		{
			pthread_join(t1[i], NULL);
			i++;
		}
		/**
		 * при использовании атомиков размер стека не выходит за ограничение и 
		 * запись в элементы за максимальным размером не происходит
		 */
 
		printf("atomic stk size = %d\n", stk->size);
		show_stack(stk);
		/**
		 * смотрим значение наверху стека
		 */
		if (atomic_peek(stk, &value))
			printf("peeked value = %d\n", value);
		else
			printf("nothing to peek\n");

		/**
		 * опустошаем стек с помощью атомиков
		 */
		i = 0;
		while (i < THREAD_COUNT)
		{
			pthread_create(&t1[i], NULL, atomic_empty_stack, (void *) stk);
			i++;
		}
		i = 0;
		while (i < THREAD_COUNT)
		{
			pthread_join(t1[i], NULL);
			i++;
		}
		printf("atomic stk size = %d\n", stk->size);
		/**
		 * смотрим значение наверху стека (стек пуст - смотреть нечего)
		 */ 
		if (atomic_peek(stk, &value))
			printf("peeked value = %d\n", value);
		else
			printf("nothing to peek\n");
		free(stk);
		stk = NULL;
	}
	return(0);
}