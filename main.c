#include "libftprintf.h"

int main(void)
{
	int size;

	size = printf("str1 = |%-0*d|\n", 5, 42);
	printf("size1 = %d\n", size);
	size = ft_printf("str2 = |%-0*d|\n", 5, 42);
	printf("size2 = %d\n", size);
	/*size = ft_putnbr_base_rv(-1000, 8, 1);
	printf("\n");
	printf("size = %d\n", size);*/
	return (0);
}