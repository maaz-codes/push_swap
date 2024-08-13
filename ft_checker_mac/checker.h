#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct doubly_list
{
	int					content;
	struct doubly_list	*next;
}						stack;

// stack_utils
void					stack_add(stack **a, stack *new_block);
stack 					*last_block(stack *a);
stack 					*stack_new(int number);
char					*stack_init(stack **a, char **strings, int len);

// instruct utils
void					swap(stack **a);
void					push(stack **a, stack **b);
void					rotate(stack **top);
void					reverse_rotate(stack **top);

// instructions
void					sa(stack **a);
void					sb(stack **b);
void					ss(stack **a, stack **b);
void					pa(stack **a, stack **b);
void					pb(stack **b, stack **a);
void					ra(stack **a);
void					rb(stack **b);
void					rr(stack **a, stack **b);
void					rra(stack **a);
void					rrb(stack **b);
void					rrr(stack **a, stack **b);

// sorting
int                     is_sorted(stack *a, stack *b);

// libft
char 					*ft_atol_modified(char *str, long *number);
char					**ft_split(const char *s, char c);
int						ft_word_count(const char *s, char sep);

// errors
char					*repetition_error(stack **a, long number);
int						error_msg();

#endif