extern "C"
{
#define new tripouille
#include "libft.h"
#undef new
}

#include "sigsegv.hpp"
#include "check.hpp"
#include "leaks.hpp"
#include <string.h>

int iTest = 1;
int main(void)
{
	signal(SIGSEGV, sigsegv);
	title("ft_isprint\t: ")

	/* 1 */ check(!ft_isprint(' ' - 1)); showLeaks();
	/* 2 */ check(ft_isprint(' ')); showLeaks();
	/* 3 */ check(!ft_isprint('~' + 1)); showLeaks();
	/* 4 */ check(ft_isprint('~')); showLeaks();
	int	i = INT_MIN;
	for (; i < INT_MAX && !ft_isprint(i); i++)
		;
	/* 5 */ check(i == 0x20); showLeaks();
	for (; i < INT_MAX && ft_isprint(i); i++)
		;
	/* 6 */ check(i == 0x7f); showLeaks();
	for (; i < INT_MAX && !ft_isprint(i); i++)
		;
	/* 7 */ check(i == INT_MAX); showLeaks();
	write(1, "\n", 1);
	return (0);
}
