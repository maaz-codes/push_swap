NAME = push_swap

SRCS = main.c instruct.c instruct_utils.c stack_utils.c libft.c sorting_utils.c push_cheapest_element.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $(NAME)

# %.o:%.c
# 	 $(CFLAGS)  -c $< -o $@

clean: 
	rm -rf $(OBJS)

fclean: 
	rm -rf $(OBJS)
	rm -rf $(NAME)

re: fclean all