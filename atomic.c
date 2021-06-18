#include "atomic.h"

int	feel_stack(t_stack **stk)
{
	atomic_int aInt;

	(void)stk;
	aInt = 5;
	atomic_load(&aInt);
	return(0);
}

int main()
{
	t_stack **stk;

	stk = (t_stack **)calloc(1, sizeof(t_stack *));
	if (stk)
	{
		feel_stack(stk);
	}
	free(stk);
	printf("hello\n");
	return(0);
}