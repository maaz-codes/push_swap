NAME = pushswap.a

SRCS =	instructs/instructs_for_a.c instructs/instructs_for_b.c instructs/instructs_for_both.c instructs/instruct_utils.c \
		libft/ft_abs.c libft/ft_atol_modified.c libft/ft_split.c libft/ft_strjoin.c libft/ft_strdup.c libft/ft_strlen.c libft/ft_strtrim.c\
		push_cheapest/push_cheapest.c push_cheapest/push_cheapest_utils.c \
		sorting/block_utils.c sorting/sorting_utils.c sorting/sorting.c sorting/target_block.c \
		errors.c stack_utils.c \
		# main.c \

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar -r $(NAME) $(OBJS)

%.o:%.c
	cc -c $< -o $@

clean: 
	rm -rf $(OBJS)

fclean: 
	rm -rf $(OBJS)
	rm -rf $(NAME)

re: fclean all