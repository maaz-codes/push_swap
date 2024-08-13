NAME = pushswap.a

# NAME_BONUS = checker.a

# NAME_GNL = gnl.a 


SRCS =	instructs/instructs_for_a.c instructs/instructs_for_b.c instructs/instructs_for_both.c instructs/instruct_utils.c \
		libft/ft_abs.c libft/ft_atol_modified.c libft/ft_split.c libft/ft_strjoin.c libft/ft_strdup.c libft/ft_strlen.c libft/ft_memcmp.c \
		push_cheapest/push_cheapest.c push_cheapest/push_cheapest_utils.c \
		sorting/block_utils.c sorting/sorting_utils.c sorting/sorting.c sorting/target_block.c \
		errors.c stack_utils.c \
		parsing.c \
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
		errors_bonus.c instructs/instructs_for_a_bonus.c instructs/instructs_for_b_bonus.c instructs/instructs_for_both_bonus.c \
		# main.c \

# SRCS_BONUS = \

# SRCS_GNL = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \


OBJS = $(SRCS:.c=.o)

# OBJS_BONUS = \

# OBJS_GNL = $(SRCS_GNL:.c=.o)


CFLAGS = -Wall -Wextra -Werror


all: $(NAME)

# bonus : $(NAME_BONUS) $(NAME_GNL)


$(NAME): $(OBJS)
	ar -r $(NAME) $(OBJS)

# $(NAME_BONUS): $(OBJS_BONUS)
# 	ar -r $(NAME_BONUS) $(OBJS_BONUS)

# $(NAME_GNL): $(OBJS_GNL)
# 	ar -r $(NAME_GNL) $(OBJS_GNL)


%.o:%.c
	cc -c $(CFLAGS) $< -o $@

clean: 
	rm -rf $(OBJS) 
# $(OBJS_BONUS) $(OBJS_GNL)

fclean: 
	rm -rf $(OBJS) 
# $(OBJS_BONUS) $(OBJS_GNL)
	rm -rf $(NAME) 
# $(NAME_BONUS) $(NAME_GNL)

re: fclean all