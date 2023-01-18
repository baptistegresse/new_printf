#include "includes/ft_printf.h"
#include <stdio.h>

int main(void)
{
    int i = ft_printf("%-2s", " - ");
    printf("\n%d\n", i);
    int j = printf("%-2s", " - ");
    printf("\n%d\n", j);
    return (0);
}