#include <unistd.h>

int main()
{
    int i;
    char    *str = "bonjour";

    i = 0;
    str = NULL;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
    return (0);
}