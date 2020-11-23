#include "libftprintf.h"
#include <stdio.h>

int main(void)
{
	int size;
	int a = 123;
	int *b;

	b = &a;
	size = printf("s1 = |%.4u|\n", 42);
	printf("size1 = %d\n", size);
	size = ft_printf("s1 = |%.4u|\n", 42);
	printf("size2 = %d\n", size);
	return (0);
}