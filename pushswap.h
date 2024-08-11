#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <unistd.h>



typedef struct doubly_list
{
	int					content;
	int					index_to_top;
	struct doubly_list	*next;
}						stack;

// stack_utils
stack					*stack_new(int number);
stack					*last_block(stack *a);
void					stack_add(stack **a, stack *new_block);
int						stack_len(stack *a);
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

// libft
char					**ft_split(const char *s, char c);
int						ft_word_count(const char *s, char sep);
int						ft_abs(int num);
char					*ft_atol_modified(char *str, long *number);

// sorting functions
stack					*find_max_block(stack *a);
stack					*find_min_block(stack *a);
void					push_elements_to_b(stack **b, stack **a);
void					tiny_sort(stack **a);
void					final_sort(stack **a);
stack					*target_block(stack *element, stack *s, char stacks);
stack					*cheapest_block(stack *a, stack *b);
int						index_to_top(stack *element, stack *s);
int						push_cost(stack *a, stack *b, stack *element, stack *target);
void					sorting(stack **a, stack **b);
int						is_sorted(stack *a);

// pushing cheapest element to top
void					push_cheapest_element(stack **a, stack **b);
void					elements_to_top(stack *cheapest, stack *target, stack **a, stack **b);
void					rotate_ab(stack **a, stack **b, stack *cheapest, stack *target);
void					reverse_rotate_ab(stack **a, stack **b, stack *cheapest, stack *target);
void					rotate_a(stack **a, stack *target);
void					reverse_rotate_a(stack **a, stack *target);
void					rotate_b(stack **b, stack *cheapest);
void 					reverse_rotate_b(stack **b, stack *cheapest);

// Errors
char					*repetition_error(stack **a, long number);
int						error_msg();

// to remove
void					print_stack(stack *a);
void					del_block(stack *a);
void					stack_clear(stack **a);

#endif