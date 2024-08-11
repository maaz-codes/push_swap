NAME = pushswap.a

SRCS = instruct.c instruct_utils.c stack_utils.c sorting_utils.c \
		ft_split.c other_functions.c \
		push_cheapest_.c push_cheapest_utils.c \ 

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