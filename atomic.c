#include "atomic.h"

void *feel_stack(void *stk)
{
	int i;
	
	i = 0;
	while (i < 1000 && push((t_stack_fix *)stk, i))
		i++;
	return (NULL);
}

int main()
{
	t_stack_fix *stk;
	pthread_t t1[T_COUNT];
	int i;

	stk = (t_stack_fix *)calloc(1, sizeof(t_stack_fix));
	if (stk)
	{
		i = 0;
		while (i < T_COUNT)
		{
			pthread_create(&t1[i], NULL, feel_stack, (void *)stk);
			i++;
		}
		i = 0;
		while (i < T_COUNT)
		{
			pthread_join(t1[i], NULL);
			i++;
		}
		printf("stk size = %lu\n", stk->size);
	}
	free(stk);
	return(0);
}