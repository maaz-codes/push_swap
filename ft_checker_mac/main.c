#include "checker.h"

char **get_next_line(int fd, char **instructs);

char *perform_instruct(char *instruct, stack **a, stack **b)
{
    if (instruct == "pa")
        pa(a, b);
    else if (instruct == "pb")
        pb(b, a);
    else if (instruct == "sa")
        sa(a);
    else if (instruct == "sb")
        sb(b);
    else if (instruct == "ra")
        ra(a);
    else if (instruct == "rb")
        rb(b);
    else if (instruct == "rra")
        rra(a);
    else if (instruct == "rrb")
        rrb(b);
    else if (instruct == "rr")
        rr(a, b);
    else if (instruct == "rrr")
        rrr(a, b);
    else if (instruct == "ss")
        ss(a, b);
    else
        return (NULL);
    return ("Success");
}

int main(int argc, char *argv[])
{
    stack *a;
    stack *b;
    char *instruct;
    int fd;

    a = NULL;
    b = NULL;
    fd = open("instructions.txt", O_RDONLY);

    if (!stack_init(&a, argv + 1, argc - 1))
        return (error_msg());

    while (get_next_line(fd, &instruct))
        if(!perform_instruct(instruct, &a, &b))
            return (error_msg());
    
    if (!is_sorted(a, b))
        write (1, "KO\n", 3);
    else
        write (1, "OK\n", 3);
}
