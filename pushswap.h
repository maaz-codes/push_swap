#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct doubly_list
{
	int					content;
	struct doubly_list	*prev;
	struct doubly_list	*next;
}						stack;

stack					*stack_new(int number);
stack					*last_block(stack *a);
void					stack_add(stack **a, stack *new_block);
int						stack_len(stack *a);
stack					*stack_init(int *numbers, int len);

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

// libft
char					**ft_split(const char *s, char c);
int						ft_word_count(const char *s, char sep);

// sorting functions
int						find_max(stack *a);
int						find_min(stack *a);
void					push_elements_to_b(stack **b, stack **a);
void					tiny_sort(stack **a);
int						target_element(int element, stack *a);
void					final_sort(stack **a);

// to remove
void					print_stack(stack *a);
void					del_block(stack *a);
void					stack_clear(stack **a);

#endif