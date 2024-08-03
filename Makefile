NAME = pushswap.a

SRCS = instruct.c instruct_utils.c stack_utils.c libft.c sorting_utils.c 

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o:%.c
	cc $(CFLAGS) -c $< -o $@

clean: 
	rm -rf $(OBJS)

fclean: 
	rm -rf $(OBJS)
	rm -rf $(NAME)

re: fclean all