#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int main(void)
{
    // %c: Print a single character
    ft_printf("%%c: %c\n", 'A');

    // %s: Print a string
    ft_printf("%%s: %s\n", "Hello, world!");

    // %p: Print a pointer
    int x = 42;
    ft_printf("%%p: %p\n", &x);

	//%p : Print a pointer - 0x0
	ft_printf("%p %p\n", 0, 0);
	printf("%p %p\n", 0, 0);

    // %d: Print a signed decimal integer
    ft_printf("%%d: %d\n", -123);

    // %i: Print a signed integer (same as %d)
    ft_printf("%%i: %i\n", 456);

    // %u: Print an unsigned decimal integer
    ft_printf("%%u: %u\n", 3000000000U);

    // %x: Print an unsigned int in lowercase hexadecimal
    ft_printf("%%x: %x\n", 305441741);

    // %X: Print an unsigned int in uppercase hexadecimal
    ft_printf("%%X: %X\n", 305441741);

    // %%: Print a percent sign
    ft_printf("%%%%: %%\n");

    return 0;
}