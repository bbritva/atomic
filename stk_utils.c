#include "atomic.h"

int push(struct s_stack_fix *stk, const int value) {
	if (stk->size >= MAXSIZE) {
		return(0);
	}
	usleep(1000);
	stk->data[stk->size] = value;
	stk->size++;
	return (1);
}

int pop(struct s_stack_fix *stk, int *value) {
	if (stk->size == 0) {
		return(0);
	}
	stk->size--;
	*value = stk->data[stk->size];
	return (1);
}

int peek(struct s_stack_fix *stk, int *value) {
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