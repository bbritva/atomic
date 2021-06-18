#include "atomic.h"

void *atomic_feel_stack(void *stk)
{
	int i;
	
	i = 0;
	while (i < MAXSIZE && atomic_push((t_stack_fix *)stk, i))
		i++;
	return (NULL);
}

void *feel_stack(void *stk)
{
	int i;
	
	i = 0;
	while (i < MAXSIZE && push((t_stack_fix *)stk, i))
		i++;
	return (NULL);
}

int show_stk(t_stack_fix *stk)
{
	int i;
	
//	i = MAXSIZE - 50;
	i = 0;
	while (i < MAXSIZE)
		printf("%d\n", stk->data[i++]);
	return (0);
}

int main()
{
	t_stack_fix *stk;
	pthread_t t1[THREAD_COUNT];
	int i;

//	stk = (t_stack_fix *)calloc(1, sizeof(t_stack_fix));
//	if (stk)
//	{
//		stk->size = 0;
//		pthread_create(&t1[0], NULL, feel_stack, (void *)stk);
//		pthread_join(t1[0], NULL);
//		printf("stk size = %lu\n", stk->size);
//	}
//	free(stk);
//	stk = NULL;
	
	stk = (t_stack_fix *)calloc(1, sizeof(t_stack_fix));
	if (stk)
	{
		stk->size = 0;
		i = 0;
		while (i < THREAD_COUNT)
		{
			pthread_create(&t1[i], NULL, feel_stack, (void *)stk);
			i++;
		}
		i = 0;
		while (i < THREAD_COUNT)
		{
			pthread_join(t1[i], NULL);
			i++;
		}
		printf("stk size = %lu\n", stk->size);
	}
//	show_stk(stk);
	free(stk);
	stk = NULL;

	stk = (t_stack_fix *)calloc(1, sizeof(t_stack_fix));
	if (stk)
	{
		stk->size = 0;
		i = 0;
		while (i < THREAD_COUNT)
		{
			pthread_create(&t1[i], NULL, atomic_feel_stack, (void *)stk);
			i++;
		}
		i = 0;
		while (i < THREAD_COUNT)
		{
			pthread_join(t1[i], NULL);
			i++;
		}
		printf("atomic stk size = %lu\n", stk->size);
	}
	show_stk(stk);
	free(stk);
	stk = NULL;
	return(0);
}