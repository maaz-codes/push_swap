#include "../pushswap.h"

char *ft_atol_modified(char *str, long *number)
{
    int i;
    int sign;

    i = 0;
    sign = 1;
    *number = 0;
    while (str[i] != '\0' && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
        i++;
    if (str[i] == '+' || str[i] == '-')
        if (str[i++] == '-')
            sign = -1;
    while (str[i] != '\0')
    {
        if (str[i] >= '0' && str[i] <= '9')
            *number = (*number * 10) + (str[i] - '0');
        else
            return (NULL);
        i++;
    }
    if (*number > INT_MAX)
        return (NULL);
    *number *= sign;
    return ("Success");
}
