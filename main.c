#include "libftprintf.h"
#include <stdio.h>

int main(void)
{
	int size;
	int a = 123;
	int *b;

	b = &a;
	size = printf("str1 = |%.*u\n", -1, 0);
	printf("size1 = %d\n", size);
	size = ft_printf("str2 = |%.*u\n", -1, 0);
	printf("size2 = %d\n", size);
	return (0);
}