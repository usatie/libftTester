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
	title("ft_isalnum\t: ")

	/* 1 */ check(!ft_isalnum('a' - 1)); showLeaks();
	/* 2 */ check(ft_isalnum('a')); showLeaks();
	/* 3 */ check(!ft_isalnum('z' + 1)); showLeaks();
	/* 4 */ check(ft_isalnum('z')); showLeaks();
	/* 5 */ check(!ft_isalnum('A' - 1)); showLeaks();
	/* 6 */ check(ft_isalnum('A')); showLeaks();
	/* 7 */ check(!ft_isalnum('Z' + 1)); showLeaks();
	/* 8 */ check(ft_isalnum('Z')); showLeaks();
	/* 9 */ check(!ft_isalnum('0' - 1)); showLeaks();
	/* 10 */ check(ft_isalnum('0')); showLeaks();
	/* 11 */ check(!ft_isalnum('9' + 1)); showLeaks();
	/* 12 */ check(ft_isalnum('9')); showLeaks();
	/* 13 */ check(!ft_isalnum(0)); showLeaks();
	/* 14 */ check(!ft_isalnum(128)); showLeaks();
	int i = INT_MIN;
	for (; i < INT_MAX && !ft_isalnum(i); i++)
		;
	/* 15 */ check(i == '0'); showLeaks();
	i = INT_MAX;
	for (; i > INT_MIN && !ft_isalnum(i); i--)
		;
	/* 16 */ check(i == 'z'); showLeaks();
	write(1, "\n", 1);
	return (0);
}
