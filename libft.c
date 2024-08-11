#include "pushswap.h"

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
    *number *= sign;
    if (*number > INT_MAX && *number < INT_MIN)
        return (NULL);
    return ("Success");
}

int ft_abs(int num)
{
    if (num < 0)
        num *= -1;
    return (num);
}

static int ft_strlen(const char *s)
{
    int len;

    len = 0;
    while (s[len])
        len++;
    return (len);
}

int ft_word_count(const char *s, char sep)
{
    int i;
    int word;

    i = 0;
    word = 0;
    while (s[i])
    {
        if (s[i] != sep && (s[i + 1] == sep || s[i + 1] == '\0'))
            word++;
        i++;
    }
    return (word);
}

static char *ft_get_word(const char *s, int start, int end)
{
    char *word;
    int i;

    i = 0;
    word = (char *)malloc(sizeof(char) * ((end - start + 1) + 1));
    if (!word)
        return (NULL);
    while (start <= end)
        word[i++] = s[start++];
    word[i] = '\0';
    return (word);
}

char **get_array(const char *s, char c, int i, int j)
{
    char **ptr;
    int k;
    ptr = (char **)malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
    if (!ptr)
        return (NULL);
    k = 0;
    while (i <= ft_strlen(s))
    {
        j = i;
        while (s[i] && s[i] != c)
        {
            if (s[i + 1] == c || s[i + 1] == '\0')
                ptr[k++] = ft_get_word(s, j, i);
            i++;
        }
        if (s[i] == '\0')
            break;
        i++;
    }
    ptr[k] = NULL;
    return (ptr);
}

char **ft_split(const char *s, char c)
{
    char **ptr;

    if (!s)
        return (NULL);
    ptr = get_array(s, c, 0, 0);
    return (ptr);
}
