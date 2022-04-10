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
	title("ft_memchr\t: ")
	
	char s[] = {0, 1, 2 ,3 ,4 ,5};
	/* 1 */ check(ft_memchr(s, 0, 0) == NULL); showLeaks();
	/* 2 */ check(ft_memchr(s, 0, 1) == s); showLeaks();
	/* 3 */ check(ft_memchr(s, 2, 3) == s + 2); showLeaks();
	/* 4 */ check(ft_memchr(s, 6, 6) == NULL); showLeaks();
	/* 5 */ check(ft_memchr(s, 2 + 256, 3) == s + 2); showLeaks(); //Cast check
	/* 6 */ check(ft_memchr(s, 5, 5) == NULL); showLeaks();
	/* 7 */ check(ft_memchr(s, 5, 6) == s + 5); showLeaks();
	/* 8 */ check(ft_memchr(s, 5, 7) == s + 5); showLeaks();
	/* 9 */ check(ft_memchr(s, 6, 6) == NULL); showLeaks();
	/* 10 */ check(ft_memchr(s, 6, 7) == NULL); showLeaks();
	/* 11 */ check(ft_memchr(s, 6, 8) == NULL); showLeaks();
	write(1, "\n", 1);
	return (0);
}
