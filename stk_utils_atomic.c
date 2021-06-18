#include "atomic.h"

int atomic_push(struct s_stack_fix *stk, const int value) {
	atomic_size_t max = MAXSIZE;
	if (atomic_compare_exchange_strong(&(stk->size), (size_t *) &max,
		atomic_fetch_add(&stk->size, 1)))
		return(0);
	usleep(1000);
	atomic_store(&stk->data[max], value);
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

//t_stack	*ft_stknew(void *content)
//{
//	t_stack	*new_el;
//
//	new_el = (t_stack *)malloc(sizeof(t_stack));
//	if (new_el)
//	{
//		new_el->content = content;
//		new_el->next = NULL;
//	}
//	return (new_el);
//}
//
//void	ft_stkadd_front(t_stack **stk, t_stack *new_el)
//{
//	if (new_el)
//		new_el->next = *stk;
//	if (stk)
//		*stk = new_el;
//}
//
//void	ft_stkdel_front(t_stack **stk, void (*del)(void *))
//{
//	t_stack *tmp;
//	if (stk && *stk)
//	{
//		del((*stk)->content);
//		tmp = *stk;
//		*stk = (*stk)->next;
//		free(tmp);
//	}
//}
//
//void	*ft_get_content(t_stack **stk)
//{
//	if (stk && *stk)
//		return((*stk)->content);
//	return(NULL);
//}