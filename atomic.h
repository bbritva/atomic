#ifndef ATOMIC_H
# define ATOMIC_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include "stdatomic.h"

typedef volatile struct		s_stack {
	void			*content;
	struct s_stack	*next;
}					t_stack;

t_stack	*ft_stknew(void *content);
void	ft_stkadd_front(t_stack **stk, t_stack *new_el);
void	*ft_get_content(t_stack **stk);



#endif