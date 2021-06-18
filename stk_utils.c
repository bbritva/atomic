#include "atomic.h"

t_stack	*ft_stknew(void *content)
{
	t_stack	*new_el;

	new_el = (t_stack *)malloc(sizeof(t_stack));
	if (new_el)
	{
		new_el->content = content;
		new_el->next = NULL;
	}
	return (new_el);
}

void	ft_stkadd_front(t_stack **stk, t_stack *new_el)
{
	if (new_el)
		new_el->next = *stk;
	if (stk)
		*stk = new_el;
}

void	ft_stkdel_front(t_stack **stk, void (*del)(void *))
{
	t_stack *tmp;
	if (stk && *stk)
	{
		del((*stk)->content);
		tmp = *stk;
		*stk = (*stk)->next;
		free(tmp);
	}
}

void	*ft_get_content(t_stack **stk)
{
	if (stk && *stk)
		return((*stk)->content);
	return(NULL);
}