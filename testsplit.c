#include <unistd.h>
#include <stdlib.h>

void    free_split(char    **split, size_t word)
{
    size_t    i;

    i = 0;
    while (i < word)
        free(*(split + i++));
    free(split);
}

void    ft_strncopy(char *dest, char const *src, size_t n)
{
    size_t    i;

    i = 0;
    while (i < n)
    {
            *(dest + i) = *(src + i);
            ++i;
    }
    *(dest + i) = 0;
}

char    **ft_split(char const *s, char c)
{
    size_t    i;
    size_t    count;
    size_t    word;
    char    **split;

    count = 0;
    i = 0;
    while (*(s + i))
    {
        if (*(s + i) == c && *(s + i - 1) && *(s + i))
            ++count;
        ++i;
    }
    split = (char **)malloc(sizeof(char *) * count + 2);
    if (!split)
        return (NULL);
    word = 0;
    count = 0;
    i = 0;
    while (*(s + ++i - 1))
        if (*(s + i) == c || *(s + i) == 0)
        {
            if (count == 0)
            *(split + word) = (char *)malloc(sizeof(char) * i - count);
            else
            *(split + word) = (char *)malloc(sizeof(char) * i - count + 1);
            if (!*(split + word))
            {
                free_split(split, word - 1);
                return (NULL);
            }
            if (count == 0)
            ft_strncopy(*(split + word++), s + count, i - count - 1);
            else
            ft_strncopy(*(split + word++), s + count, i - count);
            count = i + 1;
        }
    *(split + word) = 0;
    return (split);
}

void    putstr(char *str)
{
    int    i;

    i = 0;
    while (*(str + i))
    {
        write(1, str + i, 1);
        ++i;
    }
}

int main(void)
{
    char    **split;

    split = ft_split("Ciao, come stai?", ' ');
    putstr("_SPLIT\nft_split(\"Ciao, come stai?\", \' \') =\n");
    putstr(*split);
    putstr("\n");
    putstr(*(split + 1));
    putstr("\n");
    putstr(*(split + 2));
    putstr("\n\n");
    return (0);
}
