#include "libftprintf.h"

int main(void)
{
	printf("%-+*d\n", 10, 420);
	ft_printf("%+-*d", 10, 420);
	return (0);
}